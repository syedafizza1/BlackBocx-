// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VAnd.h for the primary calling header

#include "VAnd.h"
#include "VAnd__Syms.h"

//==========

VL_CTOR_IMP(VAnd) {
    VAnd__Syms* __restrict vlSymsp = __VlSymsp = new VAnd__Syms(this, name());
    VAnd* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VAnd::__Vconfigure(VAnd__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VAnd::~VAnd() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void VAnd::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VAnd::eval\n"); );
    VAnd__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VAnd* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("And.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VAnd::_eval_initial_loop(VAnd__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("And.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VAnd::_combo__TOP__1(VAnd__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAnd::_combo__TOP__1\n"); );
    VAnd* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_Y = ((IData)(vlTOPp->io_A) & (IData)(vlTOPp->io_B));
}

void VAnd::_eval(VAnd__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAnd::_eval\n"); );
    VAnd* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void VAnd::_eval_initial(VAnd__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAnd::_eval_initial\n"); );
    VAnd* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VAnd::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAnd::final\n"); );
    // Variables
    VAnd__Syms* __restrict vlSymsp = this->__VlSymsp;
    VAnd* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VAnd::_eval_settle(VAnd__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAnd::_eval_settle\n"); );
    VAnd* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData VAnd::_change_request(VAnd__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAnd::_change_request\n"); );
    VAnd* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VAnd::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAnd::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((io_A & 0xfeU))) {
        Verilated::overWidthError("io_A");}
    if (VL_UNLIKELY((io_B & 0xfeU))) {
        Verilated::overWidthError("io_B");}
}
#endif  // VL_DEBUG

void VAnd::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAnd::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_A = VL_RAND_RESET_I(1);
    io_B = VL_RAND_RESET_I(1);
    io_Y = VL_RAND_RESET_I(1);
    __Vm_traceActivity = 0;
}
