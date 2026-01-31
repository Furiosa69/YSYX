#include <common.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

char *ftrace_elf = NULL;
//----------- Init -------------
Elf32_Sym *symtab = NULL;
Elf32_Shdr *shdrs = NULL;
char *strtab = NULL;
int symtab_size = 0;
FILE *file = NULL;

void init_ftrace() {
    const char *nemu_home = getenv("NEMU_HOME");
    char ftrace_file[64];
    snprintf(ftrace_file,sizeof(ftrace_file),"%s/build/ftrace",nemu_home);
    file = fopen(ftrace_file,"a");

    int fd = open(ftrace_elf, O_RDONLY);
    // 读取ELF文件头
    Elf32_Ehdr ehdr;
    read(fd, &ehdr, sizeof(ehdr));
    // 读取节头表
		shdrs = (Elf32_Shdr *)malloc(ehdr.e_shentsize * ehdr.e_shnum);
    lseek(fd, ehdr.e_shoff, SEEK_SET);
    read(fd, shdrs, ehdr.e_shentsize * ehdr.e_shnum);

		Elf32_Shdr *shdr_strtab = &shdrs[ehdr.e_shstrndx];
    char *shstrtab = (char *)malloc(shdr_strtab->sh_size);
		lseek(fd, shdr_strtab->sh_offset, SEEK_SET);
    read(fd, shstrtab, shdr_strtab->sh_size);

    // 查找符号表和字符串表
    for (int i = 0; i < ehdr.e_shnum; ++i) {
				Elf32_Shdr *shdr = &shdrs[i];
        if (shdr->sh_type == SHT_SYMTAB) {
            symtab = (Elf32_Sym *) malloc(shdr->sh_size);
            lseek(fd, shdr->sh_offset, SEEK_SET);
            read(fd, symtab, shdr->sh_size);
						symtab_size = shdr->sh_size / sizeof(Elf32_Sym);
        } else if (shdr->sh_type == SHT_STRTAB ) {
						const char *section_name = shstrtab + shdr->sh_name;
						if (strcmp(".strtab",section_name) == 0) {
            	strtab = (char *)malloc(shdr->sh_size);
            	lseek(fd, shdr->sh_offset, SEEK_SET);
            	read(fd, strtab, shdr->sh_size);
				}
        }
    }

    // 释放节头表内存
		free(shstrtab);
    free(shdrs);
    close(fd);
}

//---------------- Translate -----------------
#ifndef ELF32_ST_TYPE
#define ELF32_ST_TYPE(i) ((i) & 0xf)
#endif
#define FUNC_TYPE STT_FUNC

const char* ftrace_translate(uint32_t addr) {
    for (int i = 0; i < symtab_size; ++i) {
        if (ELF32_ST_TYPE(symtab[i].st_info) == FUNC_TYPE && addr >= symtab[i].st_value && addr < symtab[i].st_value + symtab[i].st_size) {
            // 在字符串表中找到函数名
            return &strtab[symtab[i].st_name];
        }
    }
    return "???";
}

static char* last_fname = NULL;
static int jal_count = 0;

#define OPCODE_MASK  0x7F    
#define RD_MASK      0xF80   
#define RS1_MASK     0xF8000 

#define GET_OPCODE(inst) ((inst) & OPCODE_MASK)
#define GET_RD(inst)     (((inst) & RD_MASK) >> 7)
#define GET_RS1(inst)    (((inst) & RS1_MASK) >> 15)

const char* target_fname = NULL;
void print_all_function_names(uint32_t current_pc ,uint32_t target_pc, uint32_t inst) {

		bool call = (GET_OPCODE(inst) == 0x6F) && (GET_RD(inst) == 1);
    bool ret  = (GET_OPCODE(inst) == 0x67) && (GET_RS1(inst) == 1) && (GET_RD(inst) == 0);

    const char* target_fname = ftrace_translate(target_pc);
    
    if (last_fname == NULL || strcmp(last_fname, target_fname) != 0) {

        if (call) {
            jal_count++;
            fprintf(file, "PC:0x%08x | call[%d] @%s:<0x%08x>\n", current_pc,jal_count,target_fname,target_pc);
        } 

				if (ret) {
            if (jal_count > 0) {
                jal_count--;
            }
            fprintf(file, "PC:0x%08x | retu[%d] @%s:<0x%08x>\n", current_pc,jal_count,target_fname,target_pc);
        } 

        free(last_fname);
        last_fname = strdup(target_fname);
    }
}
//-------------- End ------------------
void end_ftrace(){
	free(symtab);
	free(strtab);
  fclose(file);
	symtab = NULL;
	strtab = NULL;
	symtab_size = 0;
}
