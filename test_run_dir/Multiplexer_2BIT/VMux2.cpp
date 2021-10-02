// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMux2.h for the primary calling header

#include "VMux2.h"
#include "VMux2__Syms.h"

//==========

VL_CTOR_IMP(VMux2) {
    VMux2__Syms* __restrict vlSymsp = __VlSymsp = new VMux2__Syms(this, name());
    VMux2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VMux2::__Vconfigure(VMux2__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VMux2::~VMux2() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void VMux2::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VMux2::eval\n"); );
    VMux2__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VMux2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("Mux2.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VMux2::_eval_initial_loop(VMux2__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
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
            VL_FATAL_MT("Mux2.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VMux2::_combo__TOP__1(VMux2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMux2::_combo__TOP__1\n"); );
    VMux2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_Y = (((IData)(vlTOPp->io_D1) & (IData)(vlTOPp->io_S)) 
                    | ((IData)(vlTOPp->io_D0) & (~ (IData)(vlTOPp->io_S))));
}

void VMux2::_eval(VMux2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMux2::_eval\n"); );
    VMux2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void VMux2::_eval_initial(VMux2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMux2::_eval_initial\n"); );
    VMux2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VMux2::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMux2::final\n"); );
    // Variables
    VMux2__Syms* __restrict vlSymsp = this->__VlSymsp;
    VMux2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VMux2::_eval_settle(VMux2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMux2::_eval_settle\n"); );
    VMux2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData VMux2::_change_request(VMux2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMux2::_change_request\n"); );
    VMux2* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VMux2::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMux2::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((io_D0 & 0xfeU))) {
        Verilated::overWidthError("io_D0");}
    if (VL_UNLIKELY((io_D1 & 0xfeU))) {
        Verilated::overWidthError("io_D1");}
    if (VL_UNLIKELY((io_S & 0xfeU))) {
        Verilated::overWidthError("io_S");}
}
#endif  // VL_DEBUG

void VMux2::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMux2::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_D0 = VL_RAND_RESET_I(1);
    io_D1 = VL_RAND_RESET_I(1);
    io_S = VL_RAND_RESET_I(1);
    io_Y = VL_RAND_RESET_I(1);
}
