// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_24080018.h for the primary calling header

#include "Vysyx_24080018__pch.h"

extern "C" void NPCTRAP(unsigned int pc, int x10);

void Vysyx_24080018___024unit____Vdpiimwrap_NPCTRAP_TOP____024unit(IData/*31:0*/ pc, IData/*31:0*/ x10) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vysyx_24080018___024unit____Vdpiimwrap_NPCTRAP_TOP____024unit\n"); );
    // Body
    unsigned int pc__Vcvt;
    pc__Vcvt = pc;
    int x10__Vcvt;
    x10__Vcvt = x10;
    NPCTRAP(pc__Vcvt, x10__Vcvt);
}

extern "C" void pmem_write(unsigned int addr, unsigned int data, int size);

void Vysyx_24080018___024unit____Vdpiimwrap_pmem_write_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ data, IData/*31:0*/ size) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vysyx_24080018___024unit____Vdpiimwrap_pmem_write_TOP____024unit\n"); );
    // Body
    unsigned int addr__Vcvt;
    addr__Vcvt = addr;
    unsigned int data__Vcvt;
    data__Vcvt = data;
    int size__Vcvt;
    size__Vcvt = size;
    pmem_write(addr__Vcvt, data__Vcvt, size__Vcvt);
}

extern "C" unsigned int pmem_read(unsigned int addr, int size);

void Vysyx_24080018___024unit____Vdpiimwrap_pmem_read_TOP____024unit(IData/*31:0*/ addr, IData/*31:0*/ size, IData/*31:0*/ &pmem_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vysyx_24080018___024unit____Vdpiimwrap_pmem_read_TOP____024unit\n"); );
    // Body
    unsigned int addr__Vcvt;
    addr__Vcvt = addr;
    int size__Vcvt;
    size__Vcvt = size;
    unsigned int pmem_read__Vfuncrtn__Vcvt;
    pmem_read__Vfuncrtn__Vcvt = pmem_read(addr__Vcvt, size__Vcvt);
    pmem_read__Vfuncrtn = (pmem_read__Vfuncrtn__Vcvt);
}
