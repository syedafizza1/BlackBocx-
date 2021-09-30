// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VAlu__Syms.h"


//======================

void VAlu::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VAlu* t = (VAlu*)userthis;
    VAlu__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void VAlu::traceChgThis(VAlu__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAlu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
                               | (vlTOPp->__Vm_traceActivity 
                                  >> 1U))))) {
            vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
        }
        vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VAlu::traceChgThis__2(VAlu__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAlu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBus(c+1,(vlTOPp->Alu__DOT__a__DOT__ALU_Result),8);
    }
}

void VAlu::traceChgThis__3(VAlu__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAlu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+9,(vlTOPp->clock));
        vcdp->chgBit(c+17,(vlTOPp->reset));
        vcdp->chgBus(c+25,(vlTOPp->io_A),8);
        vcdp->chgBus(c+33,(vlTOPp->io_B),8);
        vcdp->chgBus(c+41,(vlTOPp->io_ALU_Sel),4);
        vcdp->chgBus(c+49,(vlTOPp->io_ALU_Out),8);
        vcdp->chgBit(c+57,(vlTOPp->io_CarryOut));
        vcdp->chgBit(c+65,((1U & (((IData)(vlTOPp->io_A) 
                                   + (IData)(vlTOPp->io_B)) 
                                  >> 8U))));
        vcdp->chgBus(c+73,((0x1ffU & ((IData)(vlTOPp->io_A) 
                                      + (IData)(vlTOPp->io_B)))),9);
    }
}
