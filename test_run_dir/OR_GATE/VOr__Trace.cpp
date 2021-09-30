// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VOr__Syms.h"


//======================

void VOr::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VOr* t = (VOr*)userthis;
    VOr__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void VOr::traceChgThis(VOr__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VOr* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VOr::traceChgThis__2(VOr__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VOr* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+1,(vlTOPp->clock));
        vcdp->chgBit(c+9,(vlTOPp->reset));
        vcdp->chgBit(c+17,(vlTOPp->io_A));
        vcdp->chgBit(c+25,(vlTOPp->io_B));
        vcdp->chgBit(c+33,(vlTOPp->io_Y));
        vcdp->chgBit(c+41,(((IData)(vlTOPp->io_A) | (IData)(vlTOPp->io_B))));
    }
}
