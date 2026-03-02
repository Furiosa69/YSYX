#ifndef __REG_H__
#define __REG_H__

#include "sim/sim.h"
#include "common.h"
#include "utils/difftest.h"
#include "sim/sim.h"

void isa_reg_display();
uint32_t isa_reg_str2val(const char *s ,bool *success);
uint32_t diff_isa_reg_display(CPU_state *ref,CPU_state *dut);

#endif
