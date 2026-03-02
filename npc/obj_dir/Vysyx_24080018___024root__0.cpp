// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_24080018.h for the primary calling header

#include "Vysyx_24080018__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24080018___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vysyx_24080018___024root___eval_triggers__act(Vysyx_24080018___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24080018___024root___eval_triggers__act\n"); );
    Vysyx_24080018__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((IData)(vlSelfRef.clock) 
                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clock__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__clock__0 = vlSelfRef.clock;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vysyx_24080018___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vysyx_24080018___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24080018___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

extern const VlUnpacked<CData/*0:0*/, 64> Vysyx_24080018__ConstPool__TABLE_he6bd8b03_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vysyx_24080018__ConstPool__TABLE_h881e9653_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vysyx_24080018__ConstPool__TABLE_h56c190ed_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vysyx_24080018__ConstPool__TABLE_h8c6a59f0_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vysyx_24080018__ConstPool__TABLE_h4d193276_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vysyx_24080018__ConstPool__TABLE_h66672509_0;
extern const VlUnpacked<CData/*1:0*/, 256> Vysyx_24080018__ConstPool__TABLE_h6c76257e_0;
extern const VlUnpacked<CData/*0:0*/, 1024> Vysyx_24080018__ConstPool__TABLE_h5364dd10_0;

void Vysyx_24080018___024root___nba_sequent__TOP__0(Vysyx_24080018___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24080018___024root___nba_sequent__TOP__0\n"); );
    Vysyx_24080018__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ ysyx_24080018__DOT__ifu__DOT____VdfgRegularize_hdfb125b2_0_0;
    ysyx_24080018__DOT__ifu__DOT____VdfgRegularize_hdfb125b2_0_0 = 0;
    CData/*0:0*/ ysyx_24080018__DOT__exu__DOT____VdfgRegularize_h8ec3c3c6_0_4;
    ysyx_24080018__DOT__exu__DOT____VdfgRegularize_h8ec3c3c6_0_4 = 0;
    CData/*5:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    SData/*9:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*7:0*/ __Vtableidx3;
    __Vtableidx3 = 0;
    IData/*31:0*/ __Vdly__ysyx_24080018__DOT__ifu_pc;
    __Vdly__ysyx_24080018__DOT__ifu_pc = 0;
    IData/*31:0*/ __Vdly__ysyx_24080018__DOT__idu_pc;
    __Vdly__ysyx_24080018__DOT__idu_pc = 0;
    IData/*31:0*/ __Vdly__ysyx_24080018__DOT__csr__DOT__mcycle;
    __Vdly__ysyx_24080018__DOT__csr__DOT__mcycle = 0;
    IData/*31:0*/ __Vdly__ysyx_24080018__DOT__csr__DOT__mcycleh;
    __Vdly__ysyx_24080018__DOT__csr__DOT__mcycleh = 0;
    CData/*0:0*/ __VdlySet__ysyx_24080018__DOT__gpr__DOT__rf__v0;
    __VdlySet__ysyx_24080018__DOT__gpr__DOT__rf__v0 = 0;
    IData/*31:0*/ __VdlyVal__ysyx_24080018__DOT__gpr__DOT__rf__v15;
    __VdlyVal__ysyx_24080018__DOT__gpr__DOT__rf__v15 = 0;
    CData/*4:0*/ __VdlyDim0__ysyx_24080018__DOT__gpr__DOT__rf__v15;
    __VdlyDim0__ysyx_24080018__DOT__gpr__DOT__rf__v15 = 0;
    CData/*0:0*/ __VdlySet__ysyx_24080018__DOT__gpr__DOT__rf__v15;
    __VdlySet__ysyx_24080018__DOT__gpr__DOT__rf__v15 = 0;
    // Body
    __Vdly__ysyx_24080018__DOT__idu_pc = vlSelfRef.ysyx_24080018__DOT__idu_pc;
    __Vdly__ysyx_24080018__DOT__ifu_pc = vlSelfRef.ysyx_24080018__DOT__ifu_pc;
    __Vdly__ysyx_24080018__DOT__csr__DOT__mcycle = vlSelfRef.ysyx_24080018__DOT__csr__DOT__mcycle;
    __Vdly__ysyx_24080018__DOT__csr__DOT__mcycleh = vlSelfRef.ysyx_24080018__DOT__csr__DOT__mcycleh;
    __VdlySet__ysyx_24080018__DOT__gpr__DOT__rf__v0 = 0U;
    __VdlySet__ysyx_24080018__DOT__gpr__DOT__rf__v15 = 0U;
    if ((1U & (~ (IData)(vlSelfRef.reset)))) {
        if ((1U & (~ (IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__cstate)))) {
            if (vlSelfRef.ysyx_24080018__DOT__idu__DOT__cstate) {
                vlSelfRef.ysyx_24080018__DOT__data_store 
                    = (((0U != (IData)(vlSelfRef.ysyx_24080018__DOT__mem_waddr)) 
                        & ((IData)(vlSelfRef.ysyx_24080018__DOT__mem_waddr) 
                           == (IData)(vlSelfRef.ysyx_24080018__DOT__raddr2)))
                        ? vlSelfRef.ysyx_24080018__DOT__mem_wdata
                        : vlSelfRef.ysyx_24080018__DOT__rdata2);
                vlSelfRef.ysyx_24080018__DOT__addr_lsu 
                    = (((0U != (IData)(vlSelfRef.ysyx_24080018__DOT__mem_waddr)) 
                        & ((IData)(vlSelfRef.ysyx_24080018__DOT__mem_waddr) 
                           == (IData)(vlSelfRef.ysyx_24080018__DOT__raddr1)))
                        ? (vlSelfRef.ysyx_24080018__DOT__mem_wdata 
                           + vlSelfRef.ysyx_24080018__DOT__imm)
                        : (vlSelfRef.ysyx_24080018__DOT__rdata1 
                           + vlSelfRef.ysyx_24080018__DOT__imm));
            }
        }
    }
    if (vlSelfRef.reset) {
        vlSelfRef.ysyx_24080018__DOT__gpr__DOT__unnamedblk1__DOT__i = 0x00000010U;
        __Vdly__ysyx_24080018__DOT__idu_pc = 0x30000000U;
        __Vdly__ysyx_24080018__DOT__ifu_pc = 0x30000000U;
        __Vdly__ysyx_24080018__DOT__csr__DOT__mcycle = 0U;
        __Vdly__ysyx_24080018__DOT__csr__DOT__mcycleh = 0U;
        __VdlySet__ysyx_24080018__DOT__gpr__DOT__rf__v0 = 1U;
        vlSelfRef.ysyx_24080018__DOT__load = 0U;
        vlSelfRef.ysyx_24080018__DOT__pc_cnt = 0U;
        vlSelfRef.ysyx_24080018__DOT__auipc = 0U;
        vlSelfRef.ysyx_24080018__DOT__lui = 0U;
        vlSelfRef.ysyx_24080018__DOT__jal = 0U;
        vlSelfRef.ysyx_24080018__DOT__jalr = 0U;
        vlSelfRef.ysyx_24080018__DOT__ins_cnt = 0U;
        vlSelfRef.ysyx_24080018__DOT__mem_pc = 0U;
        vlSelfRef.ysyx_24080018__DOT__csr__DOT__marchid = 0x016f6e92U;
        vlSelfRef.ysyx_24080018__DOT__csr__DOT__mvendorid = 0x79737978U;
    } else {
        if (vlSelfRef.ysyx_24080018__DOT__idu__DOT__cstate) {
            if ((1U & (~ (IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__cstate)))) {
                __Vdly__ysyx_24080018__DOT__idu_pc 
                    = vlSelfRef.ysyx_24080018__DOT__idu_pc;
                vlSelfRef.ysyx_24080018__DOT__load = 0U;
                vlSelfRef.ysyx_24080018__DOT__pc_cnt = 0U;
                vlSelfRef.ysyx_24080018__DOT__auipc = 0U;
                vlSelfRef.ysyx_24080018__DOT__lui = 0U;
                vlSelfRef.ysyx_24080018__DOT__jal = 0U;
                vlSelfRef.ysyx_24080018__DOT__jalr = 0U;
                vlSelfRef.ysyx_24080018__DOT__ins_cnt = 0U;
            }
        } else if (vlSelfRef.ysyx_24080018__DOT__io_ifu_respValid) {
            __Vdly__ysyx_24080018__DOT__idu_pc = vlSelfRef.ysyx_24080018__DOT__ifu_pc;
            vlSelfRef.ysyx_24080018__DOT__load = (3U 
                                                  == 
                                                  (0x0000007fU 
                                                   & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_rdata)));
            vlSelfRef.ysyx_24080018__DOT__pc_cnt = vlSelfRef.ysyx_24080018__DOT__idu__DOT__pc_cnt;
            vlSelfRef.ysyx_24080018__DOT__auipc = (0x17U 
                                                   == 
                                                   (0x0000007fU 
                                                    & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_rdata)));
            vlSelfRef.ysyx_24080018__DOT__lui = (0x37U 
                                                 == 
                                                 (0x0000007fU 
                                                  & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_rdata)));
            vlSelfRef.ysyx_24080018__DOT__jal = (0x6fU 
                                                 == 
                                                 (0x0000007fU 
                                                  & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_rdata)));
            vlSelfRef.ysyx_24080018__DOT__jalr = (0x67U 
                                                  == 
                                                  (0x0000007fU 
                                                   & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_rdata)));
            vlSelfRef.ysyx_24080018__DOT__ins_cnt = 
                ((((IData)(vlSelfRef.ysyx_24080018__DOT__idu__DOT__UType) 
                   << 5U) | (((0x6fU == (0x0000007fU 
                                         & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_rdata))) 
                              << 4U) | ((0x63U == (0x0000007fU 
                                                   & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_rdata))) 
                                        << 3U))) | 
                 (((IData)(vlSelfRef.ysyx_24080018__DOT__idu__DOT__IType) 
                   << 2U) | (((0x23U == (0x0000007fU 
                                         & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_rdata))) 
                              << 1U) | (0x33U == (0x0000007fU 
                                                  & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_rdata))))));
        }
        if ((1U & (~ (IData)(vlSelfRef.ysyx_24080018__DOT__ControlHazard)))) {
            if (vlSelfRef.ysyx_24080018__DOT__ifu__DOT__retire) {
                __Vdly__ysyx_24080018__DOT__ifu_pc 
                    = (((vlSelfRef.ysyx_24080018__DOT__ifu__DOT__temp_pc 
                         != vlSelfRef.ysyx_24080018__DOT__ifu_pc) 
                        & (0U != vlSelfRef.ysyx_24080018__DOT__ifu__DOT__temp_pc))
                        ? vlSelfRef.ysyx_24080018__DOT__ifu__DOT__temp_pc
                        : vlSelfRef.ysyx_24080018__DOT__ifu__DOT__target_pc);
            }
        }
        if ((1U & (~ (IData)(vlSelfRef.ysyx_24080018__DOT__csr__DOT__cstate)))) {
            if ((2U == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_csr_cnt))) {
                if ((0x0b00U == (IData)(vlSelfRef.ysyx_24080018__DOT__csr_imm))) {
                    __Vdly__ysyx_24080018__DOT__csr__DOT__mcycle 
                        = (vlSelfRef.ysyx_24080018__DOT__csr_data 
                           | vlSelfRef.ysyx_24080018__DOT__rdata1);
                } else if ((0x0b80U == (IData)(vlSelfRef.ysyx_24080018__DOT__csr_imm))) {
                    __Vdly__ysyx_24080018__DOT__csr__DOT__mcycleh 
                        = (vlSelfRef.ysyx_24080018__DOT__csr_data 
                           | vlSelfRef.ysyx_24080018__DOT__rdata1);
                }
                if ((0x0b00U != (IData)(vlSelfRef.ysyx_24080018__DOT__csr_imm))) {
                    if ((0x0b80U != (IData)(vlSelfRef.ysyx_24080018__DOT__csr_imm))) {
                        if ((0x0f11U != (IData)(vlSelfRef.ysyx_24080018__DOT__csr_imm))) {
                            if ((0x0f12U == (IData)(vlSelfRef.ysyx_24080018__DOT__csr_imm))) {
                                vlSelfRef.ysyx_24080018__DOT__csr__DOT__marchid 
                                    = (vlSelfRef.ysyx_24080018__DOT__csr_data 
                                       | vlSelfRef.ysyx_24080018__DOT__rdata1);
                            }
                        }
                        if ((0x0f11U == (IData)(vlSelfRef.ysyx_24080018__DOT__csr_imm))) {
                            vlSelfRef.ysyx_24080018__DOT__csr__DOT__mvendorid 
                                = (vlSelfRef.ysyx_24080018__DOT__csr_data 
                                   | vlSelfRef.ysyx_24080018__DOT__rdata1);
                        }
                    }
                }
            } else if ((1U == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_csr_cnt))) {
                if ((0x0b00U == (IData)(vlSelfRef.ysyx_24080018__DOT__csr_imm))) {
                    __Vdly__ysyx_24080018__DOT__csr__DOT__mcycle 
                        = vlSelfRef.ysyx_24080018__DOT__rdata1;
                } else if ((0x0b80U == (IData)(vlSelfRef.ysyx_24080018__DOT__csr_imm))) {
                    __Vdly__ysyx_24080018__DOT__csr__DOT__mcycleh 
                        = vlSelfRef.ysyx_24080018__DOT__rdata1;
                }
                if ((0x0b00U != (IData)(vlSelfRef.ysyx_24080018__DOT__csr_imm))) {
                    if ((0x0b80U != (IData)(vlSelfRef.ysyx_24080018__DOT__csr_imm))) {
                        if ((0x0f11U != (IData)(vlSelfRef.ysyx_24080018__DOT__csr_imm))) {
                            if ((0x0f12U == (IData)(vlSelfRef.ysyx_24080018__DOT__csr_imm))) {
                                vlSelfRef.ysyx_24080018__DOT__csr__DOT__marchid 
                                    = vlSelfRef.ysyx_24080018__DOT__rdata1;
                            }
                        }
                        if ((0x0f11U == (IData)(vlSelfRef.ysyx_24080018__DOT__csr_imm))) {
                            vlSelfRef.ysyx_24080018__DOT__csr__DOT__mvendorid 
                                = vlSelfRef.ysyx_24080018__DOT__rdata1;
                        }
                    }
                }
            }
        }
        if ((0xffffffffU == vlSelfRef.ysyx_24080018__DOT__csr__DOT__mcycle)) {
            __Vdly__ysyx_24080018__DOT__csr__DOT__mcycleh 
                = ((IData)(1U) + vlSelfRef.ysyx_24080018__DOT__csr__DOT__mcycleh);
            __Vdly__ysyx_24080018__DOT__csr__DOT__mcycle = 0U;
        } else {
            __Vdly__ysyx_24080018__DOT__csr__DOT__mcycle 
                = ((IData)(1U) + vlSelfRef.ysyx_24080018__DOT__csr__DOT__mcycle);
        }
        if (((~ (IData)(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__cstate)) 
             & (IData)(vlSelfRef.ysyx_24080018__DOT__mem_wbu_valid))) {
            if ((((IData)(vlSelfRef.ysyx_24080018__DOT__mem_wbu_cnt) 
                  & (IData)(vlSelfRef.ysyx_24080018__DOT__mem_wbu_valid)) 
                 & (0U != (IData)(vlSelfRef.ysyx_24080018__DOT__mem_waddr)))) {
                __VdlyVal__ysyx_24080018__DOT__gpr__DOT__rf__v15 
                    = vlSelfRef.ysyx_24080018__DOT__mem_wdata;
                __VdlyDim0__ysyx_24080018__DOT__gpr__DOT__rf__v15 
                    = vlSelfRef.ysyx_24080018__DOT__mem_waddr;
                __VdlySet__ysyx_24080018__DOT__gpr__DOT__rf__v15 = 1U;
            }
        }
        if (vlSelfRef.ysyx_24080018__DOT__lsu__DOT__cstate) {
            if (((0U == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt)) 
                 & (~ (IData)(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__cstate)))) {
                vlSelfRef.ysyx_24080018__DOT__mem_pc 
                    = vlSelfRef.ysyx_24080018__DOT__exu_pc;
            } else if (((IData)(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__load) 
                        & (IData)(vlSelfRef.ysyx_24080018__DOT__io_lsu_respValid))) {
                vlSelfRef.ysyx_24080018__DOT__mem_pc 
                    = vlSelfRef.ysyx_24080018__DOT__exu_pc;
            } else if (((IData)(vlSelfRef.ysyx_24080018__DOT__io_lsu_wen) 
                        & (IData)(vlSelfRef.ysyx_24080018__DOT__io_lsu_respValid))) {
                vlSelfRef.ysyx_24080018__DOT__mem_pc 
                    = vlSelfRef.ysyx_24080018__DOT__exu_pc;
            }
        }
    }
    if ((1U & (~ (IData)(vlSelfRef.reset)))) {
        if ((1U & (~ (IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__cstate)))) {
            if (vlSelfRef.ysyx_24080018__DOT__idu__DOT__cstate) {
                vlSelfRef.ysyx_24080018__DOT__exu_csr_cnt 
                    = vlSelfRef.ysyx_24080018__DOT__idu_csr_cnt;
            }
        }
    }
    if (vlSelfRef.reset) {
        vlSelfRef.ysyx_24080018__DOT__mem_ebreak = 0U;
    } else if (vlSelfRef.ysyx_24080018__DOT__lsu__DOT__cstate) {
        if (((0U == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt)) 
             & (~ (IData)(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__cstate)))) {
            vlSelfRef.ysyx_24080018__DOT__mem_ebreak 
                = vlSelfRef.ysyx_24080018__DOT__exu_ebreak;
        } else if (((IData)(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__load) 
                    & (IData)(vlSelfRef.ysyx_24080018__DOT__io_lsu_respValid))) {
            vlSelfRef.ysyx_24080018__DOT__mem_ebreak 
                = vlSelfRef.ysyx_24080018__DOT__exu_ebreak;
        } else if (((IData)(vlSelfRef.ysyx_24080018__DOT__io_lsu_wen) 
                    & (IData)(vlSelfRef.ysyx_24080018__DOT__io_lsu_respValid))) {
            vlSelfRef.ysyx_24080018__DOT__mem_ebreak 
                = vlSelfRef.ysyx_24080018__DOT__exu_ebreak;
        }
    }
    if ((1U & (~ (IData)(vlSelfRef.reset)))) {
        if ((1U & (~ (IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__cstate)))) {
            if (vlSelfRef.ysyx_24080018__DOT__idu__DOT__cstate) {
                vlSelfRef.ysyx_24080018__DOT__exu_ebreak 
                    = vlSelfRef.ysyx_24080018__DOT__idu_ebreak;
            }
        }
    }
    if (vlSelfRef.reset) {
        vlSelfRef.ysyx_24080018__DOT__ifu__DOT__temp_pc = 0U;
        vlSelfRef.ysyx_24080018__DOT__mem_wbu_cnt = 0U;
    } else {
        if (vlSelfRef.ysyx_24080018__DOT__ControlHazard) {
            vlSelfRef.ysyx_24080018__DOT__ifu__DOT__temp_pc 
                = vlSelfRef.ysyx_24080018__DOT__ifu__DOT__target_pc;
        }
        if ((1U & ((~ (IData)(vlSelfRef.reset)) & (~ 
                                                   ((IData)(vlSelfRef.ysyx_24080018__DOT__ifu__DOT__cstate) 
                                                    | ((IData)(vlSelfRef.ysyx_24080018__DOT__ControlHazard) 
                                                       | (IData)(vlSelfRef.ysyx_24080018__DOT__ifu__DOT__prev_idle))))))) {
            vlSelfRef.ysyx_24080018__DOT__ifu__DOT__temp_pc = 0U;
        }
        if (vlSelfRef.ysyx_24080018__DOT__lsu__DOT__cstate) {
            if (((0U == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt)) 
                 & (~ (IData)(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__cstate)))) {
                vlSelfRef.ysyx_24080018__DOT__mem_wbu_cnt 
                    = vlSelfRef.ysyx_24080018__DOT__exu_wbu_cnt;
            } else if (((IData)(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__load) 
                        & (IData)(vlSelfRef.ysyx_24080018__DOT__io_lsu_respValid))) {
                vlSelfRef.ysyx_24080018__DOT__mem_wbu_cnt 
                    = vlSelfRef.ysyx_24080018__DOT__exu_wbu_cnt;
            } else if (((IData)(vlSelfRef.ysyx_24080018__DOT__io_lsu_wen) 
                        & (IData)(vlSelfRef.ysyx_24080018__DOT__io_lsu_respValid))) {
                vlSelfRef.ysyx_24080018__DOT__mem_wbu_cnt 
                    = vlSelfRef.ysyx_24080018__DOT__exu_wbu_cnt;
            }
        }
    }
    if ((1U & (~ (IData)(vlSelfRef.reset)))) {
        if ((1U & (~ (IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__cstate)))) {
            if (vlSelfRef.ysyx_24080018__DOT__idu__DOT__cstate) {
                vlSelfRef.ysyx_24080018__DOT__exu_wbu_cnt 
                    = vlSelfRef.ysyx_24080018__DOT__idu_wbu_cnt;
            }
        }
    }
    if (vlSelfRef.reset) {
        vlSelfRef.ysyx_24080018__DOT__exu_pc = 0x30000000U;
        vlSelfRef.ysyx_24080018__DOT__csr_imm = 0U;
        vlSelfRef.ysyx_24080018__DOT__raddr2 = 0U;
        vlSelfRef.ysyx_24080018__DOT__imm = 0U;
        vlSelfRef.ysyx_24080018__DOT__raddr1 = 0U;
        vlSelfRef.ysyx_24080018__DOT__mem_waddr = 0U;
        vlSelfRef.ysyx_24080018__DOT__mem_wdata = 0U;
    } else {
        if ((1U & (~ (IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__cstate)))) {
            if (vlSelfRef.ysyx_24080018__DOT__idu__DOT__cstate) {
                vlSelfRef.ysyx_24080018__DOT__exu_pc 
                    = vlSelfRef.ysyx_24080018__DOT__idu_pc;
            }
        }
        if (vlSelfRef.ysyx_24080018__DOT__idu__DOT__cstate) {
            if ((1U & (~ (IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__cstate)))) {
                vlSelfRef.ysyx_24080018__DOT__csr_imm = 0U;
                vlSelfRef.ysyx_24080018__DOT__raddr2 = 0U;
                vlSelfRef.ysyx_24080018__DOT__imm = 0U;
                vlSelfRef.ysyx_24080018__DOT__raddr1 = 0U;
            }
        } else if (vlSelfRef.ysyx_24080018__DOT__io_ifu_respValid) {
            vlSelfRef.ysyx_24080018__DOT__csr_imm = 0U;
            vlSelfRef.ysyx_24080018__DOT__raddr2 = 0U;
            vlSelfRef.ysyx_24080018__DOT__imm = 0U;
            vlSelfRef.ysyx_24080018__DOT__raddr1 = 0U;
        }
        if (vlSelfRef.ysyx_24080018__DOT__lsu__DOT__cstate) {
            if (((0U == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt)) 
                 & (~ (IData)(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__cstate)))) {
                vlSelfRef.ysyx_24080018__DOT__mem_waddr 
                    = vlSelfRef.ysyx_24080018__DOT__exu_waddr;
                vlSelfRef.ysyx_24080018__DOT__mem_wdata 
                    = vlSelfRef.ysyx_24080018__DOT__exu_wdata;
            } else if (((IData)(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__load) 
                        & (IData)(vlSelfRef.ysyx_24080018__DOT__io_lsu_respValid))) {
                vlSelfRef.ysyx_24080018__DOT__mem_waddr 
                    = vlSelfRef.ysyx_24080018__DOT__exu_waddr;
                vlSelfRef.ysyx_24080018__DOT__mem_wdata 
                    = ((4U == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt))
                        ? (((- (IData)((1U & ((IData)(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__byte_sel) 
                                              >> 7U)))) 
                            << 8U) | (IData)(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__byte_sel))
                        : ((5U == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt))
                            ? (((- (IData)((1U & ((IData)(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__half_sel) 
                                                  >> 0x0000000fU)))) 
                                << 0x00000010U) | (IData)(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__half_sel))
                            : ((6U == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt))
                                ? vlSelfRef.ysyx_24080018__DOT__lsu__DOT__temp
                                : ((7U == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt))
                                    ? (IData)(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__byte_sel)
                                    : ((8U == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt))
                                        ? (IData)(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__half_sel)
                                        : 0U)))));
            } else if (((IData)(vlSelfRef.ysyx_24080018__DOT__io_lsu_wen) 
                        & (IData)(vlSelfRef.ysyx_24080018__DOT__io_lsu_respValid))) {
                vlSelfRef.ysyx_24080018__DOT__mem_waddr = 0U;
                vlSelfRef.ysyx_24080018__DOT__mem_wdata = 0U;
            }
        }
    }
    if ((1U & (~ (IData)(vlSelfRef.reset)))) {
        if ((1U & (~ (IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__cstate)))) {
            if (vlSelfRef.ysyx_24080018__DOT__idu__DOT__cstate) {
                vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt 
                    = vlSelfRef.ysyx_24080018__DOT__idu_lsu_cnt;
                vlSelfRef.ysyx_24080018__DOT__exu_wdata 
                    = ((1U == (IData)(vlSelfRef.ysyx_24080018__DOT__alu_cnt))
                        ? (vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_a 
                           + vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_b)
                        : ((2U == (IData)(vlSelfRef.ysyx_24080018__DOT__alu_cnt))
                            ? (vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_a 
                               - vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_b)
                            : ((3U == (IData)(vlSelfRef.ysyx_24080018__DOT__alu_cnt))
                                ? ((IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT____VdfgRegularize_h8ec3c3c6_0_2)
                                    ? 1U : 0U) : ((4U 
                                                   == (IData)(vlSelfRef.ysyx_24080018__DOT__alu_cnt))
                                                   ? 
                                                  ((IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT____VdfgRegularize_h8ec3c3c6_0_3)
                                                    ? 1U
                                                    : 0U)
                                                   : 
                                                  ((5U 
                                                    == (IData)(vlSelfRef.ysyx_24080018__DOT__alu_cnt))
                                                    ? 
                                                   (vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_a 
                                                    & vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_b)
                                                    : 
                                                   ((6U 
                                                     == (IData)(vlSelfRef.ysyx_24080018__DOT__alu_cnt))
                                                     ? 
                                                    (vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_a 
                                                     | vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_b)
                                                     : 
                                                    ((7U 
                                                      == (IData)(vlSelfRef.ysyx_24080018__DOT__alu_cnt))
                                                      ? 
                                                     (vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_a 
                                                      ^ vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_b)
                                                      : 
                                                     ((8U 
                                                       == (IData)(vlSelfRef.ysyx_24080018__DOT__alu_cnt))
                                                       ? 
                                                      (vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_a 
                                                       << 
                                                       (0x0000001fU 
                                                        & vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_b))
                                                       : 
                                                      ((9U 
                                                        == (IData)(vlSelfRef.ysyx_24080018__DOT__alu_cnt))
                                                        ? 
                                                       (vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_a 
                                                        >> 
                                                        (0x0000001fU 
                                                         & vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_b))
                                                        : 
                                                       ((0x0aU 
                                                         == (IData)(vlSelfRef.ysyx_24080018__DOT__alu_cnt))
                                                         ? (IData)(
                                                                   ((((QData)((IData)(
                                                                                (- (IData)(
                                                                                (vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_a 
                                                                                >> 0x0000001fU))))) 
                                                                      << 0x00000020U) 
                                                                     | (QData)((IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_a))) 
                                                                    >> 
                                                                    (0x0000001fU 
                                                                     & vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_b)))
                                                         : 0U))))))))));
            }
        }
    }
    if (vlSelfRef.reset) {
        vlSelfRef.ysyx_24080018__DOT__ControlHazard = 0U;
        vlSelfRef.ysyx_24080018__DOT__idu_csr_cnt = 0U;
        vlSelfRef.ysyx_24080018__DOT__idu_ebreak = 0U;
        vlSelfRef.ysyx_24080018__DOT__exu_waddr = 0U;
        vlSelfRef.ysyx_24080018__DOT__idu_wbu_cnt = 0U;
        vlSelfRef.ysyx_24080018__DOT__idu_waddr = 0U;
        vlSelfRef.ysyx_24080018__DOT__idu_lsu_cnt = 0U;
        vlSelfRef.ysyx_24080018__DOT__alu_cnt = 0U;
    } else {
        if ((1U & (~ (IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__cstate)))) {
            if (vlSelfRef.ysyx_24080018__DOT__idu__DOT__cstate) {
                vlSelfRef.ysyx_24080018__DOT__exu_waddr 
                    = vlSelfRef.ysyx_24080018__DOT__idu_waddr;
            }
        }
        if (vlSelfRef.ysyx_24080018__DOT__idu__DOT__cstate) {
            vlSelfRef.ysyx_24080018__DOT__ControlHazard = 0U;
            if ((1U & (~ (IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__cstate)))) {
                vlSelfRef.ysyx_24080018__DOT__idu_csr_cnt = 0U;
                vlSelfRef.ysyx_24080018__DOT__idu_ebreak = 0U;
                vlSelfRef.ysyx_24080018__DOT__idu_wbu_cnt = 0U;
                vlSelfRef.ysyx_24080018__DOT__idu_waddr = 0U;
                vlSelfRef.ysyx_24080018__DOT__idu_lsu_cnt = 0U;
                vlSelfRef.ysyx_24080018__DOT__alu_cnt = 0U;
            }
        } else if (vlSelfRef.ysyx_24080018__DOT__io_ifu_respValid) {
            vlSelfRef.ysyx_24080018__DOT__ControlHazard 
                = (0U != (IData)(vlSelfRef.ysyx_24080018__DOT__idu__DOT__pc_cnt));
            vlSelfRef.ysyx_24080018__DOT__idu_csr_cnt = 0U;
            vlSelfRef.ysyx_24080018__DOT__idu_ebreak = 0U;
            vlSelfRef.ysyx_24080018__DOT__idu_wbu_cnt 
                = ((IData)(vlSelfRef.ysyx_24080018__DOT__idu__DOT__UType) 
                   | ((0x6fU == (0x0000007fU & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_rdata))) 
                      | ((IData)(vlSelfRef.ysyx_24080018__DOT__idu__DOT__IType) 
                         | (0x33U == (0x0000007fU & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_rdata))))));
            vlSelfRef.ysyx_24080018__DOT__idu_waddr = 0U;
            vlSelfRef.ysyx_24080018__DOT__idu_lsu_cnt 
                = ((0x23U == (0x0000007fU & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_rdata)))
                    ? 1U : ((3U == (0x0000007fU & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_rdata)))
                             ? 4U : 0U));
            vlSelfRef.ysyx_24080018__DOT__alu_cnt = vlSelfRef.ysyx_24080018__DOT__idu__DOT__alu_cnt;
        }
    }
    vlSelfRef.ysyx_24080018__DOT__ifu_pc = __Vdly__ysyx_24080018__DOT__ifu_pc;
    vlSelfRef.ysyx_24080018__DOT__csr__DOT__mcycle 
        = __Vdly__ysyx_24080018__DOT__csr__DOT__mcycle;
    vlSelfRef.ysyx_24080018__DOT__csr__DOT__mcycleh 
        = __Vdly__ysyx_24080018__DOT__csr__DOT__mcycleh;
    if (__VdlySet__ysyx_24080018__DOT__gpr__DOT__rf__v0) {
        vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[1U] = 0U;
        vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[2U] = 0U;
        vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[3U] = 0U;
        vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[4U] = 0U;
        vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[5U] = 0U;
        vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[6U] = 0U;
        vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[7U] = 0U;
        vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[8U] = 0U;
        vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[9U] = 0U;
        vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[0x0aU] = 0U;
        vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[0x0bU] = 0U;
        vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[0x0cU] = 0U;
        vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[0x0dU] = 0U;
        vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[0x0eU] = 0U;
        vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[0x0fU] = 0U;
    }
    if (__VdlySet__ysyx_24080018__DOT__gpr__DOT__rf__v15) {
        vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[__VdlyDim0__ysyx_24080018__DOT__gpr__DOT__rf__v15] 
            = __VdlyVal__ysyx_24080018__DOT__gpr__DOT__rf__v15;
    }
    vlSelfRef.ysyx_24080018__DOT__ifu__DOT__bxx = (
                                                   (1U 
                                                    == (IData)(vlSelfRef.ysyx_24080018__DOT__pc_cnt)) 
                                                   | ((2U 
                                                       == (IData)(vlSelfRef.ysyx_24080018__DOT__pc_cnt)) 
                                                      | ((3U 
                                                          == (IData)(vlSelfRef.ysyx_24080018__DOT__pc_cnt)) 
                                                         | ((4U 
                                                             == (IData)(vlSelfRef.ysyx_24080018__DOT__pc_cnt)) 
                                                            | ((5U 
                                                                == (IData)(vlSelfRef.ysyx_24080018__DOT__pc_cnt)) 
                                                               | (6U 
                                                                  == (IData)(vlSelfRef.ysyx_24080018__DOT__pc_cnt)))))));
    __Vtableidx1 = vlSelfRef.ysyx_24080018__DOT__ins_cnt;
    vlSelfRef.ysyx_24080018__DOT__exu__DOT__UType = 
        Vysyx_24080018__ConstPool__TABLE_he6bd8b03_0
        [__Vtableidx1];
    vlSelfRef.ysyx_24080018__DOT__exu__DOT__JType = 
        Vysyx_24080018__ConstPool__TABLE_h881e9653_0
        [__Vtableidx1];
    vlSelfRef.ysyx_24080018__DOT__exu__DOT__BType = 
        Vysyx_24080018__ConstPool__TABLE_h56c190ed_0
        [__Vtableidx1];
    vlSelfRef.ysyx_24080018__DOT__exu__DOT__IType = 
        Vysyx_24080018__ConstPool__TABLE_h8c6a59f0_0
        [__Vtableidx1];
    vlSelfRef.ysyx_24080018__DOT__exu__DOT__SType = 
        Vysyx_24080018__ConstPool__TABLE_h4d193276_0
        [__Vtableidx1];
    vlSelfRef.ysyx_24080018__DOT__exu__DOT__RType = 
        Vysyx_24080018__ConstPool__TABLE_h66672509_0
        [__Vtableidx1];
    vlSelfRef.ysyx_24080018__DOT__csr__DOT__cstate 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_24080018__DOT__csr_ifu_retire));
    ysyx_24080018__DOT__exu__DOT____VdfgRegularize_h8ec3c3c6_0_4 
        = ((IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__RType) 
           | ((IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__BType) 
              | (IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__SType)));
    vlSelfRef.ysyx_24080018__DOT__idu_pc = __Vdly__ysyx_24080018__DOT__idu_pc;
    vlSelfRef.ysyx_24080018__DOT__ifu__DOT__prev_idle 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (1U 
                                                   & (~ (IData)(vlSelfRef.ysyx_24080018__DOT__ifu__DOT__cstate))));
    vlSelfRef.ysyx_24080018__DOT__csr_data = ((0x0b00U 
                                               == (IData)(vlSelfRef.ysyx_24080018__DOT__csr_imm))
                                               ? vlSelfRef.ysyx_24080018__DOT__csr__DOT__mcycle
                                               : ((0x0b80U 
                                                   == (IData)(vlSelfRef.ysyx_24080018__DOT__csr_imm))
                                                   ? vlSelfRef.ysyx_24080018__DOT__csr__DOT__mcycleh
                                                   : 
                                                  ((0x0f11U 
                                                    == (IData)(vlSelfRef.ysyx_24080018__DOT__csr_imm))
                                                    ? vlSelfRef.ysyx_24080018__DOT__csr__DOT__mvendorid
                                                    : 
                                                   ((0x0f12U 
                                                     == (IData)(vlSelfRef.ysyx_24080018__DOT__csr_imm))
                                                     ? vlSelfRef.ysyx_24080018__DOT__csr__DOT__marchid
                                                     : 0U))));
    vlSelfRef.ysyx_24080018__DOT__rdata2 = ((0U == (IData)(vlSelfRef.ysyx_24080018__DOT__raddr2))
                                             ? 0U : 
                                            vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf
                                            [vlSelfRef.ysyx_24080018__DOT__raddr2]);
    vlSelfRef.ysyx_24080018__DOT__rdata1 = ((0U == (IData)(vlSelfRef.ysyx_24080018__DOT__raddr1))
                                             ? 0U : 
                                            vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf
                                            [vlSelfRef.ysyx_24080018__DOT__raddr1]);
    vlSelfRef.__VdfgRegularize_he50b618e_0_0 = ((IData)(vlSelfRef.ysyx_24080018__DOT__mem_waddr) 
                                                == (IData)(vlSelfRef.ysyx_24080018__DOT__raddr1));
    vlSelfRef.ysyx_24080018__DOT__gpr__DOT__cstate 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_24080018__DOT__wbu_ifu_retire));
    vlSelfRef.ysyx_24080018__DOT__lsu__DOT__cstate 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__nstate));
    vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_b = 
        (((IData)(ysyx_24080018__DOT__exu__DOT____VdfgRegularize_h8ec3c3c6_0_4) 
          & (((IData)(vlSelfRef.ysyx_24080018__DOT__mem_waddr) 
              == (IData)(vlSelfRef.ysyx_24080018__DOT__raddr2)) 
             & (0U != (IData)(vlSelfRef.ysyx_24080018__DOT__mem_waddr))))
          ? vlSelfRef.ysyx_24080018__DOT__mem_wdata
          : ((IData)(vlSelfRef.ysyx_24080018__DOT__jal)
              ? 4U : ((IData)(vlSelfRef.ysyx_24080018__DOT__jalr)
                       ? 4U : (((IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__UType) 
                                | ((IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__IType) 
                                   | (IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__JType)))
                                ? vlSelfRef.ysyx_24080018__DOT__imm
                                : ((IData)(ysyx_24080018__DOT__exu__DOT____VdfgRegularize_h8ec3c3c6_0_4)
                                    ? vlSelfRef.ysyx_24080018__DOT__rdata2
                                    : 0U)))));
    vlSelfRef.ysyx_24080018__DOT__ifu__DOT__cstate 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_24080018__DOT__ifu__DOT__nstate));
    ysyx_24080018__DOT__ifu__DOT____VdfgRegularize_hdfb125b2_0_0 
        = ((IData)(vlSelfRef.ysyx_24080018__DOT__ControlHazard)
            ? (vlSelfRef.ysyx_24080018__DOT__idu_pc 
               + vlSelfRef.ysyx_24080018__DOT__imm)
            : (vlSelfRef.ysyx_24080018__DOT__ifu_pc 
               + vlSelfRef.ysyx_24080018__DOT__imm));
    vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_a = 
        ((IData)(vlSelfRef.ysyx_24080018__DOT__jalr)
          ? vlSelfRef.ysyx_24080018__DOT__idu_pc : 
         ((((IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__IType) 
            | (IData)(ysyx_24080018__DOT__exu__DOT____VdfgRegularize_h8ec3c3c6_0_4)) 
           & ((IData)(vlSelfRef.__VdfgRegularize_he50b618e_0_0) 
              & (0U != (IData)(vlSelfRef.ysyx_24080018__DOT__mem_waddr))))
           ? vlSelfRef.ysyx_24080018__DOT__mem_wdata
           : ((IData)(vlSelfRef.ysyx_24080018__DOT__auipc)
               ? vlSelfRef.ysyx_24080018__DOT__idu_pc
               : ((IData)(vlSelfRef.ysyx_24080018__DOT__lui)
                   ? 0U : ((IData)(vlSelfRef.ysyx_24080018__DOT__jal)
                            ? vlSelfRef.ysyx_24080018__DOT__idu_pc
                            : ((2U == (IData)(vlSelfRef.ysyx_24080018__DOT__idu_csr_cnt))
                                ? vlSelfRef.ysyx_24080018__DOT__csr_data
                                : ((1U == (IData)(vlSelfRef.ysyx_24080018__DOT__idu_csr_cnt))
                                    ? vlSelfRef.ysyx_24080018__DOT__csr_data
                                    : vlSelfRef.ysyx_24080018__DOT__rdata1)))))));
    __Vtableidx3 = ((((((8U == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt)) 
                        << 3U) | ((7U == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt)) 
                                  << 2U)) | (((6U == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt)) 
                                              << 1U) 
                                             | (5U 
                                                == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt)))) 
                     << 4U) | ((((4U == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt)) 
                                 << 3U) | ((3U == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt)) 
                                           << 2U)) 
                               | (((2U == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt)) 
                                   << 1U) | (1U == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt)))));
    vlSelfRef.ysyx_24080018__DOT____Vcellout__lsu__o_lsu_size 
        = Vysyx_24080018__ConstPool__TABLE_h6c76257e_0
        [__Vtableidx3];
    vlSelfRef.ysyx_24080018__DOT__io_lsu_wen = ((1U 
                                                 == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt)) 
                                                | ((2U 
                                                    == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt)) 
                                                   | (3U 
                                                      == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt))));
    vlSelfRef.ysyx_24080018__DOT__lsu__DOT__load = 
        ((4U == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt)) 
         | ((5U == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt)) 
            | ((6U == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt)) 
               | ((7U == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt)) 
                  | (8U == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt))))));
    vlSelfRef.ysyx_24080018__DOT__exu__DOT____VdfgRegularize_h8ec3c3c6_0_2 
        = VL_LTS_III(32, vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_a, vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_b);
    vlSelfRef.ysyx_24080018__DOT__exu__DOT____VdfgRegularize_h8ec3c3c6_0_3 
        = (vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_a 
           < vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_b);
    vlSelfRef.ysyx_24080018__DOT__lsu__DOT__temp = 
        (((IData)(vlSelfRef.ysyx_24080018__DOT__io_lsu_respValid) 
          & (IData)(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__load))
          ? (IData)(vlSelfRef.ysyx_24080018__DOT__io_lsu_rdata)
          : 0U);
    vlSelfRef.ysyx_24080018__DOT__lsu__DOT____VdfgRegularize_h02661d78_0_8 
        = ((IData)(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__load) 
           | (IData)(vlSelfRef.ysyx_24080018__DOT__io_lsu_wen));
    vlSelfRef.ysyx_24080018__DOT__br_taken = ((1U == (IData)(vlSelfRef.ysyx_24080018__DOT__pc_cnt))
                                               ? (vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_a 
                                                  == vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_b)
                                               : ((2U 
                                                   == (IData)(vlSelfRef.ysyx_24080018__DOT__pc_cnt))
                                                   ? 
                                                  (vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_a 
                                                   != vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_b)
                                                   : 
                                                  ((3U 
                                                    == (IData)(vlSelfRef.ysyx_24080018__DOT__pc_cnt))
                                                    ? (IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT____VdfgRegularize_h8ec3c3c6_0_2)
                                                    : 
                                                   ((4U 
                                                     == (IData)(vlSelfRef.ysyx_24080018__DOT__pc_cnt))
                                                     ? 
                                                    VL_GTES_III(32, vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_a, vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_b)
                                                     : 
                                                    ((5U 
                                                      == (IData)(vlSelfRef.ysyx_24080018__DOT__pc_cnt))
                                                      ? (IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT____VdfgRegularize_h8ec3c3c6_0_3)
                                                      : 
                                                     ((6U 
                                                       == (IData)(vlSelfRef.ysyx_24080018__DOT__pc_cnt)) 
                                                      & (vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_a 
                                                         >= vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_b)))))));
    if ((2U & vlSelfRef.ysyx_24080018__DOT__addr_lsu)) {
        vlSelfRef.ysyx_24080018__DOT__lsu__DOT__half_sel 
            = (vlSelfRef.ysyx_24080018__DOT__lsu__DOT__temp 
               >> 0x00000010U);
        vlSelfRef.ysyx_24080018__DOT__lsu__DOT__byte_sel 
            = (0x000000ffU & ((1U & vlSelfRef.ysyx_24080018__DOT__addr_lsu)
                               ? (vlSelfRef.ysyx_24080018__DOT__lsu__DOT__temp 
                                  >> 0x00000018U) : 
                              (vlSelfRef.ysyx_24080018__DOT__lsu__DOT__temp 
                               >> 0x00000010U)));
    } else {
        vlSelfRef.ysyx_24080018__DOT__lsu__DOT__half_sel 
            = (0x0000ffffU & vlSelfRef.ysyx_24080018__DOT__lsu__DOT__temp);
        vlSelfRef.ysyx_24080018__DOT__lsu__DOT__byte_sel 
            = (0x000000ffU & ((1U & vlSelfRef.ysyx_24080018__DOT__addr_lsu)
                               ? (vlSelfRef.ysyx_24080018__DOT__lsu__DOT__temp 
                                  >> 8U) : vlSelfRef.ysyx_24080018__DOT__lsu__DOT__temp));
    }
    vlSelfRef.ysyx_24080018__DOT__mem_wbu_valid = ((IData)(vlSelfRef.ysyx_24080018__DOT__lsu__DOT____VdfgRegularize_h02661d78_0_8)
                                                    ? 
                                                   ((IData)(vlSelfRef.ysyx_24080018__DOT__io_lsu_respValid) 
                                                    & (IData)(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__cstate))
                                                    : (IData)(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__cstate));
    vlSelfRef.ysyx_24080018__DOT__idu__DOT__cstate 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_24080018__DOT__idu__DOT__nstate));
    vlSelfRef.ysyx_24080018__DOT__exu__DOT__cstate 
        = ((1U & (~ (IData)(vlSelfRef.reset))) && (IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__nstate));
    vlSelfRef.ysyx_24080018__DOT__ifu__DOT__target_pc 
        = (((~ (IData)(vlSelfRef.ysyx_24080018__DOT__br_taken)) 
            & (IData)(vlSelfRef.ysyx_24080018__DOT__ifu__DOT__bxx))
            ? vlSelfRef.ysyx_24080018__DOT__ifu_pc : 
           (((IData)(vlSelfRef.ysyx_24080018__DOT__ifu__DOT__bxx) 
             & (IData)(vlSelfRef.ysyx_24080018__DOT__br_taken))
             ? ysyx_24080018__DOT__ifu__DOT____VdfgRegularize_hdfb125b2_0_0
             : ((7U == (IData)(vlSelfRef.ysyx_24080018__DOT__pc_cnt))
                 ? ysyx_24080018__DOT__ifu__DOT____VdfgRegularize_hdfb125b2_0_0
                 : ((8U == (IData)(vlSelfRef.ysyx_24080018__DOT__pc_cnt))
                     ? ((IData)(vlSelfRef.__VdfgRegularize_he50b618e_0_0)
                         ? vlSelfRef.ysyx_24080018__DOT__mem_wdata
                         : vlSelfRef.ysyx_24080018__DOT__rdata1)
                     : ((IData)(4U) + vlSelfRef.ysyx_24080018__DOT__ifu_pc)))));
    vlSelfRef.ysyx_24080018__DOT__wbu_ifu_retire = 
        ((~ (IData)(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__cstate)) 
         & (IData)(vlSelfRef.ysyx_24080018__DOT__mem_wbu_valid));
    vlSelfRef.ysyx_24080018__DOT__idu__DOT__nstate 
        = ((IData)(vlSelfRef.ysyx_24080018__DOT__idu__DOT__cstate)
            ? ((IData)(vlSelfRef.ysyx_24080018__DOT__idu__DOT__cstate) 
               & ((~ (IData)(vlSelfRef.ysyx_24080018__DOT__ControlHazard)) 
                  & (IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__cstate)))
            : ((~ (IData)(vlSelfRef.ysyx_24080018__DOT__ControlHazard)) 
               & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_respValid)));
    if (vlSelfRef.ysyx_24080018__DOT__exu__DOT__cstate) {
        vlSelfRef.ysyx_24080018__DOT__exu__DOT__nstate 
            = ((IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__cstate) 
               & (((IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__SType) 
                   | (IData)(vlSelfRef.ysyx_24080018__DOT__load))
                   ? (IData)(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__cstate)
                   : ((IData)(vlSelfRef.ysyx_24080018__DOT__csr__DOT__cstate) 
                      & (0U != (IData)(vlSelfRef.ysyx_24080018__DOT__idu_csr_cnt)))));
        vlSelfRef.ysyx_24080018__DOT__exu_mem_valid 
            = (0U == (IData)(vlSelfRef.ysyx_24080018__DOT__idu_csr_cnt));
    } else {
        vlSelfRef.ysyx_24080018__DOT__exu__DOT__nstate 
            = vlSelfRef.ysyx_24080018__DOT__idu__DOT__cstate;
        vlSelfRef.ysyx_24080018__DOT__exu_mem_valid = 0U;
    }
    vlSelfRef.ysyx_24080018__DOT__csr_ifu_retire = 
        ((~ (IData)(vlSelfRef.ysyx_24080018__DOT__csr__DOT__cstate)) 
         & ((IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__cstate) 
            & (0U != (IData)(vlSelfRef.ysyx_24080018__DOT__idu_csr_cnt))));
    __Vtableidx2 = ((((((IData)(vlSelfRef.ysyx_24080018__DOT__exu_mem_valid) 
                        << 4U) | (((IData)(vlSelfRef.ysyx_24080018__DOT__io_lsu_wen) 
                                   << 3U) | ((IData)(vlSelfRef.ysyx_24080018__DOT__io_lsu_respValid) 
                                             << 2U))) 
                      | (((IData)(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__load) 
                          << 1U) | (1U & (~ (IData)(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__cstate))))) 
                     << 5U) | (((IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt) 
                                << 1U) | (IData)(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__cstate)));
    vlSelfRef.ysyx_24080018__DOT__lsu__DOT__nstate 
        = Vysyx_24080018__ConstPool__TABLE_h5364dd10_0
        [__Vtableidx2];
    vlSelfRef.ysyx_24080018__DOT__ifu__DOT__retire 
        = ((IData)(vlSelfRef.ysyx_24080018__DOT__csr_ifu_retire) 
           | (IData)(vlSelfRef.ysyx_24080018__DOT__wbu_ifu_retire));
    vlSelfRef.ysyx_24080018__DOT__ifu__DOT__nstate 
        = ((IData)(vlSelfRef.ysyx_24080018__DOT__ifu__DOT__cstate)
            ? ((IData)(vlSelfRef.ysyx_24080018__DOT__ifu__DOT__cstate) 
               & ((IData)(vlSelfRef.ysyx_24080018__DOT__ControlHazard) 
                  | ((~ (IData)(vlSelfRef.ysyx_24080018__DOT__ifu__DOT__retire)) 
                     | (vlSelfRef.ysyx_24080018__DOT__ifu__DOT__target_pc 
                        == vlSelfRef.ysyx_24080018__DOT__ifu_pc))))
            : ((~ (IData)(vlSelfRef.ysyx_24080018__DOT__ControlHazard)) 
               & ((vlSelfRef.ysyx_24080018__DOT__ifu__DOT__target_pc 
                   != vlSelfRef.ysyx_24080018__DOT__ifu_pc) 
                  & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_respValid))));
}

void Vysyx_24080018___024root___eval_nba(Vysyx_24080018___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24080018___024root___eval_nba\n"); );
    Vysyx_24080018__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vysyx_24080018___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

void Vysyx_24080018___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24080018___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vysyx_24080018___024root___eval_phase__act(Vysyx_24080018___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24080018___024root___eval_phase__act\n"); );
    Vysyx_24080018__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vysyx_24080018___024root___eval_triggers__act(vlSelf);
    Vysyx_24080018___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vysyx_24080018___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24080018___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vysyx_24080018___024root___eval_phase__nba(Vysyx_24080018___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24080018___024root___eval_phase__nba\n"); );
    Vysyx_24080018__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vysyx_24080018___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vysyx_24080018___024root___eval_nba(vlSelf);
        Vysyx_24080018___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vysyx_24080018___024root___eval(Vysyx_24080018___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24080018___024root___eval\n"); );
    Vysyx_24080018__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vysyx_24080018___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("/home/furiosa/Projects/MyCode/ysyx-workbench/npc/vsrc/ysyx_24080018.v", 3, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vysyx_24080018___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("/home/furiosa/Projects/MyCode/ysyx-workbench/npc/vsrc/ysyx_24080018.v", 3, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vysyx_24080018___024root___eval_phase__act(vlSelf));
    } while (Vysyx_24080018___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vysyx_24080018___024root___eval_debug_assertions(Vysyx_24080018___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24080018___024root___eval_debug_assertions\n"); );
    Vysyx_24080018__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clock & 0xfeU)))) {
        Verilated::overWidthError("clock");
    }
    if (VL_UNLIKELY(((vlSelfRef.reset & 0xfeU)))) {
        Verilated::overWidthError("reset");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_interrupt & 0xfeU)))) {
        Verilated::overWidthError("io_interrupt");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_master_awready & 0xfeU)))) {
        Verilated::overWidthError("io_master_awready");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_master_wready & 0xfeU)))) {
        Verilated::overWidthError("io_master_wready");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_master_bvalid & 0xfeU)))) {
        Verilated::overWidthError("io_master_bvalid");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_master_bresp & 0xfcU)))) {
        Verilated::overWidthError("io_master_bresp");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_master_bid & 0xf0U)))) {
        Verilated::overWidthError("io_master_bid");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_master_arready & 0xfeU)))) {
        Verilated::overWidthError("io_master_arready");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_master_rvalid & 0xfeU)))) {
        Verilated::overWidthError("io_master_rvalid");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_master_rresp & 0xfcU)))) {
        Verilated::overWidthError("io_master_rresp");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_master_rlast & 0xfeU)))) {
        Verilated::overWidthError("io_master_rlast");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_master_rid & 0xf0U)))) {
        Verilated::overWidthError("io_master_rid");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_slave_awvalid & 0xfeU)))) {
        Verilated::overWidthError("io_slave_awvalid");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_slave_awid & 0xf0U)))) {
        Verilated::overWidthError("io_slave_awid");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_slave_awsize & 0xf8U)))) {
        Verilated::overWidthError("io_slave_awsize");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_slave_awburst & 0xfcU)))) {
        Verilated::overWidthError("io_slave_awburst");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_slave_wvalid & 0xfeU)))) {
        Verilated::overWidthError("io_slave_wvalid");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_slave_wstrb & 0xf0U)))) {
        Verilated::overWidthError("io_slave_wstrb");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_slave_wlast & 0xfeU)))) {
        Verilated::overWidthError("io_slave_wlast");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_slave_bready & 0xfeU)))) {
        Verilated::overWidthError("io_slave_bready");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_slave_arvalid & 0xfeU)))) {
        Verilated::overWidthError("io_slave_arvalid");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_slave_arid & 0xf0U)))) {
        Verilated::overWidthError("io_slave_arid");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_slave_srsize & 0xf8U)))) {
        Verilated::overWidthError("io_slave_srsize");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_slave_arburst & 0xfcU)))) {
        Verilated::overWidthError("io_slave_arburst");
    }
    if (VL_UNLIKELY(((vlSelfRef.io_slave_rready & 0xfeU)))) {
        Verilated::overWidthError("io_slave_rready");
    }
}
#endif  // VL_DEBUG
