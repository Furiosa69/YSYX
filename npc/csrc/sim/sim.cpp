#include "sim/sim.h"
#include "utils/sdb.h"
#include "utils/debug.h"
#include "common.h"
#include "macro.h"
#include "utils/iringbuf.h"
#include "utils/ftrace.h"
#include "mem/memory.h"
#include "utils/difftest.h"
#include "main.h"
#include "lightsss.h"
#include <SDL2/SDL.h>

VerilatedContext* contextp ;
TOP_NAME* top;
VerilatedFstC* tfp = nullptr;
TOP_ROOT* root;

IFONE(CONFIG_RINGBUFF,
	RingBuffer  ringbuf;
)
CPU_state  cpu = {};

NPCState npc_state = { .state = NPC_STOP };  

void wp_check();

static bool record_wave_near_checkpoint = false;
static uint64_t wave_record_start_time = 0;
static const uint64_t WAVE_RECORD_DURATION = 1000; // 记录1000个时间单位

void step_and_dump_wave(){
  top->eval();
  contextp->timeInc(1);

  bool should_dump_wave = false;
  
  IFONE(CONFIG_WAVE, should_dump_wave = true;)
  
	IFONE(CONFIG_LIGHTSSS,
  if (record_wave_near_checkpoint) {
    should_dump_wave = true;
    
    if (contextp->time() > wave_record_start_time + WAVE_RECORD_DURATION) {
      record_wave_near_checkpoint = false;
    }
  }
	)

  if (should_dump_wave) {
    tfp->dump(contextp->time());
  }
}

void sim_init(){
  tfp = new VerilatedFstC;
  contextp = new VerilatedContext;
  top = new TOP_NAME;
	root = top->rootp;
  contextp -> traceEverOn(true);

  IFONE(CONFIG_WAVE,
  	top ->trace(tfp,10);
  	tfp ->open("wave.fst");
   )
//	#if defined(CONFIG_WAVE) || defined(CONFIG_LIGHTSSS)
//  	top ->trace(tfp,10);
//  	tfp ->open("wave.fst");
//	#endif
}

void set_npc_state(int state, uint32_t pc, int halt_ret) {

	IFONE(CONFIG_DIFFTEST,
		difftest_skip_ref();
	)

  npc_state.state = state;
  npc_state.halt_pc = pc;
  npc_state.halt_ret = halt_ret;
}

void NPCTRAP(uint32_t pc ,int halt_ret){
	set_npc_state(NPC_END,pc,halt_ret);
}

void clock_tick() {
    CLOCK = !CLOCK;
    step_and_dump_wave();
}

void rst_begin(){
    CLOCK = 0;
    RESET = 1;
		clock_tick();
		clock_tick();
		clock_tick();
		clock_tick();
    RESET = 0;
		clock_tick();
		clock_tick();

  	cpu.pc = PC;

		for(int i = 0; i<32 ; ++i){
			cpu.gpr[i] = GPR[i];
		}
//		cpu.csr[0] = MCAUSE;
//		cpu.csr[1] = MTVEC ;
//		cpu.csr[2] = MEPC  ;
//		cpu.csr[3] = MSTATUS;

		// Init begin
		IFONE(CONFIG_RINGBUFF,
			init_ringbuf(&ringbuf);
		)
		IFONE(CONFIG_FTRACE,
			init_ftrace();
		)
}

static int decode_exec(Decode *s){
	s->dnpc = PC;
	return 0;
}

int isa_exec_once(Decode *s){
	clock_tick();
	s->isa.inst.val = INST;

	IFONE(CONFIG_RINGBUFF,
		add_to_ringbuffer(&ringbuf,PC,INST);
	)

	clock_tick();
	return decode_exec(s);
}

static void exec_once(Decode *s, uint32_t pc) {
  if(AWVALID && WVALID && BREADY){
    pmem_write(AWADDR,WDATA,WSTRB);
    WREADY  = 1;
    AWREADY = 1;  
    BVALID  = 1;
    BRESP   = 0;
  }else{
    AWREADY = 0;
    WREADY  = 0;
    BVALID  = 0;
    BRESP   = 1;
  }

  if(ARVALID && RREADY){
    RDATA = pmem_read(ARADDR,4);
    RRESP   = 0;
    RVALID  = 1;
    ARREADY = 0;
  }else{
    RDATA   = 0;
    RRESP   = 1;
    RVALID  = 0;
    ARREADY = 1;
  }
  s->pc = pc;
  s->snpc = pc;
  isa_exec_once(s);
  cpu.pc = s->dnpc;

	for(int i = 0; i<32 ; ++i){
		cpu.gpr[i] = GPR[i];
	}
//		cpu.csr[0] = MCAUSE;
//		cpu.csr[1] = MTVEC ;
//		cpu.csr[2] = MEPC  ;
//		cpu.csr[3] = MSTATUS;

	IFONE(CONFIG_FTRACE,
		print_all_function_names(PC,DNPC,INST);
	)
	IFONE(CONFIG_ETRACE,
		if(CSR_cnt != 0){
			printf("mcause %x | mtvec %x | mepc %x | mstatus %x \n",MCAUSE,MTVEC,MEPC,MSTATUS);
		}
	)
}

static LightSSS g_execution_snapshot;
static uint64_t g_instruction_count = 0;
static uint64_t g_last_safe_point = 0;
bool should_checkpoint;

static void execute(uint64_t n) {
	Decode s;

  for (;n > 0; n --) {

		IFONE(CONFIG_LIGHTSSS,
			g_instruction_count++;
			should_checkpoint = (g_instruction_count %10000 == 0) || (cpu.pc %0x1000 == 0);
			if(should_checkpoint){
    	  int result = g_execution_snapshot.do_fork();

  			record_wave_near_checkpoint = true;
  			wave_record_start_time = contextp->time();

    	  if (result == FORK_CHILD) {
    	    uint64_t restore_point = g_execution_snapshot.get_end_cycles();
    	    printf("检查点已创建...\n");
    	    return;
    	  } else if (result == FORK_OK) {
    	    g_last_safe_point = g_instruction_count;
    	  }
    	}
		)

    exec_once(&s, cpu.pc);

		IFONE(CONFIG_WATCHPOINT,
			wp_check();
		)

		IFONE(CONFIG_DIFFTEST,
	  	difftest_step(PC,DNPC);
		)

		IFONE(CONFIG_VGA,
			vga_update_screen();
			SDL_Delay(16);
		)

    if (npc_state.state != NPC_RUNNING) {
			IFONE(CONFIG_LIGHTSSS,
      	g_execution_snapshot.wakeup_child(g_last_safe_point);
				printf("Wakeup Child in PC 0x%x\n",PC);
				g_execution_snapshot.do_clear();
				printf("清理完成\n");
				exit(EXIT_SUCCESS);
			)
			break;
		}
  }
}

void cpu_exec(uint64_t n){
	switch (npc_state.state) {
    case NPC_END: case NPC_ABORT:    
      printf("Program execution has ended. To restart the program, exit NPC and run again.\n");
      return;
    default: npc_state.state = NPC_RUNNING;
  }

	execute(n);

	switch (npc_state.state) {
	    case NPC_RUNNING:
	        npc_state.state = NPC_STOP;
	        break;
	
	    case NPC_ABORT:
					IFONE(CONFIG_RINGBUFF,
						print_ringbuf(&ringbuf);
					)
					printf(ANSI_FG_RED "NPC: At pc %x ABORT\n" ANSI_NONE,npc_state.halt_pc);
					break;
	    case NPC_END:
	        if (npc_state.halt_ret != 0) {
						IFONE(CONFIG_RINGBUFF,
							print_ringbuf(&ringbuf);
						)
						printf(ANSI_FG_RED "NPC: At pc %x HIT BAD TRAP\n" ANSI_NONE ,npc_state.halt_pc);
	        } else {
						printf(ANSI_FG_GREEN "NPC: At pc %x HIT GOOD TRAP\n" ANSI_NONE,npc_state.halt_pc);
	        }
					break;
	    case NPC_QUIT: 
					break;
	  }
}

int is_exit_status_bad() {   
  int good = (npc_state.state == NPC_END && npc_state.halt_ret == 0) || (npc_state.state == NPC_QUIT);

	IFONE(CONFIG_FTRACE,end_ftrace();)

	IFONE(CONFIG_MTRACE,close_mtracelog_file();)

  tfp->close(); 
  delete top;
  delete tfp;
  delete contextp;

  return !good;
}

