// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vysyx_24080018.h for the primary calling header

#ifndef VERILATED_VYSYX_24080018___024ROOT_H_
#define VERILATED_VYSYX_24080018___024ROOT_H_  // guard

#include "verilated.h"


class Vysyx_24080018__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vysyx_24080018___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clock,0,0);
        VL_IN8(reset,0,0);
        VL_IN8(io_master_awready,0,0);
        VL_OUT8(io_master_awvalid,0,0);
        VL_IN8(io_master_wready,0,0);
        VL_OUT8(io_master_wvalid,0,0);
        VL_OUT8(io_master_wstrb,3,0);
        VL_OUT8(io_master_bready,0,0);
        VL_IN8(io_master_bvalid,0,0);
        VL_IN8(io_master_bresp,1,0);
        VL_IN8(io_master_arready,0,0);
        VL_OUT8(io_master_arvalid,0,0);
        VL_OUT8(io_master_rready,0,0);
        VL_IN8(io_master_rvalid,0,0);
        VL_IN8(io_master_rresp,1,0);
        CData/*4:0*/ ysyx_24080018__DOT__idu_waddr;
        CData/*4:0*/ ysyx_24080018__DOT__exu_waddr;
        CData/*4:0*/ ysyx_24080018__DOT__mem_waddr;
        CData/*4:0*/ ysyx_24080018__DOT__raddr1;
        CData/*4:0*/ ysyx_24080018__DOT__raddr2;
        CData/*3:0*/ ysyx_24080018__DOT__idu_lsu_cnt;
        CData/*3:0*/ ysyx_24080018__DOT__exu_lsu_cnt;
        CData/*0:0*/ ysyx_24080018__DOT__idu_wbu_cnt;
        CData/*0:0*/ ysyx_24080018__DOT__exu_wbu_cnt;
        CData/*0:0*/ ysyx_24080018__DOT__mem_wbu_cnt;
        CData/*0:0*/ ysyx_24080018__DOT__idu_ebreak;
        CData/*0:0*/ ysyx_24080018__DOT__exu_ebreak;
        CData/*0:0*/ ysyx_24080018__DOT__mem_ebreak;
        CData/*3:0*/ ysyx_24080018__DOT__alu_cnt;
        CData/*5:0*/ ysyx_24080018__DOT__ins_cnt;
        CData/*2:0*/ ysyx_24080018__DOT__idu_csr_cnt;
        CData/*2:0*/ ysyx_24080018__DOT__exu_csr_cnt;
        CData/*3:0*/ ysyx_24080018__DOT__pc_cnt;
        CData/*0:0*/ ysyx_24080018__DOT__br_taken;
        CData/*0:0*/ ysyx_24080018__DOT__auipc;
        CData/*0:0*/ ysyx_24080018__DOT__lui;
        CData/*0:0*/ ysyx_24080018__DOT__load;
        CData/*0:0*/ ysyx_24080018__DOT__jalr;
        CData/*0:0*/ ysyx_24080018__DOT__jal;
        CData/*0:0*/ ysyx_24080018__DOT__ControlHazard;
        CData/*0:0*/ ysyx_24080018__DOT__o_ifu_arvalid;
        CData/*1:0*/ ysyx_24080018__DOT__i_ifu_rresp;
        CData/*0:0*/ ysyx_24080018__DOT__i_ifu_rvalid;
        CData/*0:0*/ ysyx_24080018__DOT__o_lsu_awvalid;
        CData/*0:0*/ ysyx_24080018__DOT__o_lsu_arvalid;
        CData/*0:0*/ ysyx_24080018__DOT__i_lsu_rvalid;
        CData/*0:0*/ ysyx_24080018__DOT__i_lsu_wready;
        CData/*1:0*/ ysyx_24080018__DOT__i_lsu_bresp;
        CData/*0:0*/ ysyx_24080018__DOT__i_lsu_bvalid;
        CData/*0:0*/ ysyx_24080018__DOT__ifu_idu_valid;
        CData/*0:0*/ ysyx_24080018__DOT__exu_mem_valid;
        CData/*0:0*/ ysyx_24080018__DOT__mem_wbu_valid;
        CData/*0:0*/ ysyx_24080018__DOT__wbu_ifu_retire;
        CData/*0:0*/ ysyx_24080018__DOT__csr_ifu_retire;
        CData/*0:0*/ ysyx_24080018__DOT__ifu__DOT__bxx;
        CData/*0:0*/ ysyx_24080018__DOT__ifu__DOT__retire;
        CData/*0:0*/ ysyx_24080018__DOT__ifu__DOT__cstate;
        CData/*0:0*/ ysyx_24080018__DOT__ifu__DOT__nstate;
        CData/*0:0*/ ysyx_24080018__DOT__ifu__DOT__prev_idle;
        CData/*3:0*/ ysyx_24080018__DOT__idu__DOT__pc_cnt;
        CData/*3:0*/ ysyx_24080018__DOT__idu__DOT__lsu_cnt;
        CData/*2:0*/ ysyx_24080018__DOT__idu__DOT__csr_cnt;
        CData/*0:0*/ ysyx_24080018__DOT__idu__DOT__UType;
        CData/*0:0*/ ysyx_24080018__DOT__idu__DOT__IType;
    };
    struct {
        CData/*0:0*/ ysyx_24080018__DOT__idu__DOT__cstate;
        CData/*0:0*/ ysyx_24080018__DOT__idu__DOT__nstate;
        CData/*3:0*/ ysyx_24080018__DOT__idu__DOT____VdfgRegularize_h0640af09_0_9;
        CData/*0:0*/ ysyx_24080018__DOT__exu__DOT__cstate;
        CData/*0:0*/ ysyx_24080018__DOT__exu__DOT__nstate;
        CData/*0:0*/ ysyx_24080018__DOT__exu__DOT__UType;
        CData/*0:0*/ ysyx_24080018__DOT__exu__DOT__JType;
        CData/*0:0*/ ysyx_24080018__DOT__exu__DOT__BType;
        CData/*0:0*/ ysyx_24080018__DOT__exu__DOT__IType;
        CData/*0:0*/ ysyx_24080018__DOT__exu__DOT__SType;
        CData/*0:0*/ ysyx_24080018__DOT__exu__DOT__RType;
        CData/*0:0*/ ysyx_24080018__DOT__exu__DOT____VdfgRegularize_h8ec3c3c6_0_2;
        CData/*0:0*/ ysyx_24080018__DOT__exu__DOT____VdfgRegularize_h8ec3c3c6_0_3;
        CData/*0:0*/ ysyx_24080018__DOT__lsu__DOT__cstate;
        CData/*0:0*/ ysyx_24080018__DOT__lsu__DOT__nstate;
        CData/*1:0*/ ysyx_24080018__DOT__lsu__DOT__o_lsu_size;
        CData/*0:0*/ ysyx_24080018__DOT__lsu__DOT__o_lsu_wen;
        CData/*0:0*/ ysyx_24080018__DOT__lsu__DOT__load;
        CData/*0:0*/ ysyx_24080018__DOT__lsu__DOT__shakehand;
        CData/*7:0*/ ysyx_24080018__DOT__lsu__DOT__byte_sel;
        CData/*0:0*/ ysyx_24080018__DOT__gpr__DOT__cstate;
        CData/*0:0*/ ysyx_24080018__DOT__csr__DOT__cstate;
        CData/*2:0*/ ysyx_24080018__DOT__arbiter__DOT__state;
        CData/*2:0*/ ysyx_24080018__DOT__arbiter__DOT__next_state;
        CData/*0:0*/ ysyx_24080018__DOT__arbiter__DOT__lsu_req;
        CData/*0:0*/ ysyx_24080018__DOT__arbiter__DOT__current_master;
        CData/*0:0*/ ysyx_24080018__DOT__arbiter__DOT__current_is_write;
        CData/*1:0*/ ysyx_24080018__DOT__arbiter__DOT__captured_rresp;
        CData/*1:0*/ ysyx_24080018__DOT__arbiter__DOT__captured_bresp;
        CData/*0:0*/ ysyx_24080018__DOT__arbiter__DOT__response_ready;
        CData/*0:0*/ ysyx_24080018__DOT__arbiter__DOT__last_master;
        CData/*1:0*/ ysyx_24080018__DOT__arbiter__DOT____VdfgRegularize_hb99afc30_0_7;
        CData/*0:0*/ ysyx_24080018__DOT__arbiter__DOT____VdfgRegularize_hb99afc30_0_9;
        CData/*0:0*/ __VdfgRegularize_he50b618e_0_0;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clock__0;
        SData/*11:0*/ ysyx_24080018__DOT__csr_imm;
        SData/*15:0*/ ysyx_24080018__DOT__lsu__DOT__half_sel;
        VL_OUT(io_master_awaddr,31,0);
        VL_OUT(io_master_wdata,31,0);
        VL_OUT(io_master_araddr,31,0);
        VL_IN(io_master_rdata,31,0);
        IData/*31:0*/ ysyx_24080018__DOT__ifu_pc;
        IData/*31:0*/ ysyx_24080018__DOT__idu_pc;
        IData/*31:0*/ ysyx_24080018__DOT__exu_pc;
        IData/*31:0*/ ysyx_24080018__DOT__mem_pc;
        IData/*31:0*/ ysyx_24080018__DOT__inst;
        IData/*31:0*/ ysyx_24080018__DOT__exu_wdata;
        IData/*31:0*/ ysyx_24080018__DOT__mem_wdata;
        IData/*31:0*/ ysyx_24080018__DOT__rdata1;
        IData/*31:0*/ ysyx_24080018__DOT__rdata2;
        IData/*31:0*/ ysyx_24080018__DOT__addr_lsu;
        IData/*31:0*/ ysyx_24080018__DOT__data_store;
        IData/*31:0*/ ysyx_24080018__DOT__imm;
        IData/*31:0*/ ysyx_24080018__DOT__csr_data;
        IData/*31:0*/ ysyx_24080018__DOT__ifu__DOT__target_pc;
        IData/*31:0*/ ysyx_24080018__DOT__ifu__DOT__temp_pc;
        IData/*31:0*/ ysyx_24080018__DOT__idu__DOT__imm;
        IData/*31:0*/ ysyx_24080018__DOT__exu__DOT__alu_a;
        IData/*31:0*/ ysyx_24080018__DOT__exu__DOT__alu_b;
        IData/*31:0*/ ysyx_24080018__DOT__lsu__DOT__temp;
        IData/*31:0*/ ysyx_24080018__DOT__gpr__DOT__unnamedblk1__DOT__i;
        IData/*31:0*/ ysyx_24080018__DOT__csr__DOT__mcycle;
    };
    struct {
        IData/*31:0*/ ysyx_24080018__DOT__csr__DOT__mcycleh;
        IData/*31:0*/ ysyx_24080018__DOT__csr__DOT__mvendorid;
        IData/*31:0*/ ysyx_24080018__DOT__csr__DOT__marchid;
        IData/*31:0*/ ysyx_24080018__DOT__arbiter__DOT__captured_rdata;
        IData/*31:0*/ ysyx_24080018__DOT__arbiter__DOT____VdfgRegularize_hb99afc30_0_6;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<IData/*31:0*/, 32> ysyx_24080018__DOT__gpr__DOT__rf;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
        VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    };

    // INTERNAL VARIABLES
    Vysyx_24080018__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vysyx_24080018___024root(Vysyx_24080018__Syms* symsp, const char* v__name);
    ~Vysyx_24080018___024root();
    VL_UNCOPYABLE(Vysyx_24080018___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
