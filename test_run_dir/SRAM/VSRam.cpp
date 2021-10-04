// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSRam.h for the primary calling header

#include "VSRam.h"
#include "VSRam__Syms.h"

//==========

VL_CTOR_IMP(VSRam) {
    VSRam__Syms* __restrict vlSymsp = __VlSymsp = new VSRam__Syms(this, name());
    VSRam* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VSRam::__Vconfigure(VSRam__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VSRam::~VSRam() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void VSRam::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VSRam::eval\n"); );
    VSRam__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VSRam* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("SRam.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VSRam::_eval_initial_loop(VSRam__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("SRam.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VSRam::_combo__TOP__1(VSRam__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSRam::_combo__TOP__1\n"); );
    VSRam* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->SRam__DOT__a_clk0 = (1U & (~ (IData)(vlTOPp->clock)));
}

void VSRam::_settle__TOP__2(VSRam__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSRam::_settle__TOP__2\n"); );
    VSRam* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->SRam__DOT__a_clk0 = (1U & (~ (IData)(vlTOPp->clock)));
    vlTOPp->io_dout0 = vlTOPp->SRam__DOT__a_dout0;
}

VL_INLINE_OPT void VSRam::_sequent__TOP__3(VSRam__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSRam::_sequent__TOP__3\n"); );
    VSRam* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((1U & ((~ (IData)(vlTOPp->SRam__DOT__a__DOT__csb0_reg)) 
               & (~ (IData)(vlTOPp->SRam__DOT__a__DOT__web0_reg))))) {
        vlTOPp->SRam__DOT__a__DOT__mem[vlTOPp->SRam__DOT__a__DOT__addr0_reg] 
            = vlTOPp->SRam__DOT__a__DOT__din0_reg;
    }
}

VL_INLINE_OPT void VSRam::_sequent__TOP__4(VSRam__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSRam::_sequent__TOP__4\n"); );
    VSRam* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->SRam__DOT__a_dout0 = 0U;
    vlTOPp->SRam__DOT__a__DOT__csb0_reg = vlTOPp->io_csb0;
    vlTOPp->SRam__DOT__a__DOT__web0_reg = vlTOPp->io_web0;
    vlTOPp->SRam__DOT__a__DOT__addr0_reg = vlTOPp->io_addr0;
    vlTOPp->SRam__DOT__a__DOT__din0_reg = vlTOPp->io_din0;
    if (VL_UNLIKELY(((~ (IData)(vlTOPp->SRam__DOT__a__DOT__csb0_reg)) 
                     & (IData)(vlTOPp->SRam__DOT__a__DOT__web0_reg)))) {
        VL_WRITEF("%x Reading %NSRam.a addr0=%b dout0=%b\n",
                  64,VL_TIME_Q(),vlSymsp->name(),7,
                  (IData)(vlTOPp->SRam__DOT__a__DOT__addr0_reg),
                  32,vlTOPp->SRam__DOT__a__DOT__mem
                  [vlTOPp->SRam__DOT__a__DOT__addr0_reg]);
    }
    if (VL_UNLIKELY((1U & ((~ (IData)(vlTOPp->SRam__DOT__a__DOT__csb0_reg)) 
                           & (~ (IData)(vlTOPp->SRam__DOT__a__DOT__web0_reg)))))) {
        VL_WRITEF("%x Writing %NSRam.a addr0=%b din0=%b\n",
                  64,VL_TIME_Q(),vlSymsp->name(),7,
                  (IData)(vlTOPp->SRam__DOT__a__DOT__addr0_reg),
                  32,vlTOPp->SRam__DOT__a__DOT__din0_reg);
    }
    vlTOPp->io_dout0 = 0U;
}

void VSRam::_eval(VSRam__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSRam::_eval\n"); );
    VSRam* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    if (((~ (IData)(vlTOPp->SRam__DOT__a_clk0)) & (IData)(vlTOPp->__Vclklast__TOP__SRam__DOT__a_clk0))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    if (((IData)(vlTOPp->SRam__DOT__a_clk0) & (~ (IData)(vlTOPp->__Vclklast__TOP__SRam__DOT__a_clk0)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
        vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
    }
    // Final
    vlTOPp->__Vclklast__TOP__SRam__DOT__a_clk0 = vlTOPp->SRam__DOT__a_clk0;
}

void VSRam::_eval_initial(VSRam__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSRam::_eval_initial\n"); );
    VSRam* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__SRam__DOT__a_clk0 = vlTOPp->SRam__DOT__a_clk0;
}

void VSRam::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSRam::final\n"); );
    // Variables
    VSRam__Syms* __restrict vlSymsp = this->__VlSymsp;
    VSRam* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VSRam::_eval_settle(VSRam__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSRam::_eval_settle\n"); );
    VSRam* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

VL_INLINE_OPT QData VSRam::_change_request(VSRam__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSRam::_change_request\n"); );
    VSRam* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VSRam::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSRam::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((io_clk0 & 0xfeU))) {
        Verilated::overWidthError("io_clk0");}
    if (VL_UNLIKELY((io_csb0 & 0xfeU))) {
        Verilated::overWidthError("io_csb0");}
    if (VL_UNLIKELY((io_web0 & 0xfeU))) {
        Verilated::overWidthError("io_web0");}
    if (VL_UNLIKELY((io_addr0 & 0x80U))) {
        Verilated::overWidthError("io_addr0");}
}
#endif  // VL_DEBUG

void VSRam::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSRam::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_clk0 = VL_RAND_RESET_I(1);
    io_csb0 = VL_RAND_RESET_I(1);
    io_web0 = VL_RAND_RESET_I(1);
    io_addr0 = VL_RAND_RESET_I(7);
    io_din0 = VL_RAND_RESET_I(32);
    io_dout0 = VL_RAND_RESET_I(32);
    SRam__DOT__a_clk0 = VL_RAND_RESET_I(1);
    SRam__DOT__a_dout0 = VL_RAND_RESET_I(32);
    SRam__DOT__a__DOT__csb0_reg = VL_RAND_RESET_I(1);
    SRam__DOT__a__DOT__web0_reg = VL_RAND_RESET_I(1);
    SRam__DOT__a__DOT__addr0_reg = VL_RAND_RESET_I(7);
    SRam__DOT__a__DOT__din0_reg = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<128; ++__Vi0) {
            SRam__DOT__a__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    __Vm_traceActivity = 0;
}
