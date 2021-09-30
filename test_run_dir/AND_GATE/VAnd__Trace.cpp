// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VAnd__Syms.h"


//======================

void VAnd::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VAnd* t = (VAnd*)userthis;
    VAnd__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void VAnd::traceChgThis(VAnd__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAnd* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VAnd::traceChgThis__2(VAnd__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAnd* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+1,(vlTOPp->clock));
        vcdp->chgBit(c+9,(vlTOPp->reset));
        vcdp->chgBit(c+17,(vlTOPp->io_A));
        vcdp->chgBit(c+25,(vlTOPp->io_B));
        vcdp->chgBit(c+33,(vlTOPp->io_Y));
        vcdp->chgBit(c+41,(((IData)(vlTOPp->io_A) & (IData)(vlTOPp->io_B))));
    }
}
