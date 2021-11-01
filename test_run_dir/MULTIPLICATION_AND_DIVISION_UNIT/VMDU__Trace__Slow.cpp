// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VMDU__Syms.h"


//======================

void VMDU::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&VMDU::traceInit, &VMDU::traceFull, &VMDU::traceChg, this);
}
void VMDU::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    VMDU* t = (VMDU*)userthis;
    VMDU__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void VMDU::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VMDU* t = (VMDU*)userthis;
    VMDU__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void VMDU::traceInitThis(VMDU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMDU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
        vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void VMDU::traceFullThis(VMDU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMDU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void VMDU::traceInitThis__1(VMDU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMDU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->declBit(c+169,"clock", false,-1);
        vcdp->declBit(c+177,"reset", false,-1);
        vcdp->declBus(c+185,"io_i_mdu_rs1", false,-1, 31,0);
        vcdp->declBus(c+193,"io_i_mdu_rs2", false,-1, 31,0);
        vcdp->declBus(c+201,"io_i_mdu_op", false,-1, 2,0);
        vcdp->declBit(c+209,"io_i_mdu_valid", false,-1);
        vcdp->declBit(c+217,"io_o_mdu_ready", false,-1);
        vcdp->declBus(c+225,"io_o_mdu_rd", false,-1, 31,0);
        vcdp->declBit(c+169,"MDU clock", false,-1);
        vcdp->declBit(c+177,"MDU reset", false,-1);
        vcdp->declBus(c+185,"MDU io_i_mdu_rs1", false,-1, 31,0);
        vcdp->declBus(c+193,"MDU io_i_mdu_rs2", false,-1, 31,0);
        vcdp->declBus(c+201,"MDU io_i_mdu_op", false,-1, 2,0);
        vcdp->declBit(c+209,"MDU io_i_mdu_valid", false,-1);
        vcdp->declBit(c+217,"MDU io_o_mdu_ready", false,-1);
        vcdp->declBus(c+225,"MDU io_o_mdu_rd", false,-1, 31,0);
        vcdp->declBit(c+1,"MDU a_i_clk", false,-1);
        vcdp->declBit(c+169,"MDU a_i_rst", false,-1);
        vcdp->declBus(c+185,"MDU a_i_mdu_rs1", false,-1, 31,0);
        vcdp->declBus(c+193,"MDU a_i_mdu_rs2", false,-1, 31,0);
        vcdp->declBus(c+201,"MDU a_i_mdu_op", false,-1, 2,0);
        vcdp->declBit(c+209,"MDU a_i_mdu_valid", false,-1);
        vcdp->declBit(c+233,"MDU a_o_mdu_ready", false,-1);
        vcdp->declBus(c+241,"MDU a_o_mdu_rd", false,-1, 31,0);
        vcdp->declBus(c+297,"MDU a WIDTH", false,-1, 31,0);
        vcdp->declBit(c+1,"MDU a i_clk", false,-1);
        vcdp->declBit(c+169,"MDU a i_rst", false,-1);
        vcdp->declBus(c+185,"MDU a i_mdu_rs1", false,-1, 31,0);
        vcdp->declBus(c+193,"MDU a i_mdu_rs2", false,-1, 31,0);
        vcdp->declBus(c+201,"MDU a i_mdu_op", false,-1, 2,0);
        vcdp->declBit(c+209,"MDU a i_mdu_valid", false,-1);
        vcdp->declBit(c+233,"MDU a o_mdu_ready", false,-1);
        vcdp->declBus(c+241,"MDU a o_mdu_rd", false,-1, 31,0);
        vcdp->declBit(c+209,"MDU a valid", false,-1);
        vcdp->declQuad(c+33,"MDU a rdata_a", false,-1, 32,0);
        vcdp->declQuad(c+49,"MDU a rdata_b", false,-1, 32,0);
        vcdp->declQuad(c+65,"MDU a rd", false,-1, 63,0);
        vcdp->declBus(c+249,"MDU a mul_rd", false,-1, 31,0);
        vcdp->declBit(c+81,"MDU a mul_en", false,-1);
        vcdp->declBit(c+89,"MDU a mul_done", false,-1);
        vcdp->declBit(c+257,"MDU a mul_ready", false,-1);
        vcdp->declBit(c+265,"MDU a is_mul", false,-1);
        vcdp->declBit(c+273,"MDU a unsign_mul", false,-1);
        vcdp->declBit(c+281,"MDU a sign_unsign_mul", false,-1);
        vcdp->declBit(c+289,"MDU a is_mulh", false,-1);
        vcdp->declBit(c+97,"MDU a outsign", false,-1);
        vcdp->declBus(c+105,"MDU a dividend", false,-1, 31,0);
        vcdp->declBus(c+113,"MDU a quotient", false,-1, 31,0);
        vcdp->declBus(c+121,"MDU a quotient_msk", false,-1, 31,0);
        vcdp->declBus(c+129,"MDU a div_rd", false,-1, 31,0);
        vcdp->declQuad(c+137,"MDU a divisor", false,-1, 62,0);
        vcdp->declBit(c+153,"MDU a div_ready", false,-1);
        vcdp->declBit(c+161,"MDU a running", false,-1);
        vcdp->declBit(c+9,"MDU a is_div", false,-1);
        vcdp->declBit(c+17,"MDU a is_rem", false,-1);
        vcdp->declBit(c+281,"MDU a unsign_div_rem", false,-1);
        vcdp->declBit(c+25,"MDU a prep", false,-1);
    }
}

void VMDU::traceFullThis__1(VMDU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMDU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->fullBit(c+1,(vlTOPp->MDU__DOT__a_i_clk));
        vcdp->fullBit(c+9,(vlTOPp->MDU__DOT__a__DOT__is_div));
        vcdp->fullBit(c+17,(vlTOPp->MDU__DOT__a__DOT__is_rem));
        vcdp->fullBit(c+25,(vlTOPp->MDU__DOT__a__DOT__prep));
        vcdp->fullQuad(c+33,(vlTOPp->MDU__DOT__a__DOT__rdata_a),33);
        vcdp->fullQuad(c+49,(vlTOPp->MDU__DOT__a__DOT__rdata_b),33);
        vcdp->fullQuad(c+65,(vlTOPp->MDU__DOT__a__DOT__rd),64);
        vcdp->fullBit(c+81,(vlTOPp->MDU__DOT__a__DOT__mul_en));
        vcdp->fullBit(c+89,(vlTOPp->MDU__DOT__a__DOT__mul_done));
        vcdp->fullBit(c+97,(vlTOPp->MDU__DOT__a__DOT__outsign));
        vcdp->fullBus(c+105,(vlTOPp->MDU__DOT__a__DOT__dividend),32);
        vcdp->fullBus(c+113,(vlTOPp->MDU__DOT__a__DOT__quotient),32);
        vcdp->fullBus(c+121,(vlTOPp->MDU__DOT__a__DOT__quotient_msk),32);
        vcdp->fullBus(c+129,(vlTOPp->MDU__DOT__a__DOT__div_rd),32);
        vcdp->fullQuad(c+137,(vlTOPp->MDU__DOT__a__DOT__divisor),63);
        vcdp->fullBit(c+153,(vlTOPp->MDU__DOT__a__DOT__div_ready));
        vcdp->fullBit(c+161,(vlTOPp->MDU__DOT__a__DOT__running));
        vcdp->fullBit(c+169,(vlTOPp->clock));
        vcdp->fullBit(c+177,(vlTOPp->reset));
        vcdp->fullBus(c+185,(vlTOPp->io_i_mdu_rs1),32);
        vcdp->fullBus(c+193,(vlTOPp->io_i_mdu_rs2),32);
        vcdp->fullBus(c+201,(vlTOPp->io_i_mdu_op),3);
        vcdp->fullBit(c+209,(vlTOPp->io_i_mdu_valid));
        vcdp->fullBit(c+217,(vlTOPp->io_o_mdu_ready));
        vcdp->fullBus(c+225,(vlTOPp->io_o_mdu_rd),32);
        vcdp->fullBit(c+233,((((IData)(vlTOPp->MDU__DOT__a__DOT__mul_done) 
                               & (IData)(vlTOPp->io_i_mdu_valid)) 
                              | (IData)(vlTOPp->MDU__DOT__a__DOT__div_ready))));
        vcdp->fullBus(c+241,(((4U & (IData)(vlTOPp->io_i_mdu_op))
                               ? vlTOPp->MDU__DOT__a__DOT__div_rd
                               : (((0U != (IData)(vlTOPp->io_i_mdu_op)) 
                                   & (~ ((IData)(vlTOPp->io_i_mdu_op) 
                                         >> 2U))) ? (IData)(
                                                            (vlTOPp->MDU__DOT__a__DOT__rd 
                                                             >> 0x20U))
                                   : (IData)(vlTOPp->MDU__DOT__a__DOT__rd)))),32);
        vcdp->fullBus(c+249,((((0U != (IData)(vlTOPp->io_i_mdu_op)) 
                               & (~ ((IData)(vlTOPp->io_i_mdu_op) 
                                     >> 2U))) ? (IData)(
                                                        (vlTOPp->MDU__DOT__a__DOT__rd 
                                                         >> 0x20U))
                               : (IData)(vlTOPp->MDU__DOT__a__DOT__rd))),32);
        vcdp->fullBit(c+257,(((IData)(vlTOPp->MDU__DOT__a__DOT__mul_done) 
                              & (IData)(vlTOPp->io_i_mdu_valid))));
        vcdp->fullBit(c+265,((1U & (~ ((IData)(vlTOPp->io_i_mdu_op) 
                                       >> 2U)))));
        vcdp->fullBit(c+273,((1U & ((IData)(vlTOPp->io_i_mdu_op) 
                                    >> 1U))));
        vcdp->fullBit(c+281,((1U & (IData)(vlTOPp->io_i_mdu_op))));
        vcdp->fullBit(c+289,(((0U != (IData)(vlTOPp->io_i_mdu_op)) 
                              & (~ ((IData)(vlTOPp->io_i_mdu_op) 
                                    >> 2U)))));
        vcdp->fullBus(c+297,(0x20U),32);
    }
}
