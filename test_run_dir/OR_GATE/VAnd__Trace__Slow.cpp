// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VAnd__Syms.h"


//======================

void VAnd::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&VAnd::traceInit, &VAnd::traceFull, &VAnd::traceChg, this);
}
void VAnd::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VAnd* t = (VAnd*)userthis;
    VAnd__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VAnd::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VAnd* t = (VAnd*)userthis;
    VAnd__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void VAnd::traceInitThis(VAnd__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAnd* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VAnd::traceFullThis(VAnd__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAnd* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VAnd::traceInitThis__1(VAnd__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAnd* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+1,"clock", false,-1);
        vcdp->declBit(c+9,"reset", false,-1);
        vcdp->declBit(c+17,"io_A", false,-1);
        vcdp->declBit(c+25,"io_B", false,-1);
        vcdp->declBit(c+33,"io_Y", false,-1);
        vcdp->declBit(c+1,"And clock", false,-1);
        vcdp->declBit(c+9,"And reset", false,-1);
        vcdp->declBit(c+17,"And io_A", false,-1);
        vcdp->declBit(c+25,"And io_B", false,-1);
        vcdp->declBit(c+33,"And io_Y", false,-1);
        vcdp->declBit(c+17,"And a_A", false,-1);
        vcdp->declBit(c+25,"And a_B", false,-1);
        vcdp->declBit(c+41,"And a_Y", false,-1);
        vcdp->declBit(c+41,"And a Y", false,-1);
        vcdp->declBit(c+17,"And a A", false,-1);
        vcdp->declBit(c+25,"And a B", false,-1);
    }
}

void VAnd::traceFullThis__1(VAnd__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAnd* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBit(c+1,(vlTOPp->clock));
        vcdp->fullBit(c+9,(vlTOPp->reset));
        vcdp->fullBit(c+17,(vlTOPp->io_A));
        vcdp->fullBit(c+25,(vlTOPp->io_B));
        vcdp->fullBit(c+33,(vlTOPp->io_Y));
        vcdp->fullBit(c+41,(((IData)(vlTOPp->io_A) 
                             & (IData)(vlTOPp->io_B))));
    }
}
