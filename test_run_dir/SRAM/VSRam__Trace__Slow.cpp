// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VSRam__Syms.h"


//======================

void VSRam::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&VSRam::traceInit, &VSRam::traceFull, &VSRam::traceChg, this);
}
void VSRam::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VSRam* t = (VSRam*)userthis;
    VSRam__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VSRam::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VSRam* t = (VSRam*)userthis;
    VSRam__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void VSRam::traceInitThis(VSRam__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VSRam* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VSRam::traceFullThis(VSRam__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VSRam* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VSRam::traceInitThis__1(VSRam__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VSRam* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+49,"clock", false,-1);
        vcdp->declBit(c+57,"reset", false,-1);
        vcdp->declBit(c+65,"io_clk0", false,-1);
        vcdp->declBit(c+73,"io_csb0", false,-1);
        vcdp->declBit(c+81,"io_web0", false,-1);
        vcdp->declBus(c+89,"io_addr0", false,-1, 6,0);
        vcdp->declBus(c+97,"io_din0", false,-1, 31,0);
        vcdp->declBus(c+105,"io_dout0", false,-1, 31,0);
        vcdp->declBit(c+49,"SRam clock", false,-1);
        vcdp->declBit(c+57,"SRam reset", false,-1);
        vcdp->declBit(c+65,"SRam io_clk0", false,-1);
        vcdp->declBit(c+73,"SRam io_csb0", false,-1);
        vcdp->declBit(c+81,"SRam io_web0", false,-1);
        vcdp->declBus(c+89,"SRam io_addr0", false,-1, 6,0);
        vcdp->declBus(c+97,"SRam io_din0", false,-1, 31,0);
        vcdp->declBus(c+105,"SRam io_dout0", false,-1, 31,0);
        vcdp->declBit(c+1,"SRam a_clk0", false,-1);
        vcdp->declBit(c+73,"SRam a_csb0", false,-1);
        vcdp->declBit(c+81,"SRam a_web0", false,-1);
        vcdp->declBus(c+89,"SRam a_addr0", false,-1, 6,0);
        vcdp->declBus(c+97,"SRam a_din0", false,-1, 31,0);
        vcdp->declBus(c+9,"SRam a_dout0", false,-1, 31,0);
        vcdp->declBus(c+113,"SRam a DATA_WIDTH", false,-1, 31,0);
        vcdp->declBus(c+121,"SRam a ADDR_WIDTH", false,-1, 31,0);
        vcdp->declBus(c+129,"SRam a RAM_DEPTH", false,-1, 31,0);
        vcdp->declBus(c+137,"SRam a DELAY", false,-1, 31,0);
        vcdp->declBit(c+1,"SRam a clk0", false,-1);
        vcdp->declBit(c+73,"SRam a csb0", false,-1);
        vcdp->declBit(c+81,"SRam a web0", false,-1);
        vcdp->declBus(c+89,"SRam a addr0", false,-1, 6,0);
        vcdp->declBus(c+97,"SRam a din0", false,-1, 31,0);
        vcdp->declBus(c+9,"SRam a dout0", false,-1, 31,0);
        vcdp->declBit(c+17,"SRam a csb0_reg", false,-1);
        vcdp->declBit(c+25,"SRam a web0_reg", false,-1);
        vcdp->declBus(c+33,"SRam a addr0_reg", false,-1, 6,0);
        vcdp->declBus(c+41,"SRam a din0_reg", false,-1, 31,0);
    }
}

void VSRam::traceFullThis__1(VSRam__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VSRam* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBit(c+1,(vlTOPp->SRam__DOT__a_clk0));
        vcdp->fullBus(c+9,(vlTOPp->SRam__DOT__a_dout0),32);
        vcdp->fullBit(c+17,(vlTOPp->SRam__DOT__a__DOT__csb0_reg));
        vcdp->fullBit(c+25,(vlTOPp->SRam__DOT__a__DOT__web0_reg));
        vcdp->fullBus(c+33,(vlTOPp->SRam__DOT__a__DOT__addr0_reg),7);
        vcdp->fullBus(c+41,(vlTOPp->SRam__DOT__a__DOT__din0_reg),32);
        vcdp->fullBit(c+49,(vlTOPp->clock));
        vcdp->fullBit(c+57,(vlTOPp->reset));
        vcdp->fullBit(c+65,(vlTOPp->io_clk0));
        vcdp->fullBit(c+73,(vlTOPp->io_csb0));
        vcdp->fullBit(c+81,(vlTOPp->io_web0));
        vcdp->fullBus(c+89,(vlTOPp->io_addr0),7);
        vcdp->fullBus(c+97,(vlTOPp->io_din0),32);
        vcdp->fullBus(c+105,(vlTOPp->io_dout0),32);
        vcdp->fullBus(c+113,(0x20U),32);
        vcdp->fullBus(c+121,(7U),32);
        vcdp->fullBus(c+129,(0x80U),32);
        vcdp->fullBus(c+137,(3U),32);
    }
}
