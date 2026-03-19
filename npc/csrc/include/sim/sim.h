#ifndef __SIM_H__
#define __SIM_H__

#include <verilated.h>
#include <verilated_fst_c.h>
#include <Vysyx_24080018.h>
#include "Vysyx_24080018___024root.h"

#include "mem/memory.h"  

extern VerilatedContext* contextp ;
extern VerilatedFstC* tfp ;
extern TOP_NAME* top;
extern TOP_ROOT* root;

#define  PC      root->ysyx_24080018__DOT__ifu_pc
#define  DNPC  root->ysyx_24080018__DOT__lsu_pc
#define  WBU_VALID root->ysyx_24080018__DOT__lsu_wbu_valid
#define  WBU_READY root->ysyx_24080018__DOT__wbu_lsu_ready
#define  INST   root->ysyx_24080018__DOT__ifu_inst
#define  GPR    root->ysyx_24080018__DOT__wbu__DOT__rf
//#define  CSR_cnt  root->ysyx_24080018__DOT__idu_csr_cnt
//#define  MCAUSE  root->top__DOT__csr_t0__DOT__mcause
//#define  MTVEC   root->top__DOT__csr_t0__DOT__mtvec
//#define  MEPC		 root->top__DOT__csr_t0__DOT__mepc
//#define  MSTATUS root->top__DOT__csr_t0__DOT__mstatus
#define   CLOCK   top->clock
#define   RESET   top->reset
#define   AWREADY top->io_master_awready
#define   AWVALID top->io_master_awvalid
#define   AWADDR  top->io_master_awaddr
#define   WREADY  top->io_master_wready
#define   WVALID  top->io_master_wvalid
#define   WDATA   top->io_master_wdata
#define   WSTRB   top->io_master_wstrb
#define   BREADY  top->io_master_bready
#define   BVALID  top->io_master_bvalid
#define   BRESP   top->io_master_bresp
#define   ARREADY top->io_master_arready
#define   ARVALID top->io_master_arvalid
#define   ARADDR  top->io_master_araddr
#define   RREADY  top->io_master_rready
#define   RVALID  top->io_master_rvalid
#define   RRESP   top->io_master_rresp
#define   RDATA   top->io_master_rdata

enum { NPC_RUNNING, NPC_STOP, NPC_END, NPC_ABORT, NPC_QUIT };


typedef struct {
  uint32_t gpr[32];
  uint32_t pc;
  uint32_t csr[4];
} riscv32_CPU_state;

// decode
typedef struct {
  union {
    uint32_t val;
  } inst;
} riscv32_ISADecodeInfo;

typedef riscv32_CPU_state CPU_state;
typedef riscv32_ISADecodeInfo ISADecodeInfo;

typedef struct {
  int state;
  uint32_t halt_pc;
  uint32_t halt_ret;
} NPCState;

typedef struct Decode {
  uint32_t pc;
  uint32_t snpc; 
  uint32_t dnpc; 
  ISADecodeInfo isa;
} Decode;


extern CPU_state cpu;

extern NPCState npc_state;


void step_and_dump_wave();
void sim_init();
void NPCTRAP(int pc,int x10);
void clock_tick();
void rst_begin();
void set_npc_state(int state, uint32_t pc,int halt_ret);
void cpu_exec(uint64_t n);
int  is_exit_status_bad();


#endif
