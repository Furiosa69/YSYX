// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VYSYX_24080018__DPI_H_
#define VERILATED_VYSYX_24080018__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at /home/furiosa/Projects/MyCode/ysyx-workbench/npc/vsrc/top.v:1:30
    extern void NPCTRAP(unsigned int pc, int x10);
    // DPI import at /home/furiosa/Projects/MyCode/ysyx-workbench/npc/vsrc/top.v:3:38
    extern unsigned int pmem_read(unsigned int addr, int size);
    // DPI import at /home/furiosa/Projects/MyCode/ysyx-workbench/npc/vsrc/top.v:2:30
    extern void pmem_write(unsigned int addr, unsigned int data, int size);

#ifdef __cplusplus
}
#endif

#endif  // guard
