// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vysyx_24080018.h for the primary calling header

#ifndef VERILATED_VYSYX_24080018___024UNIT_H_
#define VERILATED_VYSYX_24080018___024UNIT_H_  // guard

#include "verilated.h"


class Vysyx_24080018__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vysyx_24080018___024unit final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vysyx_24080018__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vysyx_24080018___024unit(Vysyx_24080018__Syms* symsp, const char* v__name);
    ~Vysyx_24080018___024unit();
    VL_UNCOPYABLE(Vysyx_24080018___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
