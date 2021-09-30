// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VOr.h for the primary calling header

#include "VOr.h"
#include "VOr__Syms.h"

//==========

VL_CTOR_IMP(VOr) {
    VOr__Syms* __restrict vlSymsp = __VlSymsp = new VOr__Syms(this, name());
    VOr* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VOr::__Vconfigure(VOr__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VOr::~VOr() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void VOr::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VOr::eval\n"); );
    VOr__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VOr* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("Or.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VOr::_eval_initial_loop(VOr__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("Or.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VOr::_combo__TOP__1(VOr__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VOr::_combo__TOP__1\n"); );
    VOr* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_Y = ((IData)(vlTOPp->io_A) | (IData)(vlTOPp->io_B));
}

void VOr::_eval(VOr__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VOr::_eval\n"); );
    VOr* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void VOr::_eval_initial(VOr__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VOr::_eval_initial\n"); );
    VOr* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VOr::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VOr::final\n"); );
    // Variables
    VOr__Syms* __restrict vlSymsp = this->__VlSymsp;
    VOr* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VOr::_eval_settle(VOr__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VOr::_eval_settle\n"); );
    VOr* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData VOr::_change_request(VOr__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VOr::_change_request\n"); );
    VOr* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VOr::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VOr::_eval_debug_assertions\n"); );
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

void VOr::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VOr::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_A = VL_RAND_RESET_I(1);
    io_B = VL_RAND_RESET_I(1);
    io_Y = VL_RAND_RESET_I(1);
    __Vm_traceActivity = 0;
}
