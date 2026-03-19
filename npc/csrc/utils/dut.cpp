#include <dlfcn.h>
#include "mem/memory.h"
#include "sim/sim.h"
#include "utils/difftest.h"
#include "utils/reg.h"

void (*ref_difftest_memcpy)(uint32_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;

static bool is_skip_ref = false;
static int skip_dut_nr_inst = 0;
static long difftest_img_size;
bool difftest_flags = true;

void difftest_enable(void){
  difftest_flags = true;
  ref_difftest_memcpy(RESET_VECTOR, guest_to_host(RESET_VECTOR), difftest_img_size, DIFFTEST_TO_REF);
  ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
}

void difftest_disable(void){
  difftest_flags = false;
}

bool isa_difftest_checkregs(CPU_state *ref_r, uint32_t pc) {

  for (int i = 0; i < 32; ++i) {
    if (ref_r->gpr[i] != GPR[i]){
      return false;
    }
  }

  if (ref_r->pc != PC) {
    return false;
  }

  return true;
}

void difftest_skip_ref() {
	if(!difftest_flags){
    return;
  }
  is_skip_ref = true;
  skip_dut_nr_inst = 0;
}

void difftest_skip_dut(int nr_ref, int nr_dut) {
	if(!difftest_flags){
    return;
  }
  skip_dut_nr_inst += nr_dut;

  while (nr_ref -- > 0) {
    ref_difftest_exec(1);
  }
}

void init_difftest(char *ref_so_file, long img_size, int port) {
  void *handle;
  handle = dlopen(ref_so_file, RTLD_LAZY);

	ref_difftest_memcpy 		= reinterpret_cast<void (*)(uint32_t, void*, size_t, bool)>(dlsym(handle, "difftest_memcpy"));
	ref_difftest_regcpy 		= reinterpret_cast<void (*)(void*, bool)>(dlsym(handle, "difftest_regcpy"));
	ref_difftest_exec 			= reinterpret_cast<void (*)(uint64_t)>(dlsym(handle, "difftest_exec"));
	ref_difftest_raise_intr = reinterpret_cast<void (*)(uint64_t)>(dlsym(handle, "difftest_raise_intr"));

	void (*ref_difftest_init)(int) = reinterpret_cast<void (*)(int)>(dlsym(handle, "difftest_init"));

  ref_difftest_init(port);
  ref_difftest_memcpy(0x80000000, guest_to_host(0x80000000), img_size, DIFFTEST_TO_REF);
  ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
}

static void checkregs(CPU_state *ref, uint32_t pc) {
  if (!isa_difftest_checkregs(ref, pc)) {
    npc_state.state = NPC_ABORT;
    npc_state.halt_pc = pc;
    diff_isa_reg_display(ref,&cpu);
  }
}

void difftest_step(uint32_t pc, uint32_t npc) {
	if(!difftest_flags){
    return;
  }
  CPU_state ref_r;

  if (skip_dut_nr_inst > 0) {
    ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);
    if (ref_r.pc == npc) {
      skip_dut_nr_inst = 0;
      checkregs(&ref_r, npc);
      return;
    }
    skip_dut_nr_inst --;
    if (skip_dut_nr_inst == 0)
      printf("can not catch up with ref.pc = 0x%08x at pc = 0x%08x", ref_r.pc, pc);
    return;
  }

  if (is_skip_ref) {
    // to skip the checking of an instruction, just copy the reg state to reference design
    ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
    is_skip_ref = false;
    return;
  }

  ref_difftest_exec(1);
  ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT);

  checkregs(&ref_r, pc);
}
