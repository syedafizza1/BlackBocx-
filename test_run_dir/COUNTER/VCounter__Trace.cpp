// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VCounter__Syms.h"


//======================

void VCounter::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VCounter* t = (VCounter*)userthis;
    VCounter__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void VCounter::traceChgThis(VCounter__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VCounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 1U))))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        if (VL_UNLIKELY((4U & vlTOPp->__Vm_traceActivity))) {
            vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VCounter::traceChgThis__2(VCounter__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VCounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+1,(vlTOPp->Counter__DOT__a_clk));
    }
}

void VCounter::traceChgThis__3(VCounter__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VCounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+9,(vlTOPp->Counter__DOT__a__DOT__counter_up),4);
    }
}

void VCounter::traceChgThis__4(VCounter__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VCounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+17,(vlTOPp->clock));
        vcdp->chgBit(c+25,(vlTOPp->reset));
        vcdp->chgBus(c+33,(vlTOPp->io_output),4);
    }
}
