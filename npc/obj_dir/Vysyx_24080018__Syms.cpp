// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vysyx_24080018__pch.h"
#include "Vysyx_24080018.h"
#include "Vysyx_24080018___024root.h"
#include "Vysyx_24080018___024unit.h"

// FUNCTIONS
Vysyx_24080018__Syms::~Vysyx_24080018__Syms()
{
}

Vysyx_24080018__Syms::Vysyx_24080018__Syms(VerilatedContext* contextp, const char* namep, Vysyx_24080018* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP____024unit{this, Verilated::catName(namep, "$unit")}
{
    // Check resources
    Verilated::stackCheck(272);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-9);
    // Setup each module's pointers to their submodules
    TOP.__PVT____024unit = &TOP____024unit;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP____024unit.__Vconfigure(true);
    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
    }
}
