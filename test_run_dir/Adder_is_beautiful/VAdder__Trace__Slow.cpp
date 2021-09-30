// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VAdder__Syms.h"


//======================

void VAdder::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&VAdder::traceInit, &VAdder::traceFull, &VAdder::traceChg, this);
}
void VAdder::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VAdder* t = (VAdder*)userthis;
    VAdder__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VAdder::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VAdder* t = (VAdder*)userthis;
    VAdder__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void VAdder::traceInitThis(VAdder__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAdder* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VAdder::traceFullThis(VAdder__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAdder* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VAdder::traceInitThis__1(VAdder__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAdder* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+1,"clock", false,-1);
        vcdp->declBit(c+9,"reset", false,-1);
        vcdp->declBus(c+17,"io_a", false,-1, 3,0);
        vcdp->declBus(c+25,"io_b", false,-1, 3,0);
        vcdp->declBus(c+33,"io_sum", false,-1, 3,0);
        vcdp->declBit(c+1,"Adder clock", false,-1);
        vcdp->declBit(c+9,"Adder reset", false,-1);
        vcdp->declBus(c+17,"Adder io_a", false,-1, 3,0);
        vcdp->declBus(c+25,"Adder io_b", false,-1, 3,0);
        vcdp->declBus(c+33,"Adder io_sum", false,-1, 3,0);
        vcdp->declBus(c+17,"Adder a_a", false,-1, 3,0);
        vcdp->declBus(c+25,"Adder a_b", false,-1, 3,0);
        vcdp->declBus(c+41,"Adder a_sum", false,-1, 3,0);
        vcdp->declBus(c+17,"Adder a a", false,-1, 3,0);
        vcdp->declBus(c+25,"Adder a b", false,-1, 3,0);
        vcdp->declBus(c+41,"Adder a sum", false,-1, 3,0);
    }
}

void VAdder::traceFullThis__1(VAdder__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAdder* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBit(c+1,(vlTOPp->clock));
        vcdp->fullBit(c+9,(vlTOPp->reset));
        vcdp->fullBus(c+17,(vlTOPp->io_a),4);
        vcdp->fullBus(c+25,(vlTOPp->io_b),4);
        vcdp->fullBus(c+33,(vlTOPp->io_sum),4);
        vcdp->fullBus(c+41,((0xfU & ((IData)(vlTOPp->io_a) 
                                     + (IData)(vlTOPp->io_b)))),4);
    }
}
