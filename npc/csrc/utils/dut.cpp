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
static bool difftest_inited = false;
static int skip_dut_nr_inst = 0;
static long difftest_img_size = 0;
bool difftest_flags = true;

static inline bool difftest_is_active() {
  return difftest_inited && difftest_flags;
}

void difftest_enable(void){
  if (!difftest_inited) {
    printf("DIFFTEST is not initialized yet.\n");
    return;
  }
  difftest_flags = true;
  is_skip_ref = false;
  skip_dut_nr_inst = 0;
  ref_difftest_memcpy(RESET_VECTOR, guest_to_host(RESET_VECTOR), difftest_img_size, DIFFTEST_TO_REF);
  ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
}

void difftest_disable(void){
  difftest_flags = false;
  is_skip_ref = false;
  skip_dut_nr_inst = 0;
}

bool isa_difftest_checkregs(CPU_state *ref_r, uint32_t pc) {
  (void)pc;

  for (int i = 0; i < 32; ++i) {
    if (ref_r->gpr[i] != cpu.gpr[i]){
      return false;
    }
  }

  if (ref_r->pc != cpu.pc) {
    return false;
  }

  return true;
}

void difftest_skip_ref() {
	if(!difftest_is_active()){
    return;
  }
  is_skip_ref = true;
  skip_dut_nr_inst = 0;
}

void difftest_skip_dut(int nr_ref, int nr_dut) {
	if(!difftest_is_active()){
    return;
  }
  skip_dut_nr_inst += nr_dut;

  while (nr_ref -- > 0) {
    ref_difftest_exec(1);
  }
}

void init_difftest(char *ref_so_file, long img_size, int port) {
  Assert(ref_so_file != NULL, "DiffTest reference .so is not specified");

  void *handle;
  handle = dlopen(ref_so_file, RTLD_LAZY);
  Assert(handle != NULL, "Failed to open DiffTest reference '%s': %s", ref_so_file, dlerror());

	ref_difftest_memcpy 		= reinterpret_cast<void (*)(uint32_t, void*, size_t, bool)>(dlsym(handle, "difftest_memcpy"));
  Assert(ref_difftest_memcpy != NULL, "Failed to load symbol difftest_memcpy: %s", dlerror());
	ref_difftest_regcpy 		= reinterpret_cast<void (*)(void*, bool)>(dlsym(handle, "difftest_regcpy"));
  Assert(ref_difftest_regcpy != NULL, "Failed to load symbol difftest_regcpy: %s", dlerror());
	ref_difftest_exec 			= reinterpret_cast<void (*)(uint64_t)>(dlsym(handle, "difftest_exec"));
  Assert(ref_difftest_exec != NULL, "Failed to load symbol difftest_exec: %s", dlerror());
	ref_difftest_raise_intr = reinterpret_cast<void (*)(uint64_t)>(dlsym(handle, "difftest_raise_intr"));
  Assert(ref_difftest_raise_intr != NULL, "Failed to load symbol difftest_raise_intr: %s", dlerror());

	void (*ref_difftest_init)(int) = reinterpret_cast<void (*)(int)>(dlsym(handle, "difftest_init"));
  Assert(ref_difftest_init != NULL, "Failed to load symbol difftest_init: %s", dlerror());

  difftest_img_size = img_size;
  ref_difftest_init(port);
  ref_difftest_memcpy(RESET_VECTOR, guest_to_host(RESET_VECTOR), img_size, DIFFTEST_TO_REF);
  ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
  difftest_inited = true;
  difftest_flags = true;
  is_skip_ref = false;
  skip_dut_nr_inst = 0;
}

static void checkregs(CPU_state *ref, uint32_t pc) {
  if (!isa_difftest_checkregs(ref, pc)) {
    npc_state.state = NPC_ABORT;
    npc_state.halt_pc = pc;
    diff_isa_reg_display(ref,&cpu);
  }
}

void difftest_step(uint32_t pc, uint32_t npc) {
	if(!difftest_is_active()){
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
