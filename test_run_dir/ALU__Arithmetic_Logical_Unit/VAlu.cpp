// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VAlu.h for the primary calling header

#include "VAlu.h"
#include "VAlu__Syms.h"

//==========

VL_CTOR_IMP(VAlu) {
    VAlu__Syms* __restrict vlSymsp = __VlSymsp = new VAlu__Syms(this, name());
    VAlu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VAlu::__Vconfigure(VAlu__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VAlu::~VAlu() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void VAlu::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VAlu::eval\n"); );
    VAlu__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VAlu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("Alu.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VAlu::_eval_initial_loop(VAlu__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("Alu.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VAlu::_combo__TOP__1(VAlu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAlu::_combo__TOP__1\n"); );
    VAlu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_CarryOut = (1U & (((IData)(vlTOPp->io_A) 
                                  + (IData)(vlTOPp->io_B)) 
                                 >> 8U));
    vlTOPp->Alu__DOT__a__DOT__ALU_Result = (0xffU & 
                                            ((8U & (IData)(vlTOPp->io_ALU_Sel))
                                              ? ((4U 
                                                  & (IData)(vlTOPp->io_ALU_Sel))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(vlTOPp->io_ALU_Sel))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->io_ALU_Sel))
                                                    ? 
                                                   (((IData)(vlTOPp->io_A) 
                                                     == (IData)(vlTOPp->io_B))
                                                     ? 1U
                                                     : 0U)
                                                    : 
                                                   (((IData)(vlTOPp->io_A) 
                                                     > (IData)(vlTOPp->io_B))
                                                     ? 1U
                                                     : 0U))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->io_ALU_Sel))
                                                    ? 
                                                   (~ 
                                                    ((IData)(vlTOPp->io_A) 
                                                     ^ (IData)(vlTOPp->io_B)))
                                                    : 
                                                   (~ 
                                                    ((IData)(vlTOPp->io_A) 
                                                     & (IData)(vlTOPp->io_B)))))
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlTOPp->io_ALU_Sel))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->io_ALU_Sel))
                                                    ? 
                                                   (~ 
                                                    ((IData)(vlTOPp->io_A) 
                                                     | (IData)(vlTOPp->io_B)))
                                                    : 
                                                   ((IData)(vlTOPp->io_A) 
                                                    ^ (IData)(vlTOPp->io_B)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->io_ALU_Sel))
                                                    ? 
                                                   ((IData)(vlTOPp->io_A) 
                                                    | (IData)(vlTOPp->io_B))
                                                    : 
                                                   ((IData)(vlTOPp->io_A) 
                                                    & (IData)(vlTOPp->io_B)))))
                                              : ((4U 
                                                  & (IData)(vlTOPp->io_ALU_Sel))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(vlTOPp->io_ALU_Sel))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->io_ALU_Sel))
                                                    ? 
                                                   ((0x80U 
                                                     & ((IData)(vlTOPp->io_A) 
                                                        << 7U)) 
                                                    | (0x7fU 
                                                       & ((IData)(vlTOPp->io_A) 
                                                          >> 1U)))
                                                    : 
                                                   ((0xfeU 
                                                     & ((IData)(vlTOPp->io_A) 
                                                        << 1U)) 
                                                    | (1U 
                                                       & ((IData)(vlTOPp->io_A) 
                                                          >> 7U))))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->io_ALU_Sel))
                                                    ? 
                                                   ((IData)(vlTOPp->io_A) 
                                                    >> 1U)
                                                    : 
                                                   ((IData)(vlTOPp->io_A) 
                                                    << 1U)))
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlTOPp->io_ALU_Sel))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->io_ALU_Sel))
                                                    ? 
                                                   VL_DIV_III(8, (IData)(vlTOPp->io_A), (IData)(vlTOPp->io_B))
                                                    : 
                                                   ((IData)(vlTOPp->io_A) 
                                                    * (IData)(vlTOPp->io_B)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->io_ALU_Sel))
                                                    ? 
                                                   ((IData)(vlTOPp->io_A) 
                                                    - (IData)(vlTOPp->io_B))
                                                    : 
                                                   ((IData)(vlTOPp->io_A) 
                                                    + (IData)(vlTOPp->io_B)))))));
    vlTOPp->io_ALU_Out = vlTOPp->Alu__DOT__a__DOT__ALU_Result;
}

void VAlu::_eval(VAlu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAlu::_eval\n"); );
    VAlu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
}

void VAlu::_eval_initial(VAlu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAlu::_eval_initial\n"); );
    VAlu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VAlu::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAlu::final\n"); );
    // Variables
    VAlu__Syms* __restrict vlSymsp = this->__VlSymsp;
    VAlu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VAlu::_eval_settle(VAlu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAlu::_eval_settle\n"); );
    VAlu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

VL_INLINE_OPT QData VAlu::_change_request(VAlu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAlu::_change_request\n"); );
    VAlu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VAlu::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAlu::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((io_ALU_Sel & 0xf0U))) {
        Verilated::overWidthError("io_ALU_Sel");}
}
#endif  // VL_DEBUG

void VAlu::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VAlu::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_A = VL_RAND_RESET_I(8);
    io_B = VL_RAND_RESET_I(8);
    io_ALU_Sel = VL_RAND_RESET_I(4);
    io_ALU_Out = VL_RAND_RESET_I(8);
    io_CarryOut = VL_RAND_RESET_I(1);
    Alu__DOT__a__DOT__ALU_Result = VL_RAND_RESET_I(8);
    __Vm_traceActivity = 0;
}
