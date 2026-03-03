#include <cstdio>
#include <readline/readline.h>
#include <readline/history.h>
#include "utils/difftest.h"
#include "utils/iringbuf.h"
#include <getopt.h>
#include "utils/sdb.h"
#include "utils/reg.h"
#include "mem/memory.h"
#include "sim/sim.h"
#include "main.h"

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();
void wp_watch(char *expr,uint32_t res);
void wp_remove(int no);
void wp_iterate();
extern void difftest_enable();
extern void difftest_disable();

static char *log_file = NULL;
char *diff_so_file = NULL;
static char *img_file = NULL;
int difftest_port = 1234;
char *ftrace_elf_file = NULL;

long load_img() {
  FILE *fp = fopen(img_file, "rb");

  fseek(fp, 0, SEEK_END);
  long file_size = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  if (file_size > MEMORY_SIZE) {
    fprintf(stderr, "Image file too large (%lu > %u)\n", file_size, MEMORY_SIZE);
    fclose(fp);
    return 0;  
  }

  size_t read_size = fread(memory, 1, file_size, fp);
  fclose(fp);

  return file_size;
//  loadFileToMemory(img_file, memory, MEMORY_SIZE);
}

void sdb_set_batch_mode() {
  is_batch_mode = true;
}

int parse_args(int argc, char *argv[]) {
  const struct option table[] = {
		{"batch"    , no_argument      , NULL, 'b'},
    {"log"      , required_argument, NULL, 'l'},
    {"diff"     , required_argument, NULL, 'd'},
    {"port"     , required_argument, NULL, 'p'},
    {"ftrace"   , required_argument, NULL, 'f'},
    {"help"     , no_argument      , NULL, 'h'},
    {0          , 0                , NULL,  0 },
  };
  int o;
  while ( (o = getopt_long(argc, argv, "-bhl:d:p:f:", table, NULL)) != -1) {
    switch (o) {
      case 'b': sdb_set_batch_mode(); break;
      case 'p': sscanf(optarg, "%d", &difftest_port); break;
      case 'l': log_file = optarg; break;
      case 'd': diff_so_file = optarg; break;
      case 'f': ftrace_elf_file = optarg; break;
      case 1: img_file = optarg; return 0;
      default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
        printf("\t-b,--batch              run with batch mode\n");
        printf("\t-l,--log=FILE           output log to FILE\n");
        printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
        printf("\t-p,--port=PORT          run DiffTest with port PORT\n");
        printf("\t-f,--ftrace=ELF_FILE    enable ftrace with ELF_FILE\n");
        printf("\n");
        exit(0);
    }
  }
  return 0;
}

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(npc) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}


static int cmd_q(char *args) {
  npc_state.state = NPC_QUIT;
  return -1;
}

static int cmd_help(char *args);
static int cmd_si(char *args);
static int cmd_info(char *args);
static int cmd_x(char *args);
static int cmd_p(char *args);
static int cmd_d(char *args);
static int cmd_w(char *args);
static int cmd_rst(char *args);
static int cmd_detach(char *args);
static int cmd_attach(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NPC", cmd_q },
  { "si","Continue the execution in N steps,default 1",cmd_si },
  { "info","Display the info of registers & watchpoints",cmd_info },
  { "x","Usage: x N EXPR, Scan the memory from EXPR by N bytes",cmd_x},
  { "p","Usage: p EXPR, Calcalate the expression",cmd_p},
  IFONE(CONFIG_WATCHPOINT,{ "w","Usage:w EXPR, Watch for the variation of the result of EXPR,pause at variation point",cmd_w},
  { "d","Usage:d N. Delete watchpoint ",cmd_d},)
  { "rst","Usage:rst . Restart CPU",cmd_rst},
	{ "detach","Usage:detach. Out of difftest",cmd_detach},
  { "attach","Usage:attach. Into difftest",cmd_attach}

  /* TODO: Add more commands */

};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_detach(char *args){
	char *arg = strtok(NULL, " ");
  if (!arg) {
        printf("Usage: detach\n");
        return 0;
  }
  difftest_disable();
  printf("DIFFTEST Disable\n");
  return 0;
}

static int cmd_attach(char *args){
	char *arg = strtok(NULL, " ");
  if (!arg) {
        printf("Usage: attach\n");
        return 0;
  }
  difftest_enable();
  printf("DIFFTEST Enable\n");
//  ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
  return 0;
}

static int cmd_d(char *args){
  char *arg = strtok(NULL," ");
  if(!arg) {
		printf("Usage: d N\n");
		return 0;
  }
  int no = strtol(arg,NULL,10);
  wp_remove(no);
  return 0;
}

static int cmd_w(char *args){
	if(!args) {
		printf("Usage: w EXPR\n");
		return 0;
	}
	bool success;
	uint32_t res = expr(args,&success);
	if(!success) {
		printf("invalid expression\n");
	} else {
		wp_watch(args,res);
	}
	return 0;
}

static int cmd_p(char *args){
  bool success;
  int32_t res = expr(args,&success);
  if(!success) {
	printf("invalid expression\n");
  } else {
	printf("%d\n",res);
  }
  return 0;
}

static int cmd_si(char *args){
  char *arg = strtok(NULL," ");
  int n;

  if(arg == NULL) {
		n = 1;
  } else {
		n = strtol(arg,NULL,10);
  }
 
  cpu_exec(n);
  return 0;
}

static int cmd_info(char *args){
  char *arg = strtok(NULL," ");

  if(arg == NULL) {
		printf("Usage: info r(registers) or info w(watchpoints)\n");
  } else {
	if(strcmp(arg,"r")==0) {
		isa_reg_display();
	} else if(strcmp(arg,"w")==0) {
		wp_iterate();
	} else {
		printf("Usage: info r(registers) or info w(watchpoints)\n");
	}
  }
 
  return 0;
}

static int cmd_x(char *args) {

  int len;
  uint32_t addr;
  sscanf(args,"%d %x",&len,&addr);

  int i,j;
  for(i = 0;i<len;){
	  printf(ANSI_FMT("%#010x: ",ANSI_FG_BLUE),addr);
  
	  for(j = 0;i<len&&j<5;j++,i++){
		uint32_t data = vaddr_read(addr,4);
		addr += 4;
		printf("%#010x ",data);
  }
  puts("");
  }
  return 0;
}

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

static int cmd_rst(char *args){
	rst_begin();
  return 0;
}


void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) {//退出时返回0
		 return;
	 }

        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}

void init_sdb() {
  init_regex();
  
	IFONE(CONFIG_WATCHPOINT,
  	init_wp_pool();
	)
}

void init_isa(){
	sim_init();
	rst_begin();
}

void init_monitor(int argc,char *argv[]){
	parse_args(argc, argv);

	long img_size = load_img();

	init_isa();

	IFONE(CONFIG_DIFFTEST,
		init_difftest(diff_so_file, img_size, difftest_port);
	)

	IFONE(CONFIG_VGA,
		init_vga();
	)

	init_sdb();

	init_disasm("riscv32-pc-linux-gnu");
}

void engine_start(){
	sdb_mainloop();
}
