// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_24080018.h for the primary calling header

#include "Vysyx_24080018__pch.h"

VL_ATTR_COLD void Vysyx_24080018___024root___eval_static(Vysyx_24080018___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24080018___024root___eval_static\n"); );
    Vysyx_24080018__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clock__0 = vlSelfRef.clock;
}

VL_ATTR_COLD void Vysyx_24080018___024root___eval_initial(Vysyx_24080018___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24080018___024root___eval_initial\n"); );
    Vysyx_24080018__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vysyx_24080018___024root___eval_final(Vysyx_24080018___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24080018___024root___eval_final\n"); );
    Vysyx_24080018__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24080018___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vysyx_24080018___024root___eval_phase__stl(Vysyx_24080018___024root* vlSelf);

VL_ATTR_COLD void Vysyx_24080018___024root___eval_settle(Vysyx_24080018___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24080018___024root___eval_settle\n"); );
    Vysyx_24080018__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vysyx_24080018___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("/home/furiosa/Projects/MyCode/ysyx-workbench/npc/vsrc/ysyx_24080018.v", 3, "", "Settle region did not converge after 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (Vysyx_24080018___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void Vysyx_24080018___024root___eval_triggers__stl(Vysyx_24080018___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24080018___024root___eval_triggers__stl\n"); );
    Vysyx_24080018__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vysyx_24080018___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
}

VL_ATTR_COLD bool Vysyx_24080018___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24080018___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24080018___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vysyx_24080018___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vysyx_24080018___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24080018___024root___trigger_anySet__stl\n"); );
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

extern const VlUnpacked<CData/*1:0*/, 256> Vysyx_24080018__ConstPool__TABLE_h6c76257e_0;
extern const VlUnpacked<CData/*3:0*/, 64> Vysyx_24080018__ConstPool__TABLE_h6c782964_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vysyx_24080018__ConstPool__TABLE_he6bd8b03_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vysyx_24080018__ConstPool__TABLE_h881e9653_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vysyx_24080018__ConstPool__TABLE_h56c190ed_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vysyx_24080018__ConstPool__TABLE_h8c6a59f0_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vysyx_24080018__ConstPool__TABLE_h4d193276_0;
extern const VlUnpacked<CData/*0:0*/, 64> Vysyx_24080018__ConstPool__TABLE_h66672509_0;
extern const VlUnpacked<CData/*0:0*/, 1024> Vysyx_24080018__ConstPool__TABLE_h5364dd10_0;

VL_ATTR_COLD void Vysyx_24080018___024root___stl_sequent__TOP__0(Vysyx_24080018___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24080018___024root___stl_sequent__TOP__0\n"); );
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
    CData/*5:0*/ __Vtableidx4;
    __Vtableidx4 = 0;
    // Body
    vlSelfRef.ysyx_24080018__DOT__idu__DOT__UType = 
        ((0x17U == (0x0000007fU & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_rdata))) 
         | (0x37U == (0x0000007fU & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_rdata))));
    vlSelfRef.ysyx_24080018__DOT__idu__DOT__IType = 
        ((0x67U == (0x0000007fU & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_rdata))) 
         | ((3U == (0x0000007fU & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_rdata))) 
            | (0x13U == (0x0000007fU & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_rdata)))));
    vlSelfRef.ysyx_24080018__DOT__idu__DOT__pc_cnt 
        = ((0x63U == (0x0000007fU & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_rdata)))
            ? 1U : ((0x6fU == (0x0000007fU & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_rdata)))
                     ? 7U : ((0x67U == (0x0000007fU 
                                        & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_rdata)))
                              ? 8U : 0U)));
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
    __Vtableidx4 = ((((0x37U == (0x0000007fU & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_rdata))) 
                      << 5U) | (((0x17U == (0x0000007fU 
                                            & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_rdata))) 
                                 << 4U) | ((0x6fU == 
                                            (0x0000007fU 
                                             & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_rdata))) 
                                           << 3U))) 
                    | (((0x67U == (0x0000007fU & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_rdata))) 
                        << 2U) | (((0x13U == (0x0000007fU 
                                              & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_rdata))) 
                                   << 1U) | (0x33U 
                                             == (0x0000007fU 
                                                 & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_rdata))))));
    vlSelfRef.ysyx_24080018__DOT__idu__DOT__alu_cnt 
        = Vysyx_24080018__ConstPool__TABLE_h6c782964_0
        [__Vtableidx4];
    vlSelfRef.ysyx_24080018__DOT__idu__DOT__nstate 
        = ((IData)(vlSelfRef.ysyx_24080018__DOT__idu__DOT__cstate)
            ? ((IData)(vlSelfRef.ysyx_24080018__DOT__idu__DOT__cstate) 
               & ((~ (IData)(vlSelfRef.ysyx_24080018__DOT__ControlHazard)) 
                  & (IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__cstate)))
            : ((~ (IData)(vlSelfRef.ysyx_24080018__DOT__ControlHazard)) 
               & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_respValid)));
    vlSelfRef.ysyx_24080018__DOT__exu_mem_valid = ((IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__cstate) 
                                                   & (0U 
                                                      == (IData)(vlSelfRef.ysyx_24080018__DOT__idu_csr_cnt)));
    vlSelfRef.ysyx_24080018__DOT__csr_ifu_retire = 
        ((~ (IData)(vlSelfRef.ysyx_24080018__DOT__csr__DOT__cstate)) 
         & ((IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__cstate) 
            & (0U != (IData)(vlSelfRef.ysyx_24080018__DOT__idu_csr_cnt))));
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
    ysyx_24080018__DOT__ifu__DOT____VdfgRegularize_hdfb125b2_0_0 
        = ((IData)(vlSelfRef.ysyx_24080018__DOT__ControlHazard)
            ? (vlSelfRef.ysyx_24080018__DOT__idu_pc 
               + vlSelfRef.ysyx_24080018__DOT__imm)
            : (vlSelfRef.ysyx_24080018__DOT__ifu_pc 
               + vlSelfRef.ysyx_24080018__DOT__imm));
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
    vlSelfRef.ysyx_24080018__DOT__rdata2 = ((0U == (IData)(vlSelfRef.ysyx_24080018__DOT__raddr2))
                                             ? 0U : 
                                            vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf
                                            [vlSelfRef.ysyx_24080018__DOT__raddr2]);
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
    vlSelfRef.ysyx_24080018__DOT__rdata1 = ((0U == (IData)(vlSelfRef.ysyx_24080018__DOT__raddr1))
                                             ? 0U : 
                                            vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf
                                            [vlSelfRef.ysyx_24080018__DOT__raddr1]);
    vlSelfRef.__VdfgRegularize_he50b618e_0_0 = ((IData)(vlSelfRef.ysyx_24080018__DOT__mem_waddr) 
                                                == (IData)(vlSelfRef.ysyx_24080018__DOT__raddr1));
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
    vlSelfRef.ysyx_24080018__DOT__lsu__DOT__temp = 
        (((IData)(vlSelfRef.ysyx_24080018__DOT__io_lsu_respValid) 
          & (IData)(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__load))
          ? (IData)(vlSelfRef.ysyx_24080018__DOT__io_lsu_rdata)
          : 0U);
    vlSelfRef.ysyx_24080018__DOT__lsu__DOT____VdfgRegularize_h02661d78_0_8 
        = ((IData)(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__load) 
           | (IData)(vlSelfRef.ysyx_24080018__DOT__io_lsu_wen));
    vlSelfRef.ysyx_24080018__DOT__exu__DOT__nstate 
        = ((IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__cstate)
            ? ((IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__cstate) 
               & (((IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__SType) 
                   | (IData)(vlSelfRef.ysyx_24080018__DOT__load))
                   ? (IData)(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__cstate)
                   : ((IData)(vlSelfRef.ysyx_24080018__DOT__csr__DOT__cstate) 
                      & (0U != (IData)(vlSelfRef.ysyx_24080018__DOT__idu_csr_cnt)))))
            : (IData)(vlSelfRef.ysyx_24080018__DOT__idu__DOT__cstate));
    ysyx_24080018__DOT__exu__DOT____VdfgRegularize_h8ec3c3c6_0_4 
        = ((IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__RType) 
           | ((IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__BType) 
              | (IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__SType)));
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
    vlSelfRef.ysyx_24080018__DOT__wbu_ifu_retire = 
        ((~ (IData)(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__cstate)) 
         & (IData)(vlSelfRef.ysyx_24080018__DOT__mem_wbu_valid));
    vlSelfRef.ysyx_24080018__DOT__exu__DOT____VdfgRegularize_h8ec3c3c6_0_2 
        = VL_LTS_III(32, vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_a, vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_b);
    vlSelfRef.ysyx_24080018__DOT__exu__DOT____VdfgRegularize_h8ec3c3c6_0_3 
        = (vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_a 
           < vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_b);
    vlSelfRef.ysyx_24080018__DOT__ifu__DOT__retire 
        = ((IData)(vlSelfRef.ysyx_24080018__DOT__csr_ifu_retire) 
           | (IData)(vlSelfRef.ysyx_24080018__DOT__wbu_ifu_retire));
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

VL_ATTR_COLD void Vysyx_24080018___024root____Vm_traceActivitySetAll(Vysyx_24080018___024root* vlSelf);

VL_ATTR_COLD void Vysyx_24080018___024root___eval_stl(Vysyx_24080018___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24080018___024root___eval_stl\n"); );
    Vysyx_24080018__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vysyx_24080018___024root___stl_sequent__TOP__0(vlSelf);
        Vysyx_24080018___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD bool Vysyx_24080018___024root___eval_phase__stl(Vysyx_24080018___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24080018___024root___eval_phase__stl\n"); );
    Vysyx_24080018__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vysyx_24080018___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = Vysyx_24080018___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vysyx_24080018___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vysyx_24080018___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_24080018___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24080018___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vysyx_24080018___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clock)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vysyx_24080018___024root____Vm_traceActivitySetAll(Vysyx_24080018___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24080018___024root____Vm_traceActivitySetAll\n"); );
    Vysyx_24080018__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
}

VL_ATTR_COLD void Vysyx_24080018___024root___ctor_var_reset(Vysyx_24080018___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24080018___024root___ctor_var_reset\n"); );
    Vysyx_24080018__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clock = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5452235342940299466ull);
    vlSelf->reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9928399931838511862ull);
    vlSelf->io_interrupt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 408515240381666009ull);
    vlSelf->io_master_awready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15918341228068111945ull);
    vlSelf->io_master_awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1254038570903178483ull);
    vlSelf->io_master_awaddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5100000641368617149ull);
    vlSelf->io_master_awid = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12987614511039531521ull);
    vlSelf->io_master_awlen = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9580548919814266776ull);
    vlSelf->io_master_awsize = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 13854187349888989176ull);
    vlSelf->io_master_awburst = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 16970178477346425689ull);
    vlSelf->io_master_wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10619170216674498609ull);
    vlSelf->io_master_wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1901748201038864800ull);
    vlSelf->io_master_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4508192480944508561ull);
    vlSelf->io_master_wstrb = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4103275223239596405ull);
    vlSelf->io_master_wlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3571525934430669283ull);
    vlSelf->io_master_bready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5636029676147399511ull);
    vlSelf->io_master_bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14479403608764655851ull);
    vlSelf->io_master_bresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 252024972192926592ull);
    vlSelf->io_master_bid = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1062445100397978765ull);
    vlSelf->io_master_arready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 189821581177370283ull);
    vlSelf->io_master_arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17696505626772089272ull);
    vlSelf->io_master_araddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7705699152724094327ull);
    vlSelf->io_master_arid = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7405609512209415492ull);
    vlSelf->io_master_arlen = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12197991585860830104ull);
    vlSelf->io_master_srsize = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9883615941491566813ull);
    vlSelf->io_master_arburst = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5406036630392025300ull);
    vlSelf->io_master_rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14835472978164275174ull);
    vlSelf->io_master_rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4643816389357758479ull);
    vlSelf->io_master_rresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17575739218363420612ull);
    vlSelf->io_master_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13565575050082382344ull);
    vlSelf->io_master_rlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18248460336661176801ull);
    vlSelf->io_master_rid = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 10731670764913458081ull);
    vlSelf->io_slave_awready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15386364766571949112ull);
    vlSelf->io_slave_awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5334601523648441864ull);
    vlSelf->io_slave_awaddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2745451994456866424ull);
    vlSelf->io_slave_awid = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12914048876469032452ull);
    vlSelf->io_slave_awlen = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8315638325092922864ull);
    vlSelf->io_slave_awsize = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16399205572355175556ull);
    vlSelf->io_slave_awburst = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5360184287951858800ull);
    vlSelf->io_slave_wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1820984914711112230ull);
    vlSelf->io_slave_wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13353078287730269036ull);
    vlSelf->io_slave_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13100422519405067609ull);
    vlSelf->io_slave_wstrb = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1200568031881101223ull);
    vlSelf->io_slave_wlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11119378898008568253ull);
    vlSelf->io_slave_bready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5991839402217458983ull);
    vlSelf->io_slave_bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9882747069049294001ull);
    vlSelf->io_slave_bresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12095680284664615464ull);
    vlSelf->io_slave_bid = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14865370267791099114ull);
    vlSelf->io_slave_arready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14323104873743723684ull);
    vlSelf->io_slave_arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9295917410590269615ull);
    vlSelf->io_slave_araddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8494381812203753726ull);
    vlSelf->io_slave_arid = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4271623300114428176ull);
    vlSelf->io_slave_arlen = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15287740914422975644ull);
    vlSelf->io_slave_srsize = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1457067875403955093ull);
    vlSelf->io_slave_arburst = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 13405440217435810056ull);
    vlSelf->io_slave_rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13430075741762723373ull);
    vlSelf->io_slave_rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14468517393453990678ull);
    vlSelf->io_slave_rresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2774376520687953150ull);
    vlSelf->io_slave_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17943950254526375416ull);
    vlSelf->io_slave_rlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13724252849132544087ull);
    vlSelf->io_slave_rid = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13355305980320080930ull);
    vlSelf->ysyx_24080018__DOT__idu_waddr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6243326302805078159ull);
    vlSelf->ysyx_24080018__DOT__exu_waddr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 11491787304436306488ull);
    vlSelf->ysyx_24080018__DOT__mem_waddr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8906035927691665316ull);
    vlSelf->ysyx_24080018__DOT__raddr1 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 17568824013789694499ull);
    vlSelf->ysyx_24080018__DOT__raddr2 = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 3389699782850333964ull);
    vlSelf->ysyx_24080018__DOT__ifu_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12888832122808465708ull);
    vlSelf->ysyx_24080018__DOT__idu_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16214911400612473392ull);
    vlSelf->ysyx_24080018__DOT__exu_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6000252954780707335ull);
    vlSelf->ysyx_24080018__DOT__mem_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14276240972619206000ull);
    vlSelf->ysyx_24080018__DOT__idu_lsu_cnt = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1917201351916013486ull);
    vlSelf->ysyx_24080018__DOT__exu_lsu_cnt = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7059170149364806546ull);
    vlSelf->ysyx_24080018__DOT__idu_wbu_cnt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14655812064451564664ull);
    vlSelf->ysyx_24080018__DOT__exu_wbu_cnt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12058005838788151295ull);
    vlSelf->ysyx_24080018__DOT__mem_wbu_cnt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12741337630999312286ull);
    vlSelf->ysyx_24080018__DOT__idu_ebreak = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12271143743610116620ull);
    vlSelf->ysyx_24080018__DOT__exu_ebreak = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13453395986191558034ull);
    vlSelf->ysyx_24080018__DOT__mem_ebreak = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9451687035931039556ull);
    vlSelf->ysyx_24080018__DOT__exu_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5290028726690089803ull);
    vlSelf->ysyx_24080018__DOT__mem_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1422508408616198187ull);
    vlSelf->ysyx_24080018__DOT__alu_cnt = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11411363490561840494ull);
    vlSelf->ysyx_24080018__DOT__ins_cnt = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 8815150610157080146ull);
    vlSelf->ysyx_24080018__DOT__idu_csr_cnt = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 18071109099941908480ull);
    vlSelf->ysyx_24080018__DOT__exu_csr_cnt = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 734924052756094813ull);
    vlSelf->ysyx_24080018__DOT__pc_cnt = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4127990086178488051ull);
    vlSelf->ysyx_24080018__DOT__rdata1 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13677691432324446122ull);
    vlSelf->ysyx_24080018__DOT__rdata2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5043201101652340271ull);
    vlSelf->ysyx_24080018__DOT__addr_lsu = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1243910396318842614ull);
    vlSelf->ysyx_24080018__DOT__data_store = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12546705655694580817ull);
    vlSelf->ysyx_24080018__DOT__imm = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15844459453172499905ull);
    vlSelf->ysyx_24080018__DOT__csr_imm = VL_SCOPED_RAND_RESET_I(12, __VscopeHash, 11369178091145362680ull);
    vlSelf->ysyx_24080018__DOT__csr_data = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1035771565101760253ull);
    vlSelf->ysyx_24080018__DOT__br_taken = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5166609807914998979ull);
    vlSelf->ysyx_24080018__DOT__auipc = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18179169832474287493ull);
    vlSelf->ysyx_24080018__DOT__lui = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2186949540625425358ull);
    vlSelf->ysyx_24080018__DOT__load = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1405576409552531717ull);
    vlSelf->ysyx_24080018__DOT__jalr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16244383436994958949ull);
    vlSelf->ysyx_24080018__DOT__jal = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10036356369622415472ull);
    vlSelf->ysyx_24080018__DOT__ControlHazard = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14444201183800107953ull);
    vlSelf->ysyx_24080018__DOT__exu_mem_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7564016861167565230ull);
    vlSelf->ysyx_24080018__DOT__mem_wbu_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9101197229252981329ull);
    vlSelf->ysyx_24080018__DOT__wbu_ifu_retire = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3199802225180380675ull);
    vlSelf->ysyx_24080018__DOT__csr_ifu_retire = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4097773729778150599ull);
    vlSelf->ysyx_24080018__DOT____Vcellout__lsu__o_lsu_size = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1024597184646001080ull);
    vlSelf->ysyx_24080018__DOT__io_ifu_respValid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16790818476969420484ull);
    vlSelf->ysyx_24080018__DOT__io_ifu_rdata = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15699073708745474897ull);
    vlSelf->ysyx_24080018__DOT__io_lsu_wen = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8668178278982266139ull);
    vlSelf->ysyx_24080018__DOT__io_lsu_respValid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13884349888480364790ull);
    vlSelf->ysyx_24080018__DOT__io_lsu_rdata = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3535483192427038864ull);
    vlSelf->ysyx_24080018__DOT__ifu__DOT__bxx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6795418198075099564ull);
    vlSelf->ysyx_24080018__DOT__ifu__DOT__target_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16055388127088277110ull);
    vlSelf->ysyx_24080018__DOT__ifu__DOT__retire = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9681269903547604325ull);
    vlSelf->ysyx_24080018__DOT__ifu__DOT__cstate = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 531842110714637763ull);
    vlSelf->ysyx_24080018__DOT__ifu__DOT__nstate = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7704205237535614906ull);
    vlSelf->ysyx_24080018__DOT__ifu__DOT__temp_pc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15456150109453350199ull);
    vlSelf->ysyx_24080018__DOT__ifu__DOT__prev_idle = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4034906521500372198ull);
    vlSelf->ysyx_24080018__DOT__idu__DOT__pc_cnt = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 10059361748535024838ull);
    vlSelf->ysyx_24080018__DOT__idu__DOT__alu_cnt = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3436202820590541996ull);
    vlSelf->ysyx_24080018__DOT__idu__DOT__UType = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13666258362373788801ull);
    vlSelf->ysyx_24080018__DOT__idu__DOT__IType = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12167050527862804888ull);
    vlSelf->ysyx_24080018__DOT__idu__DOT__cstate = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17362683753943652554ull);
    vlSelf->ysyx_24080018__DOT__idu__DOT__nstate = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2701326679876756797ull);
    vlSelf->ysyx_24080018__DOT__exu__DOT__cstate = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11337729144327954641ull);
    vlSelf->ysyx_24080018__DOT__exu__DOT__nstate = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18066311335008315550ull);
    vlSelf->ysyx_24080018__DOT__exu__DOT__UType = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2377919251652524357ull);
    vlSelf->ysyx_24080018__DOT__exu__DOT__JType = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14050095558887907912ull);
    vlSelf->ysyx_24080018__DOT__exu__DOT__BType = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8501624153885443982ull);
    vlSelf->ysyx_24080018__DOT__exu__DOT__IType = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13062849801236480762ull);
    vlSelf->ysyx_24080018__DOT__exu__DOT__SType = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15513767594959573290ull);
    vlSelf->ysyx_24080018__DOT__exu__DOT__RType = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6101070039797558492ull);
    vlSelf->ysyx_24080018__DOT__exu__DOT__alu_a = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12635962348540258130ull);
    vlSelf->ysyx_24080018__DOT__exu__DOT__alu_b = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9442023421743119686ull);
    vlSelf->ysyx_24080018__DOT__exu__DOT____VdfgRegularize_h8ec3c3c6_0_2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12542995057467301923ull);
    vlSelf->ysyx_24080018__DOT__exu__DOT____VdfgRegularize_h8ec3c3c6_0_3 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15811803632939052098ull);
    vlSelf->ysyx_24080018__DOT__lsu__DOT__cstate = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1372054015747027207ull);
    vlSelf->ysyx_24080018__DOT__lsu__DOT__nstate = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11903600655584241364ull);
    vlSelf->ysyx_24080018__DOT__lsu__DOT__temp = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18124972264798213289ull);
    vlSelf->ysyx_24080018__DOT__lsu__DOT__load = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17483723228744635966ull);
    vlSelf->ysyx_24080018__DOT__lsu__DOT__byte_sel = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 833192059414968157ull);
    vlSelf->ysyx_24080018__DOT__lsu__DOT__half_sel = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12148799769359843447ull);
    vlSelf->ysyx_24080018__DOT__lsu__DOT____VdfgRegularize_h02661d78_0_8 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12818185261215297800ull);
    vlSelf->ysyx_24080018__DOT__gpr__DOT__cstate = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3418827902227324140ull);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->ysyx_24080018__DOT__gpr__DOT__rf[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9044610174848893640ull);
    }
    vlSelf->ysyx_24080018__DOT__gpr__DOT__unnamedblk1__DOT__i = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17145240345704626826ull);
    vlSelf->ysyx_24080018__DOT__csr__DOT__cstate = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7218381510929960711ull);
    vlSelf->ysyx_24080018__DOT__csr__DOT__mcycle = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9782985434398190882ull);
    vlSelf->ysyx_24080018__DOT__csr__DOT__mcycleh = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17572335607370969946ull);
    vlSelf->ysyx_24080018__DOT__csr__DOT__mvendorid = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13808141631555697208ull);
    vlSelf->ysyx_24080018__DOT__csr__DOT__marchid = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11803889258846008371ull);
    vlSelf->__VdfgRegularize_he50b618e_0_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 777431380022455576ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clock__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13272892335938733197ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
