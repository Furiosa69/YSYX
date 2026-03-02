#include "utils/reg.h"

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

const char *csrs[] = {
	"mcause", "mtvec", "mepc", "mstatus"
};

void isa_reg_display() {
  int reg_num = ARRLEN(regs);
	int csr_num = ARRLEN(csrs);

  for(int i = 0;i<reg_num;i++) {
    printf("%2d : %8s%#15x%15d\n",i,regs[i],cpu.gpr[i],cpu.gpr[i]);
  }

	for(int i = 0;i<csr_num;i++){
		printf("%2d : %8s%#15x%15d\n",i,csrs[i],cpu.csr[i],cpu.csr[i]);
	}

}

uint32_t isa_reg_str2val(const char *s, bool *success) {
  int reg_num = ARRLEN(regs);
  int i;

  for(i = 0;i<reg_num;i++) {
  int len1 = strlen(s);
  int len2 = strlen(regs[i]);
  if(strncmp( s+len1-2, regs[i]+len2-2,2)== 0){
    return cpu.gpr[i];
  }
  }

  return 0;
}

uint32_t diff_isa_reg_display(CPU_state *ref,CPU_state *dut) {
  int reg_num = ARRLEN(regs);
  int i;

	if(ref->pc != root->top__DOT__ifu_pc){
		printf("ref.pc -> 0x%08x , dut.pc -> 0x%08x\n",ref->pc,dut->pc);
	}

  for(i = 0;i<reg_num;i++) {
		if(ref->gpr[i] != root->top__DOT__gpr_t0__DOT__rf[i]){
    	printf("%2d | ref->%s = 0x%08x, dut->%s = 0x%08x\n",i,regs[i],ref->gpr[i],regs[i],root->top__DOT__gpr_t0__DOT__rf[i]);
		}
	}

  return 0;
}

