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
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[0U]))) {
        bufp->chgCData(oldp+0,(vlSelfRef.ysyx_24080018__DOT__idu__DOT__pc_cnt),4);
        bufp->chgBit(oldp+1,(((IData)(vlSelfRef.ysyx_24080018__DOT__idu__DOT__UType) 
                              | ((0x6fU == (0x0000007fU 
                                            & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_rdata))) 
                                 | ((IData)(vlSelfRef.ysyx_24080018__DOT__idu__DOT__IType) 
                                    | (0x33U == (0x0000007fU 
                                                 & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_rdata))))))));
        bufp->chgCData(oldp+2,(vlSelfRef.ysyx_24080018__DOT__idu__DOT__alu_cnt),4);
        bufp->chgCData(oldp+3,(((((IData)(vlSelfRef.ysyx_24080018__DOT__idu__DOT__UType) 
                                  << 5U) | (((0x6fU 
                                              == (0x0000007fU 
                                                  & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_rdata))) 
                                             << 4U) 
                                            | ((0x63U 
                                                == 
                                                (0x0000007fU 
                                                 & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_rdata))) 
                                               << 3U))) 
                                | (((IData)(vlSelfRef.ysyx_24080018__DOT__idu__DOT__IType) 
                                    << 2U) | (((0x23U 
                                                == 
                                                (0x0000007fU 
                                                 & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_rdata))) 
                                               << 1U) 
                                              | (0x33U 
                                                 == 
                                                 (0x0000007fU 
                                                  & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_rdata))))))),6);
        bufp->chgBit(oldp+4,(vlSelfRef.ysyx_24080018__DOT__idu__DOT__UType));
        bufp->chgBit(oldp+5,(vlSelfRef.ysyx_24080018__DOT__idu__DOT__IType));
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgCData(oldp+6,(vlSelfRef.ysyx_24080018__DOT__idu_waddr),5);
        bufp->chgCData(oldp+7,(vlSelfRef.ysyx_24080018__DOT__exu_waddr),5);
        bufp->chgCData(oldp+8,(vlSelfRef.ysyx_24080018__DOT__mem_waddr),5);
        bufp->chgCData(oldp+9,(vlSelfRef.ysyx_24080018__DOT__raddr1),5);
        bufp->chgCData(oldp+10,(vlSelfRef.ysyx_24080018__DOT__raddr2),5);
        bufp->chgIData(oldp+11,(vlSelfRef.ysyx_24080018__DOT__ifu_pc),32);
        bufp->chgIData(oldp+12,(vlSelfRef.ysyx_24080018__DOT__idu_pc),32);
        bufp->chgIData(oldp+13,(vlSelfRef.ysyx_24080018__DOT__exu_pc),32);
        bufp->chgIData(oldp+14,(vlSelfRef.ysyx_24080018__DOT__mem_pc),32);
        bufp->chgCData(oldp+15,(vlSelfRef.ysyx_24080018__DOT__idu_lsu_cnt),4);
        bufp->chgCData(oldp+16,(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt),4);
        bufp->chgBit(oldp+17,(vlSelfRef.ysyx_24080018__DOT__idu_wbu_cnt));
        bufp->chgBit(oldp+18,(vlSelfRef.ysyx_24080018__DOT__exu_wbu_cnt));
        bufp->chgBit(oldp+19,(vlSelfRef.ysyx_24080018__DOT__mem_wbu_cnt));
        bufp->chgBit(oldp+20,(vlSelfRef.ysyx_24080018__DOT__idu_ebreak));
        bufp->chgBit(oldp+21,(vlSelfRef.ysyx_24080018__DOT__exu_ebreak));
        bufp->chgBit(oldp+22,(vlSelfRef.ysyx_24080018__DOT__mem_ebreak));
        bufp->chgIData(oldp+23,(vlSelfRef.ysyx_24080018__DOT__exu_wdata),32);
        bufp->chgIData(oldp+24,(vlSelfRef.ysyx_24080018__DOT__mem_wdata),32);
        bufp->chgCData(oldp+25,(vlSelfRef.ysyx_24080018__DOT__alu_cnt),4);
        bufp->chgCData(oldp+26,(vlSelfRef.ysyx_24080018__DOT__ins_cnt),6);
        bufp->chgCData(oldp+27,(vlSelfRef.ysyx_24080018__DOT__idu_csr_cnt),3);
        bufp->chgCData(oldp+28,(vlSelfRef.ysyx_24080018__DOT__exu_csr_cnt),3);
        bufp->chgCData(oldp+29,(vlSelfRef.ysyx_24080018__DOT__pc_cnt),4);
        bufp->chgIData(oldp+30,(vlSelfRef.ysyx_24080018__DOT__rdata1),32);
        bufp->chgIData(oldp+31,(vlSelfRef.ysyx_24080018__DOT__rdata2),32);
        bufp->chgIData(oldp+32,(vlSelfRef.ysyx_24080018__DOT__addr_lsu),32);
        bufp->chgIData(oldp+33,(vlSelfRef.ysyx_24080018__DOT__data_store),32);
        bufp->chgIData(oldp+34,(vlSelfRef.ysyx_24080018__DOT__imm),32);
        bufp->chgSData(oldp+35,(vlSelfRef.ysyx_24080018__DOT__csr_imm),12);
        bufp->chgIData(oldp+36,(vlSelfRef.ysyx_24080018__DOT__csr_data),32);
        bufp->chgBit(oldp+37,(vlSelfRef.ysyx_24080018__DOT__br_taken));
        bufp->chgBit(oldp+38,(vlSelfRef.ysyx_24080018__DOT__auipc));
        bufp->chgBit(oldp+39,(vlSelfRef.ysyx_24080018__DOT__lui));
        bufp->chgBit(oldp+40,(vlSelfRef.ysyx_24080018__DOT__load));
        bufp->chgBit(oldp+41,(vlSelfRef.ysyx_24080018__DOT__jalr));
        bufp->chgBit(oldp+42,(vlSelfRef.ysyx_24080018__DOT__jal));
        bufp->chgBit(oldp+43,(vlSelfRef.ysyx_24080018__DOT__ControlHazard));
        bufp->chgBit(oldp+44,(vlSelfRef.ysyx_24080018__DOT__idu__DOT__cstate));
        bufp->chgBit(oldp+45,(vlSelfRef.ysyx_24080018__DOT__exu_mem_valid));
        bufp->chgBit(oldp+46,(vlSelfRef.ysyx_24080018__DOT__mem_wbu_valid));
        bufp->chgBit(oldp+47,(((IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__cstate) 
                               & (0U != (IData)(vlSelfRef.ysyx_24080018__DOT__idu_csr_cnt)))));
        bufp->chgBit(oldp+48,((1U & (~ (IData)(vlSelfRef.ysyx_24080018__DOT__idu__DOT__cstate)))));
        bufp->chgBit(oldp+49,((1U & (~ (IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__cstate)))));
        bufp->chgBit(oldp+50,((1U & (~ (IData)(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__cstate)))));
        bufp->chgBit(oldp+51,((1U & (~ (IData)(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__cstate)))));
        bufp->chgBit(oldp+52,((1U & (~ (IData)(vlSelfRef.ysyx_24080018__DOT__csr__DOT__cstate)))));
        bufp->chgBit(oldp+53,(vlSelfRef.ysyx_24080018__DOT__wbu_ifu_retire));
        bufp->chgBit(oldp+54,(vlSelfRef.ysyx_24080018__DOT__csr_ifu_retire));
        bufp->chgIData(oldp+55,(((IData)(vlSelfRef.__VdfgRegularize_he50b618e_0_0)
                                  ? vlSelfRef.ysyx_24080018__DOT__mem_wdata
                                  : vlSelfRef.ysyx_24080018__DOT__rdata1)),32);
        bufp->chgBit(oldp+56,((1U & (((vlSelfRef.ysyx_24080018__DOT__ifu__DOT__temp_pc 
                                       != vlSelfRef.ysyx_24080018__DOT__ifu_pc) 
                                      & (0U != vlSelfRef.ysyx_24080018__DOT__ifu__DOT__temp_pc))
                                      ? vlSelfRef.ysyx_24080018__DOT__ifu__DOT__temp_pc
                                      : vlSelfRef.ysyx_24080018__DOT__ifu_pc))));
        bufp->chgBit(oldp+57,((1U & vlSelfRef.ysyx_24080018__DOT__addr_lsu)));
        bufp->chgBit(oldp+58,((1U & (IData)(vlSelfRef.ysyx_24080018__DOT____Vcellout__lsu__o_lsu_size))));
        bufp->chgBit(oldp+59,(vlSelfRef.ysyx_24080018__DOT__io_lsu_wen));
        bufp->chgBit(oldp+60,((1U & VL_SHIFTL_III(1,1,32, vlSelfRef.ysyx_24080018__DOT__data_store, 
                                                  VL_SHIFTL_III(32,32,32, 
                                                                (3U 
                                                                 & vlSelfRef.ysyx_24080018__DOT__addr_lsu), 3U)))));
        bufp->chgBit(oldp+61,((1U & ((1U == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt))
                                      ? ((0U == (3U 
                                                 & vlSelfRef.ysyx_24080018__DOT__addr_lsu))
                                          ? 1U : ((1U 
                                                   == 
                                                   (3U 
                                                    & vlSelfRef.ysyx_24080018__DOT__addr_lsu))
                                                   ? 2U
                                                   : 
                                                  ((2U 
                                                    == 
                                                    (3U 
                                                     & vlSelfRef.ysyx_24080018__DOT__addr_lsu))
                                                    ? 4U
                                                    : 
                                                   ((3U 
                                                     == 
                                                     (3U 
                                                      & vlSelfRef.ysyx_24080018__DOT__addr_lsu))
                                                     ? 8U
                                                     : 0U))))
                                      : ((2U == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt))
                                          ? ((2U & vlSelfRef.ysyx_24080018__DOT__addr_lsu)
                                              ? 0x0cU
                                              : 3U)
                                          : ((3U == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt))
                                              ? 0x0fU
                                              : 0U))))));
        bufp->chgBit(oldp+62,(vlSelfRef.ysyx_24080018__DOT__csr__DOT__cstate));
        bufp->chgIData(oldp+63,(vlSelfRef.ysyx_24080018__DOT__csr__DOT__mcycle),32);
        bufp->chgIData(oldp+64,(vlSelfRef.ysyx_24080018__DOT__csr__DOT__mcycleh),32);
        bufp->chgIData(oldp+65,(vlSelfRef.ysyx_24080018__DOT__csr__DOT__mvendorid),32);
        bufp->chgIData(oldp+66,(vlSelfRef.ysyx_24080018__DOT__csr__DOT__marchid),32);
        bufp->chgBit(oldp+67,(vlSelfRef.ysyx_24080018__DOT__exu__DOT__cstate));
        bufp->chgBit(oldp+68,(((IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__cstate)
                                ? ((IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__cstate) 
                                   & (((IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__SType) 
                                       | (IData)(vlSelfRef.ysyx_24080018__DOT__load))
                                       ? (IData)(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__cstate)
                                       : ((IData)(vlSelfRef.ysyx_24080018__DOT__csr__DOT__cstate) 
                                          & (0U != (IData)(vlSelfRef.ysyx_24080018__DOT__idu_csr_cnt)))))
                                : (IData)(vlSelfRef.ysyx_24080018__DOT__idu__DOT__cstate))));
        bufp->chgBit(oldp+69,(vlSelfRef.ysyx_24080018__DOT__exu__DOT__UType));
        bufp->chgBit(oldp+70,(vlSelfRef.ysyx_24080018__DOT__exu__DOT__JType));
        bufp->chgBit(oldp+71,(vlSelfRef.ysyx_24080018__DOT__exu__DOT__BType));
        bufp->chgBit(oldp+72,(vlSelfRef.ysyx_24080018__DOT__exu__DOT__IType));
        bufp->chgBit(oldp+73,(vlSelfRef.ysyx_24080018__DOT__exu__DOT__SType));
        bufp->chgBit(oldp+74,(vlSelfRef.ysyx_24080018__DOT__exu__DOT__RType));
        bufp->chgIData(oldp+75,(vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_a),32);
        bufp->chgIData(oldp+76,(vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_b),32);
        bufp->chgQData(oldp+77,(((((QData)((IData)(
                                                   (- (IData)(
                                                              (vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_a 
                                                               >> 0x0000001fU))))) 
                                   << 0x00000020U) 
                                  | (QData)((IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_a))) 
                                 >> (0x0000001fU & vlSelfRef.ysyx_24080018__DOT__exu__DOT__alu_b))),64);
        bufp->chgBit(oldp+79,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__cstate));
        bufp->chgIData(oldp+80,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[0]),32);
        bufp->chgIData(oldp+81,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[1]),32);
        bufp->chgIData(oldp+82,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[2]),32);
        bufp->chgIData(oldp+83,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[3]),32);
        bufp->chgIData(oldp+84,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[4]),32);
        bufp->chgIData(oldp+85,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[5]),32);
        bufp->chgIData(oldp+86,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[6]),32);
        bufp->chgIData(oldp+87,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[7]),32);
        bufp->chgIData(oldp+88,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[8]),32);
        bufp->chgIData(oldp+89,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[9]),32);
        bufp->chgIData(oldp+90,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[10]),32);
        bufp->chgIData(oldp+91,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[11]),32);
        bufp->chgIData(oldp+92,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[12]),32);
        bufp->chgIData(oldp+93,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[13]),32);
        bufp->chgIData(oldp+94,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[14]),32);
        bufp->chgIData(oldp+95,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[15]),32);
        bufp->chgIData(oldp+96,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[16]),32);
        bufp->chgIData(oldp+97,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[17]),32);
        bufp->chgIData(oldp+98,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[18]),32);
        bufp->chgIData(oldp+99,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[19]),32);
        bufp->chgIData(oldp+100,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[20]),32);
        bufp->chgIData(oldp+101,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[21]),32);
        bufp->chgIData(oldp+102,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[22]),32);
        bufp->chgIData(oldp+103,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[23]),32);
        bufp->chgIData(oldp+104,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[24]),32);
        bufp->chgIData(oldp+105,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[25]),32);
        bufp->chgIData(oldp+106,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[26]),32);
        bufp->chgIData(oldp+107,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[27]),32);
        bufp->chgIData(oldp+108,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[28]),32);
        bufp->chgIData(oldp+109,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[29]),32);
        bufp->chgIData(oldp+110,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[30]),32);
        bufp->chgIData(oldp+111,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__rf[31]),32);
        bufp->chgBit(oldp+112,(((IData)(vlSelfRef.ysyx_24080018__DOT__mem_wbu_cnt) 
                                & (IData)(vlSelfRef.ysyx_24080018__DOT__mem_wbu_valid))));
        bufp->chgIData(oldp+113,(vlSelfRef.ysyx_24080018__DOT__gpr__DOT__unnamedblk1__DOT__i),32);
        bufp->chgBit(oldp+114,(((IData)(vlSelfRef.ysyx_24080018__DOT__idu__DOT__cstate)
                                 ? ((IData)(vlSelfRef.ysyx_24080018__DOT__idu__DOT__cstate) 
                                    & ((~ (IData)(vlSelfRef.ysyx_24080018__DOT__ControlHazard)) 
                                       & (IData)(vlSelfRef.ysyx_24080018__DOT__exu__DOT__cstate)))
                                 : ((~ (IData)(vlSelfRef.ysyx_24080018__DOT__ControlHazard)) 
                                    & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_respValid)))));
        bufp->chgIData(oldp+115,((((vlSelfRef.ysyx_24080018__DOT__ifu__DOT__temp_pc 
                                    != vlSelfRef.ysyx_24080018__DOT__ifu_pc) 
                                   & (0U != vlSelfRef.ysyx_24080018__DOT__ifu__DOT__temp_pc))
                                   ? vlSelfRef.ysyx_24080018__DOT__ifu__DOT__temp_pc
                                   : vlSelfRef.ysyx_24080018__DOT__ifu_pc)),32);
        bufp->chgBit(oldp+116,((8U == (IData)(vlSelfRef.ysyx_24080018__DOT__pc_cnt))));
        bufp->chgBit(oldp+117,((7U == (IData)(vlSelfRef.ysyx_24080018__DOT__pc_cnt))));
        bufp->chgBit(oldp+118,(vlSelfRef.ysyx_24080018__DOT__ifu__DOT__bxx));
        bufp->chgIData(oldp+119,(vlSelfRef.ysyx_24080018__DOT__ifu__DOT__target_pc),32);
        bufp->chgBit(oldp+120,(vlSelfRef.ysyx_24080018__DOT__ifu__DOT__retire));
        bufp->chgBit(oldp+121,(vlSelfRef.ysyx_24080018__DOT__ifu__DOT__cstate));
        bufp->chgBit(oldp+122,(((IData)(vlSelfRef.ysyx_24080018__DOT__ifu__DOT__cstate)
                                 ? ((IData)(vlSelfRef.ysyx_24080018__DOT__ifu__DOT__cstate) 
                                    & ((IData)(vlSelfRef.ysyx_24080018__DOT__ControlHazard) 
                                       | ((~ (IData)(vlSelfRef.ysyx_24080018__DOT__ifu__DOT__retire)) 
                                          | (vlSelfRef.ysyx_24080018__DOT__ifu__DOT__target_pc 
                                             == vlSelfRef.ysyx_24080018__DOT__ifu_pc))))
                                 : ((~ (IData)(vlSelfRef.ysyx_24080018__DOT__ControlHazard)) 
                                    & ((vlSelfRef.ysyx_24080018__DOT__ifu__DOT__target_pc 
                                        != vlSelfRef.ysyx_24080018__DOT__ifu_pc) 
                                       & (IData)(vlSelfRef.ysyx_24080018__DOT__io_ifu_respValid))))));
        bufp->chgIData(oldp+123,(vlSelfRef.ysyx_24080018__DOT__ifu__DOT__temp_pc),32);
        bufp->chgBit(oldp+124,(vlSelfRef.ysyx_24080018__DOT__ifu__DOT__prev_idle));
        bufp->chgCData(oldp+125,(vlSelfRef.ysyx_24080018__DOT____Vcellout__lsu__o_lsu_size),2);
        bufp->chgIData(oldp+126,(VL_SHIFTL_III(32,32,32, vlSelfRef.ysyx_24080018__DOT__data_store, 
                                               VL_SHIFTL_III(32,32,32, 
                                                             (3U 
                                                              & vlSelfRef.ysyx_24080018__DOT__addr_lsu), 3U))),32);
        bufp->chgCData(oldp+127,(((1U == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt))
                                   ? ((0U == (3U & vlSelfRef.ysyx_24080018__DOT__addr_lsu))
                                       ? 1U : ((1U 
                                                == 
                                                (3U 
                                                 & vlSelfRef.ysyx_24080018__DOT__addr_lsu))
                                                ? 2U
                                                : (
                                                   (2U 
                                                    == 
                                                    (3U 
                                                     & vlSelfRef.ysyx_24080018__DOT__addr_lsu))
                                                    ? 4U
                                                    : 
                                                   ((3U 
                                                     == 
                                                     (3U 
                                                      & vlSelfRef.ysyx_24080018__DOT__addr_lsu))
                                                     ? 8U
                                                     : 0U))))
                                   : ((2U == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt))
                                       ? ((2U & vlSelfRef.ysyx_24080018__DOT__addr_lsu)
                                           ? 0x0cU : 3U)
                                       : ((3U == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt))
                                           ? 0x0fU : 0U)))),4);
        bufp->chgBit(oldp+128,(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__cstate));
        bufp->chgBit(oldp+129,(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__nstate));
        bufp->chgIData(oldp+130,(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__temp),32);
        bufp->chgIData(oldp+131,(((4U == (IData)(vlSelfRef.ysyx_24080018__DOT__exu_lsu_cnt))
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
        bufp->chgBit(oldp+132,(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__load));
        bufp->chgCData(oldp+133,(((2U & vlSelfRef.ysyx_24080018__DOT__addr_lsu)
                                   ? 0x0cU : 3U)),4);
        bufp->chgCData(oldp+134,(((0U == (3U & vlSelfRef.ysyx_24080018__DOT__addr_lsu))
                                   ? 1U : ((1U == (3U 
                                                   & vlSelfRef.ysyx_24080018__DOT__addr_lsu))
                                            ? 2U : 
                                           ((2U == 
                                             (3U & vlSelfRef.ysyx_24080018__DOT__addr_lsu))
                                             ? 4U : 
                                            ((3U == 
                                              (3U & vlSelfRef.ysyx_24080018__DOT__addr_lsu))
                                              ? 8U : 0U))))),4);
        bufp->chgCData(oldp+135,(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__byte_sel),8);
        bufp->chgSData(oldp+136,(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__half_sel),16);
    }
    bufp->chgBit(oldp+137,(vlSelfRef.clock));
    bufp->chgBit(oldp+138,(vlSelfRef.reset));
    bufp->chgBit(oldp+139,(vlSelfRef.io_interrupt));
    bufp->chgBit(oldp+140,(vlSelfRef.io_master_awready));
    bufp->chgBit(oldp+141,(vlSelfRef.io_master_awvalid));
    bufp->chgIData(oldp+142,(vlSelfRef.io_master_awaddr),32);
    bufp->chgCData(oldp+143,(vlSelfRef.io_master_awid),4);
    bufp->chgCData(oldp+144,(vlSelfRef.io_master_awlen),8);
    bufp->chgCData(oldp+145,(vlSelfRef.io_master_awsize),3);
    bufp->chgCData(oldp+146,(vlSelfRef.io_master_awburst),2);
    bufp->chgBit(oldp+147,(vlSelfRef.io_master_wready));
    bufp->chgBit(oldp+148,(vlSelfRef.io_master_wvalid));
    bufp->chgIData(oldp+149,(vlSelfRef.io_master_wdata),32);
    bufp->chgCData(oldp+150,(vlSelfRef.io_master_wstrb),4);
    bufp->chgBit(oldp+151,(vlSelfRef.io_master_wlast));
    bufp->chgBit(oldp+152,(vlSelfRef.io_master_bready));
    bufp->chgBit(oldp+153,(vlSelfRef.io_master_bvalid));
    bufp->chgCData(oldp+154,(vlSelfRef.io_master_bresp),2);
    bufp->chgCData(oldp+155,(vlSelfRef.io_master_bid),4);
    bufp->chgBit(oldp+156,(vlSelfRef.io_master_arready));
    bufp->chgBit(oldp+157,(vlSelfRef.io_master_arvalid));
    bufp->chgIData(oldp+158,(vlSelfRef.io_master_araddr),32);
    bufp->chgCData(oldp+159,(vlSelfRef.io_master_arid),4);
    bufp->chgCData(oldp+160,(vlSelfRef.io_master_arlen),8);
    bufp->chgCData(oldp+161,(vlSelfRef.io_master_srsize),3);
    bufp->chgCData(oldp+162,(vlSelfRef.io_master_arburst),2);
    bufp->chgBit(oldp+163,(vlSelfRef.io_master_rready));
    bufp->chgBit(oldp+164,(vlSelfRef.io_master_rvalid));
    bufp->chgCData(oldp+165,(vlSelfRef.io_master_rresp),2);
    bufp->chgIData(oldp+166,(vlSelfRef.io_master_rdata),32);
    bufp->chgBit(oldp+167,(vlSelfRef.io_master_rlast));
    bufp->chgCData(oldp+168,(vlSelfRef.io_master_rid),4);
    bufp->chgBit(oldp+169,(vlSelfRef.io_slave_awready));
    bufp->chgBit(oldp+170,(vlSelfRef.io_slave_awvalid));
    bufp->chgIData(oldp+171,(vlSelfRef.io_slave_awaddr),32);
    bufp->chgCData(oldp+172,(vlSelfRef.io_slave_awid),4);
    bufp->chgCData(oldp+173,(vlSelfRef.io_slave_awlen),8);
    bufp->chgCData(oldp+174,(vlSelfRef.io_slave_awsize),3);
    bufp->chgCData(oldp+175,(vlSelfRef.io_slave_awburst),2);
    bufp->chgBit(oldp+176,(vlSelfRef.io_slave_wready));
    bufp->chgBit(oldp+177,(vlSelfRef.io_slave_wvalid));
    bufp->chgIData(oldp+178,(vlSelfRef.io_slave_wdata),32);
    bufp->chgCData(oldp+179,(vlSelfRef.io_slave_wstrb),4);
    bufp->chgBit(oldp+180,(vlSelfRef.io_slave_wlast));
    bufp->chgBit(oldp+181,(vlSelfRef.io_slave_bready));
    bufp->chgBit(oldp+182,(vlSelfRef.io_slave_bvalid));
    bufp->chgCData(oldp+183,(vlSelfRef.io_slave_bresp),2);
    bufp->chgCData(oldp+184,(vlSelfRef.io_slave_bid),4);
    bufp->chgBit(oldp+185,(vlSelfRef.io_slave_arready));
    bufp->chgBit(oldp+186,(vlSelfRef.io_slave_arvalid));
    bufp->chgIData(oldp+187,(vlSelfRef.io_slave_araddr),32);
    bufp->chgCData(oldp+188,(vlSelfRef.io_slave_arid),4);
    bufp->chgCData(oldp+189,(vlSelfRef.io_slave_arlen),8);
    bufp->chgCData(oldp+190,(vlSelfRef.io_slave_srsize),3);
    bufp->chgCData(oldp+191,(vlSelfRef.io_slave_arburst),2);
    bufp->chgBit(oldp+192,(vlSelfRef.io_slave_rready));
    bufp->chgBit(oldp+193,(vlSelfRef.io_slave_rvalid));
    bufp->chgCData(oldp+194,(vlSelfRef.io_slave_rresp),2);
    bufp->chgIData(oldp+195,(vlSelfRef.io_slave_rdata),32);
    bufp->chgBit(oldp+196,(vlSelfRef.io_slave_rlast));
    bufp->chgCData(oldp+197,(vlSelfRef.io_slave_rid),4);
    bufp->chgBit(oldp+198,((1U & ((~ (IData)(vlSelfRef.reset)) 
                                  & (~ ((IData)(vlSelfRef.ysyx_24080018__DOT__ifu__DOT__cstate) 
                                        | ((IData)(vlSelfRef.ysyx_24080018__DOT__ControlHazard) 
                                           | (IData)(vlSelfRef.ysyx_24080018__DOT__ifu__DOT__prev_idle))))))));
    bufp->chgBit(oldp+199,(((~ (IData)(vlSelfRef.reset)) 
                            & ((IData)(vlSelfRef.ysyx_24080018__DOT__exu_mem_valid) 
                               & ((~ (IData)(vlSelfRef.ysyx_24080018__DOT__lsu__DOT__cstate)) 
                                  & (IData)(vlSelfRef.ysyx_24080018__DOT__lsu__DOT____VdfgRegularize_h02661d78_0_8))))));
}

void Vysyx_24080018___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_24080018___024root__trace_cleanup\n"); );
    // Body
    Vysyx_24080018___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_24080018___024root*>(voidSelf);
    Vysyx_24080018__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
