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
#include "local-include/reg.h"

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

void isa_reg_display() {
	int reg_num = ARRLEN(regs);
	int i;

	for(i = 0;i<reg_num ;i++) {
		printf("reg[%2d]: %3s%#12x\n",i,regs[i],cpu.gpr[i]);
	}
}

word_t isa_reg_str2val(const char *s, bool *success) {
  int reg_num = ARRLEN(regs);
  int i;

  int l1 = strlen(s);
  int l2 = strlen("PC");
  if(strncmp(s+l1-2,"PC"+l2-2,2)==0){
    return cpu.pc;
  }

  for(i = 0;i<reg_num ;i++) {
    int len1 = strlen(s);
    int len2 = strlen(regs[i]);
	  if(strncmp( s+len1-2, regs[i]+len2-2,2)== 0){
	  	return cpu.gpr[i];
	  }
  }
  return 0;
}
