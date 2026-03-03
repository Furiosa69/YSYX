// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vysyx_24080018__Syms.h"


void Vysyx_24080018___024root__trace_chg_0_sub_0(Vysyx_24080018___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vysyx_24080018___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24080018___024root__trace_chg_0\n"); );
    // Body
    Vysyx_24080018___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_24080018___024root*>(voidSelf);
    Vysyx_24080018__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vysyx_24080018___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vysyx_24080018___024root__trace_chg_0_sub_0(Vysyx_24080018___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24080018___024root__trace_chg_0_sub_0\n"); );
    Vysyx_24080018__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    if (VL_UNLIKELY(((vlSelfRef.__Vm_traceActivity[1U] 
                      | vlSelfRef.__Vm_traceActivity
                      [2U])))) {
        bufp->chgIData(oldp+0,(vlSelfRef.ysyx_24080018__DOT__inst),32);
        bufp->chgBit(oldp+1,(vlSelfRef.ysyx_24080018__DOT__o_ifu_arvalid));
        bufp->chgCData(oldp+2,(vlSelfRef.ysyx_24080018__DOT__i_ifu_rresp),2);
        bufp->chgBit(oldp+3,(vlSelfRef.ysyx_24080018__DOT__i_ifu_rvalid));
        bufp->chgBit(oldp+4,(vlSelfRef.ysyx_24080018__DOT__o_lsu_awvalid));
        bufp->chgBit(oldp+5,(vlSelfRef.ysyx_24080018__DOT__o_lsu_arvalid));
        bufp->chgIData(oldp+6,(((IData)(vlSelfRef.ysyx_24080018__DOT__arbiter__DOT____VdfgRegularize_hb99afc30_0_9)
                                 ? vlSelfRef.ysyx_24080018__DOT__arbiter__DOT____VdfgRegularize_hb99afc30_0_6
                                 : 0U)),32);
        bufp->chgCData(oldp+7,(((IData)(vlSelfRef.ysyx_24080018__DOT__arbiter__DOT____VdfgRegularize_hb99afc30_0_9)
                                 ? (IData)(vlSelfRef.ysyx_24080018__DOT__arbiter__DOT____VdfgRegularize_hb99afc30_0_7)
                                 : 0U)),2);
        bufp->chgBit(oldp+8,(vlSelfRef.ysyx_24080018__DOT__i_lsu_rvalid));
        bufp->chgBit(oldp+9,(vlSelfRef.ysyx_24080018__DOT__i_lsu_wready));
        bufp->chgCData(oldp+10,(vlSelfRef.ysyx_24080018__DOT__i_lsu_bresp),2);
        bufp->chgBit(oldp+11,(vlSelfRef.ysyx_24080018__DOT__i_lsu_bvalid));
        bufp->chgBit(oldp+12,(vlSelfRef.ysyx_24080018__DOT__ifu_idu_valid));
        bufp->chgBit(oldp+13,(vlSelfRef.ysyx_24080018__DOT__mem_wbu_valid));
        bufp->chgBit(oldp+14,(vlSelfRef.ysyx_24080018__DOT__wbu_ifu_retire));
        bufp->chgCData(oldp+15,(vlSelfRef.ysyx_24080018__DOT__arbiter__DOT__next_state),3);
        bufp->chgBit(oldp+16,(vlSelfRef.ysyx_24080018__DOT__arbiter__DOT__lsu_req));
        bufp->chgBit(oldp+17,(vlSelfRef.ysyx_24080018__DOT__arbiter__DOT__current_master));
        bufp->chgBit(oldp+18,(((IData)(vlSelfRef.ysyx_24080018__DOT__mem_wbu_cnt) 
                               & (IData)(vlSelfRef.ysyx_24080018__DOT__mem_wbu_valid))));
        bufp->chgCData(oldp+19,((0x0000007fU & vlSelfRef.ysyx_24080018__DOT__inst)),7);
        bufp->chgCData(oldp+20,((7U & (vlSelfRef.ysyx_24080018__DOT__inst 
                                       >> 0x0000000cU))),3);
        bufp->chgCData(oldp+21,((vlSelfRef.ysyx_24080018__DOT__inst 
                                 >> 0x00000019U)),7);
        bufp->chgCData(oldp+22,(vlSelfRef.ysyx_24080018__DOT__idu__DOT__pc_cnt),4);
        bufp->chgCData(oldp+23,(vlSelfRef.ysyx_24080018__DOT__idu__DOT__lsu_cnt),4);
        bufp->chgBit(oldp+24,(((IData)(vlSelfRef.ysyx_24080018__DOT__idu__DOT__UType) 
                               | ((0x6fU == (0x0000007fU 
                                             & vlSelfRef.ysyx_24080018__DOT__inst)) 
                                  | ((IData)(vlSelfRef.ysyx_24080018__DOT__idu__DOT__IType) 
                                     | ((0x33U == (0x0000007fU 
                                                   & vlSelfRef.ysyx_24080018__DOT__inst)) 
                                        | ((1U == (IData)(vlSelfRef.ysyx_24080018__DOT__idu__DOT__csr_cnt)) 
                                           | (2U == (IData)(vlSelfRef.ysyx_24080018__DOT__idu__DOT__csr_cnt)))))))));
        bufp->chgCData(oldp+25,(((0x33U == (0x0000007fU 
                                            & vlSelfRef.ysyx_24080018__DOT__inst))
                                  ? ((0U == (7U & (vlSelfRef.ysyx_24080018__DOT__inst 
                                                   >> 0x0000000cU)))
                                      ? ((0U == (vlSelfRef.ysyx_24080018__DOT__inst 
                                                 >> 0x00000019U))
                                          ? 1U : 2U)
                                      : (IData)(vlSelfRef.ysyx_24080018__DOT__idu__DOT____VdfgRegularize_h0640af09_0_9))
                                  : ((0x13U == (0x0000007fU 
                                                & vlSelfRef.ysyx_24080018__DOT__inst))
                                      ? ((0U == (7U 
                                                 & (vlSelfRef.ysyx_24080018__DOT__inst 
                                                    >> 0x0000000cU)))
                                          ? 1U : (IData)(vlSelfRef.ysyx_24080018__DOT__idu__DOT____VdfgRegularize_h0640af09_0_9))
                                      : ((0x67U == 
                                          (0x0000007fU 
                                           & vlSelfRef.ysyx_24080018__DOT__inst))
                                          ? 1U : ((0x6fU 
                                                   == 
                                                   (0x0000007fU 
                                                    & vlSelfRef.ysyx_24080018__DOT__inst))
                                                   ? 1U
                                                   : 
                                                  ((0x17U 
                                                    == 
                                                    (0x0000007fU 
                                                     & vlSelfRef.ysyx_24080018__DOT__inst))
                                                    ? 1U
                                                    : 
                                                   ((0x37U 
                                                     == 
                                                     (0x0000007fU 
                                                      & vlSelfRef.ysyx_24080018__DOT__inst))
                                                     ? 1U
                                                     : 
                                                    ((0x73U 
                                                      == 
                                                      (0x0000007fU 
                                                       & vlSelfRef.ysyx_24080018__DOT__inst))
                                                      ? 
                                                     ((2U 
                                                       == 
                                                       (7U 
                                                        & (vlSelfRef.ysyx_24080018__DOT__inst 
                                                           >> 0x0000000cU)))
                                                       ? 1U
                                                       : 
                                                      ((1U 
                                                        == 
                                                        (7U 
                                                         & (vlSelfRef.ysyx_24080018__DOT__inst 
                                                            >> 0x0000000cU)))
                                                        ? 1U
                                                        : 0U))
                                                      : 0U)))))))),4);
        bufp->chgCData(oldp+26,(((((IData)(vlSelfRef.ysyx_24080018__DOT__idu__DOT__UType) 
                                   << 5U) | (((0x6fU 
                                               == (0x0000007fU 
                                                   & vlSelfRef.ysyx_24080018__DOT__inst)) 
                                              << 4U) 
                                             | ((0x63U 
                                                 == 
                                                 (0x0000007fU 
                                                  & vlSelfRef.ysyx_24080018__DOT__inst)) 
                                                << 3U))) 
                                 | (((IData)(vlSelfRef.ysyx_24080018__DOT__idu__DOT__IType) 
                                     << 2U) | (((0x23U 
                                                 == 
                                                 (0x0000007fU 
                                                  & vlSelfRef.ysyx_24080018__DOT__inst)) 
                                                << 1U) 
                                               | (0x33U 
                                                  == 
                                                  (0x0000007fU 
                                                   & vlSelfRef.ysyx_24080018__DOT__inst)))))),6);
        bufp->chgCData(oldp+27,(vlSelfRef.ysyx_24080018__DOT__idu__DOT__csr_cnt),3);
        bufp->chgCData(oldp+28,((0x0000001fU & (vlSelfRef.ysyx_24080018__DOT__inst 
                                                >> 0x0000000fU))),5);
        bufp->chgCData(oldp+29,((0x0000001fU & (vlSelfRef.ysyx_24080018__DOT__inst 
                                                >> 0x00000014U))),5);
        bufp->chgCData(oldp+30,((0x0000001fU & (vlSelfRef.ysyx_24080018__DOT__inst 
                                                >> 7U))),5);
        bufp->chgIData(oldp+31,(vlSelfRef.ysyx_24080018__DOT__idu__DOT__imm),32);
        bufp->chgSData(oldp+32,(((0x73U == (0x0000007fU 
                                            & vlSelfRef.ysyx_24080018__DOT__inst))
                                  ? (vlSelfRef.ysyx_24080018__DOT__inst 
                                     >> 0x00000014U)
                                  : 0U)),12);
        bufp->chgBit(oldp+33,((0x17U == (0x0000007fU 
                                         & vlSelfRef.ysyx_24080018__DOT__inst))));
        bufp->chgBit(oldp+34,((0x37U == (0x0000007fU 
                                         & vlSelfRef.ysyx_24080018__DOT__inst))));
        bufp->chgBit(oldp+35,((0x00100073U == vlSelfRef.ysyx_24080018__DOT__inst)));
        bufp->chgBit(oldp+36,((3U == (0x0000007fU & vlSelfRef.ysyx_24080018__DOT__inst))));
        bufp->chgBit(oldp+37,((0x6fU == (0x0000007fU 
                                         & vlSelfRef.ysyx_24080018__DOT__inst))));
        bufp->chgBit(oldp+38,((0x67U == (0x0000007fU 
                                         & vlSelfRef.ysyx_24080018__DOT__inst))));
        bufp->chgBit(oldp+39,(vlSelfRef.ysyx_24080018__DOT__idu__DOT__UType));
        bufp->chgBit(oldp+40,((0x63U == (0x0000007fU 
                                         & vlSelfRef.ysyx_24080018__DOT__inst))));
        bufp->chgBit(oldp+41,(vlSelfRef.ysyx_24080018__DOT__idu__DOT__IType));
        bufp->chgBit(oldp+42,((0x23U == (0x0000007fU 
                                         & vlSelfRef.ysyx_24080018__DOT__inst))));
        bufp->chgBit(oldp+43,((0x33U == (0x0000007fU 
                                         & vlSelfRef.ysyx_24080018__DOT__inst))));
        bufp->chgBit(oldp+44,((0x73U == (0x0000007fU 
                                         & vlSelfRef.ysyx_24080018__DOT__inst))));
        bufp->chgBit(oldp+45,((0x13U == (0x0000007fU 
                                         & vlSelfRef.ysyx_24080018__DOT__inst))));
        bufp->chgBit(oldp+46,((0x00000073U == vlSelfRef.ysyx_24080018__DOT__inst)));
        bufp->chgBit(oldp+47,((0x30200073U == vlSelfRef.ysyx_24080018__DOT__inst)));
        bufp->chgBit(oldp+48,(((IData)(vlSelfRef.ysyx_24080018__DOT__idu__DOT__cstate)
                                ? ((IData)(vlSelfRef.ysyx_24080018__DOT__idu__DOT__cstate) 
                                   & ((~ (IData)(vlSelfRef.ysyx_24080018__DOT__ControlHazard)) 
                                      & (IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__cstate)))
                                : ((~ (IData)(vlSelfRef.ysyx_24080018__DOT__ControlHazard)) 
                                   & (IData)(vlSelfRef.ysyx_24080018__DOT__ifu_idu_valid)))));
        bufp->chgBit(oldp+49,(vlSelfRef.ysyx_24080018__DOT__ifu__DOT__retire));
        bufp->chgBit(oldp+50,(((IData)(vlSelfRef.ysyx_24080018__DOT__ifu__DOT__cstate)
                                ? ((IData)(vlSelfRef.ysyx_24080018__DOT__ifu__DOT__cstate) 
                                   & ((IData)(vlSelfRef.ysyx_24080018__DOT__ControlHazard) 
                                      | ((~ (IData)(vlSelfRef.ysyx_24080018__DOT__ifu__DOT__retire)) 
                                         | (vlSelfRef.ysyx_24080018__DOT__ifu__DOT__target_pc 
                                            == vlSelfRef.ysyx_24080018__DOT__ifu_pc))))
                                : ((~ (IData)(vlSelfRef.ysyx_24080018__DOT__ControlHazard)) 
                                   & ((vlSelfRef.ysyx_24080018__DOT__ifu__DOT__target_pc 
                                       != vlSelfRef.ysyx_24080018__DOT__ifu_pc) 
                                      & ((IData)(vlSelfRef.ysyx_24080018__DOT__i_ifu_rvalid) 
                                         & (0U == (IData)(vlSelfRef.ysyx_24080018__DOT__i_ifu_rresp))))))));
        bufp->chgBit(oldp+51,(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__nstate));
        bufp->chgIData(oldp+52,(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__temp),32);
        bufp->chgIData(oldp+53,(((4U == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt))
                                  ? (((- (IData)((1U 
                                                  & ((IData)(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__byte_sel) 
                                                     >> 7U)))) 
                                      << 8U) | (IData)(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__byte_sel))
                                  : ((5U == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt))
                                      ? (((- (IData)(
                                                     (1U 
                                                      & ((IData)(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__half_sel) 
                                                         >> 0x0000000fU)))) 
                                          << 0x00000010U) 
                                         | (IData)(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__half_sel))
                                      : ((6U == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt))
                                          ? vlSelfRef.ysyx_24080018__DOT__lsu__DOT__temp
                                          : ((7U == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt))
                                              ? (IData)(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__byte_sel)
                                              : ((8U 
                                                  == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt))
                                                  ? (IData)(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__half_sel)
                                                  : 0U)))))),32);
        bufp->chgBit(oldp+54,(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__shakehand));
        bufp->chgCData(oldp+55,(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__byte_sel),8);
        bufp->chgSData(oldp+56,(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__half_sel),16);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgCData(oldp+57,(vlSelfRef.ysyx_24080018__DOT__idu_waddr),5);
        bufp->chgCData(oldp+58,(vlSelfRef.ysyx_24080018__DOT__exu_waddr),5);
        bufp->chgCData(oldp+59,(vlSelfRef.ysyx_24080018__DOT__mem_waddr),5);
        bufp->chgCData(oldp+60,(vlSelfRef.ysyx_24080018__DOT__raddr1),5);
        bufp->chgCData(oldp+61,(vlSelfRef.ysyx_24080018__DOT__raddr2),5);
        bufp->chgIData(oldp+62,(vlSelfRef.ysyx_24080018__DOT__ifu_pc),32);
        bufp->chgIData(oldp+63,(vlSelfRef.ysyx_24080018__DOT__idu_pc),32);
        bufp->chgIData(oldp+64,(vlSelfRef.ysyx_24080018__DOT__exu_pc),32);
        bufp->chgIData(oldp+65,(vlSelfRef.ysyx_24080018__DOT__mem_pc),32);
        bufp->chgCData(oldp+66,(vlSelfRef.ysyx_24080018__DOT__idu_lsu_cnt),4);
        bufp->chgCData(oldp+67,(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt),4);
        bufp->chgBit(oldp+68,(vlSelfRef.ysyx_24080018__DOT__idu_wbu_cnt));
        bufp->chgBit(oldp+69,(vlSelfRef.ysyx_24080018__DOT__exu_wbu_cnt));
        bufp->chgBit(oldp+70,(vlSelfRef.ysyx_24080018__DOT__mem_wbu_cnt));
        bufp->chgBit(oldp+71,(vlSelfRef.ysyx_24080018__DOT__idu_ebreak));
        bufp->chgBit(oldp+72,(vlSelfRef.ysyx_24080018__DOT__exu_ebreak));
        bufp->chgBit(oldp+73,(vlSelfRef.ysyx_24080018__DOT__mem_ebreak));
        bufp->chgIData(oldp+74,(vlSelfRef.ysyx_24080018__DOT__exu_wdata),32);
        bufp->chgIData(oldp+75,(vlSelfRef.ysyx_24080018__DOT__mem_wdata),32);
        bufp->chgCData(oldp+76,(vlSelfRef.ysyx_24080018__DOT__alu_cnt),4);
        bufp->chgCData(oldp+77,(vlSelfRef.ysyx_24080018__DOT__ins_cnt),6);
        bufp->chgCData(oldp+78,(vlSelfRef.ysyx_24080018__DOT__idu_csr_cnt),3);
        bufp->chgCData(oldp+79,(vlSelfRef.ysyx_24080018__DOT__exu_csr_cnt),3);
        bufp->chgCData(oldp+80,(vlSelfRef.ysyx_24080018__DOT__pc_cnt),4);
        bufp->chgIData(oldp+81,(vlSelfRef.ysyx_24080018__DOT__rdata1),32);
        bufp->chgIData(oldp+82,(vlSelfRef.ysyx_24080018__DOT__rdata2),32);
        bufp->chgIData(oldp+83,(vlSelfRef.ysyx_24080018__DOT__addr_lsu),32);
        bufp->chgIData(oldp+84,(vlSelfRef.ysyx_24080018__DOT__data_store),32);
        bufp->chgIData(oldp+85,(vlSelfRef.ysyx_24080018__DOT__imm),32);
        bufp->chgSData(oldp+86,(vlSelfRef.ysyx_24080018__DOT__csr_imm),12);
        bufp->chgIData(oldp+87,(vlSelfRef.ysyx_24080018__DOT__csr_data),32);
        bufp->chgBit(oldp+88,(vlSelfRef.ysyx_24080018__DOT__br_taken));
        bufp->chgBit(oldp+89,(vlSelfRef.ysyx_24080018__DOT__auipc));
        bufp->chgBit(oldp+90,(vlSelfRef.ysyx_24080018__DOT__lui));
        bufp->chgBit(oldp+91,(vlSelfRef.ysyx_24080018__DOT__load));
        bufp->chgBit(oldp+92,(vlSelfRef.ysyx_24080018__DOT__jalr));
        bufp->chgBit(oldp+93,(vlSelfRef.ysyx_24080018__DOT__jal));
        bufp->chgBit(oldp+94,(vlSelfRef.ysyx_24080018__DOT__ControlHazard));
        bufp->chgIData(oldp+95,((((vlSelfRef.ysyx_24080018__DOT__ifu__DOT__temp_pc 
                                   != vlSelfRef.ysyx_24080018__DOT__ifu_pc) 
                                  & (0U != vlSelfRef.ysyx_24080018__DOT__ifu__DOT__temp_pc))
                                  ? vlSelfRef.ysyx_24080018__DOT__ifu__DOT__temp_pc
                                  : vlSelfRef.ysyx_24080018__DOT__ifu_pc)),32);
        bufp->chgBit(oldp+96,((1U & (~ (IData)(vlSelfRef.ysyx_24080018__DOT__ifu__DOT__cstate)))));
        bufp->chgBit(oldp+97,((1U & (~ (IData)(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__cstate)))));
        bufp->chgBit(oldp+98,(vlSelfRef.ysyx_24080018__DOT__idu__DOT__cstate));
        bufp->chgBit(oldp+99,(vlSelfRef.ysyx_24080018__DOT__exu_mem_valid));
        bufp->chgBit(oldp+100,(((IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__cstate) 
                                & (0U != (IData)(vlSelfRef.ysyx_24080018__DOT__idu_csr_cnt)))));
        bufp->chgBit(oldp+101,((1U & (~ (IData)(vlSelfRef.ysyx_24080018__DOT__idu__DOT__cstate)))));
        bufp->chgBit(oldp+102,((1U & (~ (IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__cstate)))));
        bufp->chgBit(oldp+103,((1U & (~ (IData)(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__cstate)))));
        bufp->chgBit(oldp+104,((1U & (~ (IData)(vlSelfRef.ysyx_24080018__DOT__csr__DOT__cstate)))));
        bufp->chgBit(oldp+105,(vlSelfRef.ysyx_24080018__DOT__csr_ifu_retire));
        bufp->chgIData(oldp+106,(((IData)(vlSelfRef.__VdfgRegularize_he50b618e_0_0)
                                   ? vlSelfRef.ysyx_24080018__DOT__mem_wdata
                                   : vlSelfRef.ysyx_24080018__DOT__rdata1)),32);
        bufp->chgCData(oldp+107,(vlSelfRef.ysyx_24080018__DOT__arbiter__DOT__state),3);
        bufp->chgIData(oldp+108,(vlSelfRef.ysyx_24080018__DOT__arbiter__DOT__captured_rdata),32);
        bufp->chgCData(oldp+109,(vlSelfRef.ysyx_24080018__DOT__arbiter__DOT__captured_rresp),2);
        bufp->chgCData(oldp+110,(vlSelfRef.ysyx_24080018__DOT__arbiter__DOT__captured_bresp),2);
        bufp->chgBit(oldp+111,(vlSelfRef.ysyx_24080018__DOT__arbiter__DOT__response_ready));
        bufp->chgBit(oldp+112,(vlSelfRef.ysyx_24080018__DOT__arbiter__DOT__last_master));
        bufp->chgBit(oldp+113,(vlSelfRef.ysyx_24080018__DOT__csr__DOT__cstate));
        bufp->chgIData(oldp+114,(vlSelfRef.ysyx_24080018__DOT__csr__DOT__mcycle),32);
        bufp->chgIData(oldp+115,(vlSelfRef.ysyx_24080018__DOT__csr__DOT__mcycleh),32);
        bufp->chgIData(oldp+116,(vlSelfRef.ysyx_24080018__DOT__csr__DOT__mvendorid),32);
        bufp->chgIData(oldp+117,(vlSelfRef.ysyx_24080018__DOT__csr__DOT__marchid),32);
        bufp->chgBit(oldp+118,(vlSelfRef.ysyx_24080018__DOT__exu__DOT__cstate));
        bufp->chgBit(oldp+119,(((IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__cstate)
                                 ? ((IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__cstate) 
                                    & (((IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__SType) 
                                        | (IData)(vlSelfRef.ysyx_24080018__DOT__load))
                                        ? (IData)(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__cstate)
                                        : ((IData)(vlSelfRef.ysyx_24080018__DOT__csr__DOT__cstate) 
                                           & (0U != (IData)(vlSelfRef.ysyx_24080018__DOT__idu_csr_cnt)))))
                                 : (IData)(vlSelfRef.ysyx_24080018__DOT__idu__DOT__cstate))));
        bufp->chgBit(oldp+120,(vlSelfRef.ysyx_24080018__DOT__exu__DOT__UType));
        bufp->chgBit(oldp+121,(vlSelfRef.ysyx_24080018__DOT__exu__DOT__JType));
        bufp->chgBit(oldp+122,(vlSelfRef.ysyx_24080018__DOT__exu__DOT__BType));
        bufp->chgBit(oldp+123,(vlSelfRef.ysyx_24080018__DOT__exu__DOT__IType));
        bufp->chgBit(oldp+124,(vlSelfRef.ysyx_24080018__DOT__exu__DOT__SType));
        bufp->chgBit(oldp+125,(vlSelfRef.ysyx_24080018__DOT__exu__DOT__RType));
        bufp->chgIData(oldp+126,(vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_a),32);
        bufp->chgIData(oldp+127,(vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_b),32);
        bufp->chgQData(oldp+128,(((((QData)((IData)(
                                                    (- (IData)(
                                                               (vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_a 
                                                                >> 0x0000001fU))))) 
                                    << 0x00000020U) 
                                   | (QData)((IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_a))) 
                                  >> (0x0000001fU & vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_b))),64);
        bufp->chgBit(oldp+130,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__cstate));
        bufp->chgIData(oldp+131,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[0]),32);
        bufp->chgIData(oldp+132,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[1]),32);
        bufp->chgIData(oldp+133,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[2]),32);
        bufp->chgIData(oldp+134,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[3]),32);
        bufp->chgIData(oldp+135,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[4]),32);
        bufp->chgIData(oldp+136,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[5]),32);
        bufp->chgIData(oldp+137,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[6]),32);
        bufp->chgIData(oldp+138,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[7]),32);
        bufp->chgIData(oldp+139,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[8]),32);
        bufp->chgIData(oldp+140,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[9]),32);
        bufp->chgIData(oldp+141,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[10]),32);
        bufp->chgIData(oldp+142,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[11]),32);
        bufp->chgIData(oldp+143,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[12]),32);
        bufp->chgIData(oldp+144,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[13]),32);
        bufp->chgIData(oldp+145,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[14]),32);
        bufp->chgIData(oldp+146,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[15]),32);
        bufp->chgIData(oldp+147,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[16]),32);
        bufp->chgIData(oldp+148,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[17]),32);
        bufp->chgIData(oldp+149,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[18]),32);
        bufp->chgIData(oldp+150,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[19]),32);
        bufp->chgIData(oldp+151,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[20]),32);
        bufp->chgIData(oldp+152,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[21]),32);
        bufp->chgIData(oldp+153,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[22]),32);
        bufp->chgIData(oldp+154,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[23]),32);
        bufp->chgIData(oldp+155,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[24]),32);
        bufp->chgIData(oldp+156,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[25]),32);
        bufp->chgIData(oldp+157,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[26]),32);
        bufp->chgIData(oldp+158,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[27]),32);
        bufp->chgIData(oldp+159,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[28]),32);
        bufp->chgIData(oldp+160,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[29]),32);
        bufp->chgIData(oldp+161,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[30]),32);
        bufp->chgIData(oldp+162,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[31]),32);
        bufp->chgIData(oldp+163,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__unnamedblk1__DOT__i),32);
        bufp->chgBit(oldp+164,((8U == (IData)(vlSelfRef.ysyx_24080018__DOT__pc_cnt))));
        bufp->chgBit(oldp+165,((7U == (IData)(vlSelfRef.ysyx_24080018__DOT__pc_cnt))));
        bufp->chgBit(oldp+166,(vlSelfRef.ysyx_24080018__DOT__ifu__DOT__bxx));
        bufp->chgIData(oldp+167,(vlSelfRef.ysyx_24080018__DOT__ifu__DOT__target_pc),32);
        bufp->chgBit(oldp+168,(vlSelfRef.ysyx_24080018__DOT__ifu__DOT__cstate));
        bufp->chgIData(oldp+169,(vlSelfRef.ysyx_24080018__DOT__ifu__DOT__temp_pc),32);
        bufp->chgBit(oldp+170,(vlSelfRef.ysyx_24080018__DOT__ifu__DOT__prev_idle));
        bufp->chgBit(oldp+171,(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__cstate));
        bufp->chgCData(oldp+172,(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__o_lsu_size),2);
        bufp->chgBit(oldp+173,(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__o_lsu_wen));
        bufp->chgBit(oldp+174,(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__load));
        bufp->chgCData(oldp+175,(((2U & vlSelfRef.ysyx_24080018__DOT__addr_lsu)
                                   ? 0x0cU : 3U)),4);
        bufp->chgCData(oldp+176,(((0U == (3U & vlSelfRef.ysyx_24080018__DOT__addr_lsu))
                                   ? 1U : ((1U == (3U 
                                                   & vlSelfRef.ysyx_24080018__DOT__addr_lsu))
                                            ? 2U : 
                                           ((2U == 
                                             (3U & vlSelfRef.ysyx_24080018__DOT__addr_lsu))
                                             ? 4U : 
                                            ((3U == 
                                              (3U & vlSelfRef.ysyx_24080018__DOT__addr_lsu))
                                              ? 8U : 0U))))),4);
    }
    bufp->chgBit(oldp+177,(vlSelfRef.clock));
    bufp->chgBit(oldp+178,(vlSelfRef.reset));
    bufp->chgBit(oldp+179,(vlSelfRef.io_master_awready));
    bufp->chgBit(oldp+180,(vlSelfRef.io_master_awvalid));
    bufp->chgIData(oldp+181,(vlSelfRef.io_master_awaddr),32);
    bufp->chgBit(oldp+182,(vlSelfRef.io_master_wready));
    bufp->chgBit(oldp+183,(vlSelfRef.io_master_wvalid));
    bufp->chgIData(oldp+184,(vlSelfRef.io_master_wdata),32);
    bufp->chgCData(oldp+185,(vlSelfRef.io_master_wstrb),4);
    bufp->chgBit(oldp+186,(vlSelfRef.io_master_bready));
    bufp->chgBit(oldp+187,(vlSelfRef.io_master_bvalid));
    bufp->chgCData(oldp+188,(vlSelfRef.io_master_bresp),2);
    bufp->chgBit(oldp+189,(vlSelfRef.io_master_arready));
    bufp->chgBit(oldp+190,(vlSelfRef.io_master_arvalid));
    bufp->chgIData(oldp+191,(vlSelfRef.io_master_araddr),32);
    bufp->chgBit(oldp+192,(vlSelfRef.io_master_rready));
    bufp->chgBit(oldp+193,(vlSelfRef.io_master_rvalid));
    bufp->chgCData(oldp+194,(vlSelfRef.io_master_rresp),2);
    bufp->chgIData(oldp+195,(vlSelfRef.io_master_rdata),32);
    bufp->chgBit(oldp+196,(((3U == (IData)(vlSelfRef.ysyx_24080018__DOT__arbiter__DOT__state)) 
                            & (IData)(vlSelfRef.io_master_arready))));
    bufp->chgBit(oldp+197,(((4U == (IData)(vlSelfRef.ysyx_24080018__DOT__arbiter__DOT__state)) 
                            & (IData)(vlSelfRef.io_master_awready))));
    bufp->chgBit(oldp+198,(((5U == (IData)(vlSelfRef.ysyx_24080018__DOT__arbiter__DOT__state)) 
                            & (IData)(vlSelfRef.io_master_arready))));
}

void Vysyx_24080018___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24080018___024root__trace_cleanup\n"); );
    // Body
    Vysyx_24080018___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_24080018___024root*>(voidSelf);
    Vysyx_24080018__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
