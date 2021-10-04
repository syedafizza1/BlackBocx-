// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VSRam__Syms.h"


//======================

void VSRam::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VSRam* t = (VSRam*)userthis;
    VSRam__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void VSRam::traceChgThis(VSRam__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VSRam* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void VSRam::traceChgThis__2(VSRam__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VSRam* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+1,(vlTOPp->SRam__DOT__a_clk0));
    }
}

void VSRam::traceChgThis__3(VSRam__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VSRam* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+9,(vlTOPp->SRam__DOT__a_dout0),32);
        vcdp->chgBit(c+17,(vlTOPp->SRam__DOT__a__DOT__csb0_reg));
        vcdp->chgBit(c+25,(vlTOPp->SRam__DOT__a__DOT__web0_reg));
        vcdp->chgBus(c+33,(vlTOPp->SRam__DOT__a__DOT__addr0_reg),7);
        vcdp->chgBus(c+41,(vlTOPp->SRam__DOT__a__DOT__din0_reg),32);
    }
}

void VSRam::traceChgThis__4(VSRam__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VSRam* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+49,(vlTOPp->clock));
        vcdp->chgBit(c+57,(vlTOPp->reset));
        vcdp->chgBit(c+65,(vlTOPp->io_clk0));
        vcdp->chgBit(c+73,(vlTOPp->io_csb0));
        vcdp->chgBit(c+81,(vlTOPp->io_web0));
        vcdp->chgBus(c+89,(vlTOPp->io_addr0),7);
        vcdp->chgBus(c+97,(vlTOPp->io_din0),32);
        vcdp->chgBus(c+105,(vlTOPp->io_dout0),32);
    }
}
