/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "sdb.h"
#include "memory/vaddr.h"

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();
void wp_watch(char *expr,word_t res);
void wp_remove(int no);
void wp_iterate();
void restart_again();
void test_expr(int no);

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}

static int cmd_r(char *args) {
  restart_again();
  return 0;
}

static int cmd_q(char *args) {
  nemu_state.state = NEMU_QUIT;
  return -1;
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

static int cmd_px(char *args){
  bool success;
  int32_t res = expr(args,&success);
  if(!success) {
		printf("invalid expression\n");
  } else {
		printf("%x\n",res);
  }
  return 0;
}

static int cmd_w(char *args){
  if(!args) {
		printf("Usage: w EXPR\n");
		return 0;
  }
  bool success;
  word_t res = expr(args,&success);
  if(!success) {
		printf("invalid expression\n");
  } else {
		wp_watch(args,res);
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

static int cmd_x(char *args) {

  int len;
  vaddr_t addr;
  sscanf(args,"%d %x",&len,&addr);

  int i,j;
  for(i = 0;i<len;){
	  printf(ANSI_FMT("%#010x: ",ANSI_FG_BLUE),addr);
  
	  for(j = 0;i<len&&j<5;j++,i++){
			word_t data = vaddr_read(addr,4);//查看host_read函数定义后返回32位值
			addr += 4;
			printf("%#010x ",data);//查看isa文件里面的init.c对照发现输出正确
  	}
  	puts("");
  }
  return 0;
}


static int cmd_exprtest(char *args){
  char *arg = strtok(NULL," ");
  if(!arg){
		printf("Usage: exprtest n\n");
    return 0;
  }
  int no = strtol(arg,NULL,10); 

  test_expr(no);

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

static int cmd_help(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
  { "p", "Usage: p EXPR, Calcalate the expression",cmd_p},
  { "p/x", "Usage: p/x EXPR, Represent data in hexadecimal",cmd_px},
  { "w", "Usage:w EXPR, Watch for the variation of the result of EXPR,pause at variation point",cmd_w},
  { "d", "Usage:d N. Delete watchpoint ",cmd_d},
  { "info", "Display the info of registers & watchpoints",cmd_info },
  { "si", "Continue the execution in N steps,default 1",cmd_si },
  { "r",  "Run program again",cmd_r },
  { "x",  "Usage: x N EXPR, Scan the memory from EXPR by N bytes",cmd_x},
  { "exprtest", "Usage:exprtest N, creat N tests and difftest", cmd_exprtest},
};

#define NR_CMD ARRLEN(cmd_table)

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

void sdb_set_batch_mode() {
  is_batch_mode = true;
}

void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) { return; }
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}

void test_expr(int no) {
  int32_t EXPR;
  int32_t TEST;
  bool success;
  FILE *fp = NULL;
  char *buf = NULL;
  size_t len = 0;
  ssize_t read ;
  char filepath[128];

  const char *nemu_home = getenv("NEMU_HOME");

  char command[256];
  snprintf(command, sizeof(command),"%s/tools/gen-expr/build/gen-expr %d > input",nemu_home,no);
  printf("Excute command: %s\n",command);
  system(command);

  snprintf(filepath,sizeof(filepath),"%s/input",nemu_home);

  fp = fopen(filepath,"r");
  assert(fp);
 
  int test_count = 0;
  int passed = 0;
  int failed = 0;

  while(fscanf(fp,"%d ",&TEST)==1){
	  read = getline(&buf,&len,fp);
    if(read == -1){
      fprintf(stderr,"Read exprtest failed\n");
    }
    if(read > 0 && buf[read-1] == '\n'){
	    buf[read-1] = '\0';
      read--;
    }

    EXPR = expr(buf,&success);

    if(!success){
      printf("Failed: can not exprtest:%s\n",buf);
      failed ++;
    }
    else if( TEST != EXPR) {
      printf("wrong: expr = %s \nTEST =  %d, EXPR =  %d\n",buf,TEST,EXPR);
      failed ++;
    } else {
//      printf("right: expr = %s \nTEST =  %d, EXPR =  %d\n\n",buf,TEST,EXPR);
      passed ++;
    }

    test_count ++;
  }

  printf("\n===== sum =====\n");
  printf("总计: %d\n",test_count);
  printf("通过: %d\n",passed);
  printf("失败: %d\n",failed);

  fclose(fp);
  free(buf); 
}
