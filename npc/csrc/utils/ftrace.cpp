#include "common.h"
#include "main.h"
#include <unistd.h>
#include <fcntl.h> //file
#include <elf.h>   //Elf32_Sym
#include <unistd.h>//read()

Elf32_Sym *symtab = NULL;
Elf32_Shdr *shdrs = NULL;
char *strtab = NULL;
int symtab_size = 0;
extern char* ftrace_elf_file;

void init_ftrace() {
    int fd = open(ftrace_elf_file, O_RDONLY);

    // 读取ELF文件头
    Elf32_Ehdr ehdr;
    ssize_t bytes_read = read(fd, &ehdr, sizeof(ehdr));
		if (bytes_read != sizeof(ehdr)) {
				perror("read ehdr");
				close(fd);
				exit(1);
		}

    // 读取节头表
		shdrs = (Elf32_Shdr *)malloc(ehdr.e_shentsize * ehdr.e_shnum);
    lseek(fd, ehdr.e_shoff, SEEK_SET);
    bytes_read = read(fd, shdrs, ehdr.e_shentsize * ehdr.e_shnum);
		if (bytes_read != ehdr.e_shentsize * ehdr.e_shnum){
				perror("read shdrs");
				free(shdrs);
				close(fd);
				exit(1);
		}

		Elf32_Shdr *shdr_strtab = &shdrs[ehdr.e_shstrndx];
    char *shstrtab = (char *)malloc(shdr_strtab->sh_size);
		lseek(fd, shdr_strtab->sh_offset, SEEK_SET);
    bytes_read = read(fd, shstrtab, shdr_strtab->sh_size);
		if (bytes_read != shdr_strtab->sh_size){
				perror("read shstrtab");
				free(shstrtab);
				free(shdrs);
				close(fd);
				exit(1);
		}

    // 查找符号表和字符串表
    for (int i = 0; i < ehdr.e_shnum; ++i) {
				Elf32_Shdr *shdr = &shdrs[i];
        if (shdr->sh_type == SHT_SYMTAB) {
            symtab = (Elf32_Sym *) malloc(shdr->sh_size);
            lseek(fd, shdr->sh_offset, SEEK_SET);
            bytes_read = read(fd, symtab, shdr->sh_size);
						if (bytes_read != shdr->sh_size){
								perror("read symtab");
								free(symtab);
								free(shstrtab);
								free(shdrs);
								close(fd);
								exit(1);
						}
						symtab_size = shdr->sh_size / sizeof(Elf32_Sym);
        } else if (shdr->sh_type == SHT_STRTAB ) {
						const char *section_name = shstrtab + shdr->sh_name;
						if (strcmp(".strtab",section_name) == 0) {
            	strtab = (char *)malloc(shdr->sh_size);
            	lseek(fd, shdr->sh_offset, SEEK_SET);
            	bytes_read = read(fd, strtab, shdr->sh_size);
						if (bytes_read != shdr->sh_size){
								perror("read strtab");
								free(strtab);
								free(symtab);
								free(shstrtab);
								free(shdrs);
								close(fd);
								exit(1);
						}
				}
        }
    }

    // 释放节头表内存
		free(shstrtab);
    free(shdrs);
    close(fd);

    if (symtab == NULL || strtab == NULL) {
        fprintf(stderr, "Failed to read symbol table or string table.\n");
        exit(1);
    }
}

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

IFONE(CONFIG_FTRACE,
	FILE *ftrace_file = fopen(TRACE_DIR "trace_ftrace.txt", "a");

void print_all_function_names(uint32_t current_pc ,uint32_t target_pc, uint32_t inst) {

		bool call = (GET_OPCODE(inst) == 0x6F) && (GET_RD(inst) == 1);
    bool ret  = (GET_OPCODE(inst) == 0x67) && (GET_RS1(inst) == 1) && (GET_RD(inst) == 0);

    if (ftrace_file == NULL) {
        perror("Error opening ftrace file");
        return;
    }

    const char* target_fname = ftrace_translate(target_pc);
    
    if (last_fname == NULL || strcmp(last_fname, target_fname) != 0) {

        if (call) {
            jal_count++;
            fprintf(ftrace_file, "PC:0x%08x | call[%d] @func:<%s : 0x%08x>\n", current_pc,jal_count,target_fname,target_pc);
        } 

				if (ret) {
            if (jal_count > 0) {
                jal_count--;
            }
            fprintf(ftrace_file, "PC:0x%08x | ret[%d]  @func:<%s : 0x%08x>\n", current_pc,jal_count,target_fname,target_pc);
        } 

        free(last_fname);
        last_fname = strdup(target_fname);
    }
}

void end_ftrace(){
  fclose(ftrace_file);
	free(symtab);
	free(strtab);
	symtab = NULL;
	strtab = NULL;
	symtab_size = 0;
}

)
