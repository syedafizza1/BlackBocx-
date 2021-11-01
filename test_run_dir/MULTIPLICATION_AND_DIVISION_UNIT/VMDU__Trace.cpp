// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VMDU__Syms.h"


//======================

void VMDU::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    VMDU* t = (VMDU*)userthis;
    VMDU__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
        t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void VMDU::traceChgThis(VMDU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMDU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void VMDU::traceChgThis__2(VMDU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMDU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+1,(vlTOPp->MDU__DOT__a_i_clk));
        vcdp->chgBit(c+9,(vlTOPp->MDU__DOT__a__DOT__is_div));
        vcdp->chgBit(c+17,(vlTOPp->MDU__DOT__a__DOT__is_rem));
        vcdp->chgBit(c+25,(vlTOPp->MDU__DOT__a__DOT__prep));
    }
}

void VMDU::traceChgThis__3(VMDU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMDU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgQuad(c+33,(vlTOPp->MDU__DOT__a__DOT__rdata_a),33);
        vcdp->chgQuad(c+49,(vlTOPp->MDU__DOT__a__DOT__rdata_b),33);
        vcdp->chgQuad(c+65,(vlTOPp->MDU__DOT__a__DOT__rd),64);
        vcdp->chgBit(c+81,(vlTOPp->MDU__DOT__a__DOT__mul_en));
        vcdp->chgBit(c+89,(vlTOPp->MDU__DOT__a__DOT__mul_done));
        vcdp->chgBit(c+97,(vlTOPp->MDU__DOT__a__DOT__outsign));
        vcdp->chgBus(c+105,(vlTOPp->MDU__DOT__a__DOT__dividend),32);
        vcdp->chgBus(c+113,(vlTOPp->MDU__DOT__a__DOT__quotient),32);
        vcdp->chgBus(c+121,(vlTOPp->MDU__DOT__a__DOT__quotient_msk),32);
        vcdp->chgBus(c+129,(vlTOPp->MDU__DOT__a__DOT__div_rd),32);
        vcdp->chgQuad(c+137,(vlTOPp->MDU__DOT__a__DOT__divisor),63);
        vcdp->chgBit(c+153,(vlTOPp->MDU__DOT__a__DOT__div_ready));
        vcdp->chgBit(c+161,(vlTOPp->MDU__DOT__a__DOT__running));
    }
}

void VMDU::traceChgThis__4(VMDU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    VMDU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c = code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
        vcdp->chgBit(c+169,(vlTOPp->clock));
        vcdp->chgBit(c+177,(vlTOPp->reset));
        vcdp->chgBus(c+185,(vlTOPp->io_i_mdu_rs1),32);
        vcdp->chgBus(c+193,(vlTOPp->io_i_mdu_rs2),32);
        vcdp->chgBus(c+201,(vlTOPp->io_i_mdu_op),3);
        vcdp->chgBit(c+209,(vlTOPp->io_i_mdu_valid));
        vcdp->chgBit(c+217,(vlTOPp->io_o_mdu_ready));
        vcdp->chgBus(c+225,(vlTOPp->io_o_mdu_rd),32);
        vcdp->chgBit(c+233,((((IData)(vlTOPp->MDU__DOT__a__DOT__mul_done) 
                              & (IData)(vlTOPp->io_i_mdu_valid)) 
                             | (IData)(vlTOPp->MDU__DOT__a__DOT__div_ready))));
        vcdp->chgBus(c+241,(((4U & (IData)(vlTOPp->io_i_mdu_op))
                              ? vlTOPp->MDU__DOT__a__DOT__div_rd
                              : (((0U != (IData)(vlTOPp->io_i_mdu_op)) 
                                  & (~ ((IData)(vlTOPp->io_i_mdu_op) 
                                        >> 2U))) ? (IData)(
                                                           (vlTOPp->MDU__DOT__a__DOT__rd 
                                                            >> 0x20U))
                                  : (IData)(vlTOPp->MDU__DOT__a__DOT__rd)))),32);
        vcdp->chgBus(c+249,((((0U != (IData)(vlTOPp->io_i_mdu_op)) 
                              & (~ ((IData)(vlTOPp->io_i_mdu_op) 
                                    >> 2U))) ? (IData)(
                                                       (vlTOPp->MDU__DOT__a__DOT__rd 
                                                        >> 0x20U))
                              : (IData)(vlTOPp->MDU__DOT__a__DOT__rd))),32);
        vcdp->chgBit(c+257,(((IData)(vlTOPp->MDU__DOT__a__DOT__mul_done) 
                             & (IData)(vlTOPp->io_i_mdu_valid))));
        vcdp->chgBit(c+265,((1U & (~ ((IData)(vlTOPp->io_i_mdu_op) 
                                      >> 2U)))));
        vcdp->chgBit(c+273,((1U & ((IData)(vlTOPp->io_i_mdu_op) 
                                   >> 1U))));
        vcdp->chgBit(c+281,((1U & (IData)(vlTOPp->io_i_mdu_op))));
        vcdp->chgBit(c+289,(((0U != (IData)(vlTOPp->io_i_mdu_op)) 
                             & (~ ((IData)(vlTOPp->io_i_mdu_op) 
                                   >> 2U)))));
    }
}
