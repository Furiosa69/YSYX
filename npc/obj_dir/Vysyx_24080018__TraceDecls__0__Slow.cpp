// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing declarations
#include "verilated_fst_c.h"


void Vysyx_24080018___024root__traceDeclTypesSub0(VerilatedFst* tracep) {
    {
        const char* __VenumItemNames[]
        = {"IDLE", "IFU_RD", "LSU_WR", "LSU_RD", "RESP"};
        const char* __VenumItemValues[]
        = {"1", "10", "11", "100", "101"};
        tracep->declDTypeEnum(1, "ysyx_24080018_arbiter.state_e", 5, 3, __VenumItemNames, __VenumItemValues);
    }
}

void Vysyx_24080018___024root__trace_decl_types(VerilatedFst* tracep) {
    Vysyx_24080018___024root__traceDeclTypesSub0(tracep);
}
