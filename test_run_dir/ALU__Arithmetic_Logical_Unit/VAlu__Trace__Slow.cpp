// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VAlu__Syms.h"


//======================

void VAlu::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&VAlu::traceInit, &VAlu::traceFull, &VAlu::traceChg, this);
}
void VAlu::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VAlu* t = (VAlu*)userthis;
    VAlu__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VAlu::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VAlu* t = (VAlu*)userthis;
    VAlu__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void VAlu::traceInitThis(VAlu__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAlu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VAlu::traceFullThis(VAlu__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAlu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VAlu::traceInitThis__1(VAlu__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAlu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+9,"clock", false,-1);
        vcdp->declBit(c+17,"reset", false,-1);
        vcdp->declBus(c+25,"io_A", false,-1, 7,0);
        vcdp->declBus(c+33,"io_B", false,-1, 7,0);
        vcdp->declBus(c+41,"io_ALU_Sel", false,-1, 3,0);
        vcdp->declBus(c+49,"io_ALU_Out", false,-1, 7,0);
        vcdp->declBit(c+57,"io_CarryOut", false,-1);
        vcdp->declBit(c+9,"Alu clock", false,-1);
        vcdp->declBit(c+17,"Alu reset", false,-1);
        vcdp->declBus(c+25,"Alu io_A", false,-1, 7,0);
        vcdp->declBus(c+33,"Alu io_B", false,-1, 7,0);
        vcdp->declBus(c+41,"Alu io_ALU_Sel", false,-1, 3,0);
        vcdp->declBus(c+49,"Alu io_ALU_Out", false,-1, 7,0);
        vcdp->declBit(c+57,"Alu io_CarryOut", false,-1);
        vcdp->declBus(c+25,"Alu a_A", false,-1, 7,0);
        vcdp->declBus(c+33,"Alu a_B", false,-1, 7,0);
        vcdp->declBus(c+41,"Alu a_ALU_Sel", false,-1, 3,0);
        vcdp->declBus(c+1,"Alu a_ALU_Out", false,-1, 7,0);
        vcdp->declBit(c+65,"Alu a_CarryOut", false,-1);
        vcdp->declBus(c+25,"Alu a A", false,-1, 7,0);
        vcdp->declBus(c+33,"Alu a B", false,-1, 7,0);
        vcdp->declBus(c+41,"Alu a ALU_Sel", false,-1, 3,0);
        vcdp->declBus(c+1,"Alu a ALU_Out", false,-1, 7,0);
        vcdp->declBit(c+65,"Alu a CarryOut", false,-1);
        vcdp->declBus(c+1,"Alu a ALU_Result", false,-1, 7,0);
        vcdp->declBus(c+73,"Alu a tmp", false,-1, 8,0);
    }
}

void VAlu::traceFullThis__1(VAlu__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VAlu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBus(c+1,(vlTOPp->Alu__DOT__a__DOT__ALU_Result),8);
        vcdp->fullBit(c+9,(vlTOPp->clock));
        vcdp->fullBit(c+17,(vlTOPp->reset));
        vcdp->fullBus(c+25,(vlTOPp->io_A),8);
        vcdp->fullBus(c+33,(vlTOPp->io_B),8);
        vcdp->fullBus(c+41,(vlTOPp->io_ALU_Sel),4);
        vcdp->fullBus(c+49,(vlTOPp->io_ALU_Out),8);
        vcdp->fullBit(c+57,(vlTOPp->io_CarryOut));
        vcdp->fullBit(c+65,((1U & (((IData)(vlTOPp->io_A) 
                                    + (IData)(vlTOPp->io_B)) 
                                   >> 8U))));
        vcdp->fullBus(c+73,((0x1ffU & ((IData)(vlTOPp->io_A) 
                                       + (IData)(vlTOPp->io_B)))),9);
    }
}
