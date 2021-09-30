// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VCounter__Syms.h"


//======================

void VCounter::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&VCounter::traceInit, &VCounter::traceFull, &VCounter::traceChg, this);
}
void VCounter::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VCounter* t = (VCounter*)userthis;
    VCounter__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VCounter::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VCounter* t = (VCounter*)userthis;
    VCounter__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void VCounter::traceInitThis(VCounter__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VCounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VCounter::traceFullThis(VCounter__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VCounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VCounter::traceInitThis__1(VCounter__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VCounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+17,"clock", false,-1);
        vcdp->declBit(c+25,"reset", false,-1);
        vcdp->declBus(c+33,"io_output", false,-1, 3,0);
        vcdp->declBit(c+17,"Counter clock", false,-1);
        vcdp->declBit(c+25,"Counter reset", false,-1);
        vcdp->declBus(c+33,"Counter io_output", false,-1, 3,0);
        vcdp->declBit(c+1,"Counter a_clk", false,-1);
        vcdp->declBit(c+25,"Counter a_reset", false,-1);
        vcdp->declBus(c+9,"Counter a_counter", false,-1, 3,0);
        vcdp->declBit(c+1,"Counter a clk", false,-1);
        vcdp->declBit(c+25,"Counter a reset", false,-1);
        vcdp->declBus(c+9,"Counter a counter", false,-1, 3,0);
        vcdp->declBus(c+9,"Counter a counter_up", false,-1, 3,0);
    }
}

void VCounter::traceFullThis__1(VCounter__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VCounter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBit(c+1,(vlTOPp->Counter__DOT__a_clk));
        vcdp->fullBus(c+9,(vlTOPp->Counter__DOT__a__DOT__counter_up),4);
        vcdp->fullBit(c+17,(vlTOPp->clock));
        vcdp->fullBit(c+25,(vlTOPp->reset));
        vcdp->fullBus(c+33,(vlTOPp->io_output),4);
    }
}
