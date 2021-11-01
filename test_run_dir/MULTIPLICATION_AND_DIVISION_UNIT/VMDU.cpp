// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMDU.h for the primary calling header

#include "VMDU.h"
#include "VMDU__Syms.h"

//==========

VL_CTOR_IMP(VMDU) {
    VMDU__Syms* __restrict vlSymsp = __VlSymsp = new VMDU__Syms(this, name());
    VMDU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VMDU::__Vconfigure(VMDU__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VMDU::~VMDU() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void VMDU::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VMDU::eval\n"); );
    VMDU__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VMDU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("MDU.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VMDU::_eval_initial_loop(VMDU__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("MDU.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VMDU::_combo__TOP__1(VMDU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMDU::_combo__TOP__1\n"); );
    VMDU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->MDU__DOT__a_i_clk = (1U & (~ (IData)(vlTOPp->clock)));
}

void VMDU::_settle__TOP__2(VMDU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMDU::_settle__TOP__2\n"); );
    VMDU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->MDU__DOT__a_i_clk = (1U & (~ (IData)(vlTOPp->clock)));
    vlTOPp->io_o_mdu_ready = (((IData)(vlTOPp->MDU__DOT__a__DOT__mul_done) 
                               & (IData)(vlTOPp->io_i_mdu_valid)) 
                              | (IData)(vlTOPp->MDU__DOT__a__DOT__div_ready));
    vlTOPp->io_o_mdu_rd = ((4U & (IData)(vlTOPp->io_i_mdu_op))
                            ? vlTOPp->MDU__DOT__a__DOT__div_rd
                            : (((0U != (IData)(vlTOPp->io_i_mdu_op)) 
                                & (~ ((IData)(vlTOPp->io_i_mdu_op) 
                                      >> 2U))) ? (IData)(
                                                         (vlTOPp->MDU__DOT__a__DOT__rd 
                                                          >> 0x20U))
                                : (IData)(vlTOPp->MDU__DOT__a__DOT__rd)));
    vlTOPp->MDU__DOT__a__DOT__is_div = (1U & (((IData)(vlTOPp->io_i_mdu_op) 
                                               >> 2U) 
                                              & (~ 
                                                 ((IData)(vlTOPp->io_i_mdu_op) 
                                                  >> 1U))));
    vlTOPp->MDU__DOT__a__DOT__is_rem = (1U & (((IData)(vlTOPp->io_i_mdu_op) 
                                               >> 2U) 
                                              & ((IData)(vlTOPp->io_i_mdu_op) 
                                                 >> 1U)));
    vlTOPp->MDU__DOT__a__DOT__prep = ((((IData)(vlTOPp->io_i_mdu_valid) 
                                        & ((IData)(vlTOPp->MDU__DOT__a__DOT__is_div) 
                                           | (IData)(vlTOPp->MDU__DOT__a__DOT__is_rem))) 
                                       & (~ (IData)(vlTOPp->MDU__DOT__a__DOT__running))) 
                                      & (~ (IData)(vlTOPp->MDU__DOT__a__DOT__div_ready)));
}

VL_INLINE_OPT void VMDU::_sequent__TOP__3(VMDU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMDU::_sequent__TOP__3\n"); );
    VMDU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdly__MDU__DOT__a__DOT__running;
    IData/*31:0*/ __Vdly__MDU__DOT__a__DOT__dividend;
    IData/*31:0*/ __Vdly__MDU__DOT__a__DOT__quotient;
    IData/*31:0*/ __Vdly__MDU__DOT__a__DOT__quotient_msk;
    QData/*62:0*/ __Vdly__MDU__DOT__a__DOT__divisor;
    // Body
    __Vdly__MDU__DOT__a__DOT__quotient_msk = vlTOPp->MDU__DOT__a__DOT__quotient_msk;
    __Vdly__MDU__DOT__a__DOT__quotient = vlTOPp->MDU__DOT__a__DOT__quotient;
    __Vdly__MDU__DOT__a__DOT__divisor = vlTOPp->MDU__DOT__a__DOT__divisor;
    __Vdly__MDU__DOT__a__DOT__dividend = vlTOPp->MDU__DOT__a__DOT__dividend;
    __Vdly__MDU__DOT__a__DOT__running = vlTOPp->MDU__DOT__a__DOT__running;
    vlTOPp->MDU__DOT__a__DOT__mul_done = vlTOPp->MDU__DOT__a__DOT__mul_en;
    if ((((~ (IData)(vlTOPp->clock)) & (~ ((IData)(vlTOPp->io_i_mdu_op) 
                                           >> 2U))) 
         & (IData)(vlTOPp->MDU__DOT__a__DOT__mul_en))) {
        vlTOPp->MDU__DOT__a__DOT__rd = VL_MULS_QQQ(64,64,64, 
                                                   VL_EXTENDS_QQ(64,33, vlTOPp->MDU__DOT__a__DOT__rdata_a), 
                                                   VL_EXTENDS_QQ(64,33, vlTOPp->MDU__DOT__a__DOT__rdata_b));
    }
    if (vlTOPp->clock) {
        __Vdly__MDU__DOT__a__DOT__running = 0U;
    } else {
        if (vlTOPp->MDU__DOT__a__DOT__prep) {
            __Vdly__MDU__DOT__a__DOT__dividend = ((1U 
                                                   & ((~ (IData)(vlTOPp->io_i_mdu_op)) 
                                                      & (vlTOPp->io_i_mdu_rs1 
                                                         >> 0x1fU)))
                                                   ? 
                                                  VL_NEGATE_I(vlTOPp->io_i_mdu_rs1)
                                                   : vlTOPp->io_i_mdu_rs1);
            __Vdly__MDU__DOT__a__DOT__divisor = (VL_ULL(0x7fffffffffffffff) 
                                                 & (((1U 
                                                      & ((~ (IData)(vlTOPp->io_i_mdu_op)) 
                                                         & (vlTOPp->io_i_mdu_rs2 
                                                            >> 0x1fU)))
                                                      ? 
                                                     VL_NEGATE_Q((QData)((IData)(vlTOPp->io_i_mdu_rs2)))
                                                      : (QData)((IData)(vlTOPp->io_i_mdu_rs2))) 
                                                    << 0x1fU));
            __Vdly__MDU__DOT__a__DOT__quotient = 0U;
            __Vdly__MDU__DOT__a__DOT__quotient_msk = 0x80000000U;
            __Vdly__MDU__DOT__a__DOT__running = 1U;
            vlTOPp->MDU__DOT__a__DOT__div_ready = 0U;
        } else {
            if (((~ (IData)((0U != vlTOPp->MDU__DOT__a__DOT__quotient_msk))) 
                 & (IData)(vlTOPp->MDU__DOT__a__DOT__running))) {
                __Vdly__MDU__DOT__a__DOT__running = 0U;
                vlTOPp->MDU__DOT__a__DOT__div_ready = 1U;
                vlTOPp->MDU__DOT__a__DOT__div_rd = 
                    ((IData)(vlTOPp->MDU__DOT__a__DOT__is_div)
                      ? ((IData)(vlTOPp->MDU__DOT__a__DOT__outsign)
                          ? VL_NEGATE_I(vlTOPp->MDU__DOT__a__DOT__quotient)
                          : vlTOPp->MDU__DOT__a__DOT__quotient)
                      : ((IData)(vlTOPp->MDU__DOT__a__DOT__outsign)
                          ? VL_NEGATE_I(vlTOPp->MDU__DOT__a__DOT__dividend)
                          : vlTOPp->MDU__DOT__a__DOT__dividend));
            } else {
                if ((vlTOPp->MDU__DOT__a__DOT__divisor 
                     <= (QData)((IData)(vlTOPp->MDU__DOT__a__DOT__dividend)))) {
                    __Vdly__MDU__DOT__a__DOT__dividend 
                        = (vlTOPp->MDU__DOT__a__DOT__dividend 
                           - (IData)(vlTOPp->MDU__DOT__a__DOT__divisor));
                    __Vdly__MDU__DOT__a__DOT__quotient 
                        = (vlTOPp->MDU__DOT__a__DOT__quotient 
                           | vlTOPp->MDU__DOT__a__DOT__quotient_msk);
                }
                __Vdly__MDU__DOT__a__DOT__divisor = 
                    (VL_ULL(0x7fffffffffffffff) & (vlTOPp->MDU__DOT__a__DOT__divisor 
                                                   >> 1U));
                vlTOPp->MDU__DOT__a__DOT__div_ready = 0U;
                __Vdly__MDU__DOT__a__DOT__quotient_msk 
                    = (vlTOPp->MDU__DOT__a__DOT__quotient_msk 
                       >> 1U);
            }
        }
    }
    vlTOPp->MDU__DOT__a__DOT__dividend = __Vdly__MDU__DOT__a__DOT__dividend;
    vlTOPp->MDU__DOT__a__DOT__divisor = __Vdly__MDU__DOT__a__DOT__divisor;
    vlTOPp->MDU__DOT__a__DOT__quotient = __Vdly__MDU__DOT__a__DOT__quotient;
    vlTOPp->MDU__DOT__a__DOT__quotient_msk = __Vdly__MDU__DOT__a__DOT__quotient_msk;
    vlTOPp->MDU__DOT__a__DOT__running = __Vdly__MDU__DOT__a__DOT__running;
    vlTOPp->MDU__DOT__a__DOT__mul_en = (((IData)(vlTOPp->io_i_mdu_valid) 
                                         & (~ ((IData)(vlTOPp->io_i_mdu_op) 
                                               >> 2U))) 
                                        & (IData)(vlTOPp->io_i_mdu_valid));
    if (((IData)(vlTOPp->io_i_mdu_valid) & (~ ((IData)(vlTOPp->io_i_mdu_op) 
                                               >> 2U)))) {
        vlTOPp->MDU__DOT__a__DOT__rdata_a = (VL_ULL(0x1ffffffff) 
                                             & ((2U 
                                                 & (IData)(vlTOPp->io_i_mdu_op))
                                                 ? 
                                                ((1U 
                                                  & (IData)(vlTOPp->io_i_mdu_op))
                                                  ? (QData)((IData)(vlTOPp->io_i_mdu_rs1))
                                                  : 
                                                 (((QData)((IData)(
                                                                   (1U 
                                                                    & (vlTOPp->io_i_mdu_rs1 
                                                                       >> 0x1fU)))) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(vlTOPp->io_i_mdu_rs1))))
                                                 : 
                                                VL_EXTENDS_QI(33,32, vlTOPp->io_i_mdu_rs1)));
    }
    if (((IData)(vlTOPp->io_i_mdu_valid) & (~ ((IData)(vlTOPp->io_i_mdu_op) 
                                               >> 2U)))) {
        vlTOPp->MDU__DOT__a__DOT__rdata_b = (VL_ULL(0x1ffffffff) 
                                             & ((2U 
                                                 & (IData)(vlTOPp->io_i_mdu_op))
                                                 ? (QData)((IData)(vlTOPp->io_i_mdu_rs2))
                                                 : 
                                                VL_EXTENDS_QI(33,32, vlTOPp->io_i_mdu_rs2)));
    }
    if ((1U & (~ (IData)(vlTOPp->clock)))) {
        if (vlTOPp->MDU__DOT__a__DOT__prep) {
            vlTOPp->MDU__DOT__a__DOT__outsign = (((
                                                   ((~ (IData)(vlTOPp->io_i_mdu_op)) 
                                                    & (IData)(vlTOPp->MDU__DOT__a__DOT__is_div)) 
                                                   & ((1U 
                                                       & (vlTOPp->io_i_mdu_rs1 
                                                          >> 0x1fU)) 
                                                      != 
                                                      (1U 
                                                       & (vlTOPp->io_i_mdu_rs2 
                                                          >> 0x1fU)))) 
                                                  & (0U 
                                                     != vlTOPp->io_i_mdu_rs2)) 
                                                 | (((~ (IData)(vlTOPp->io_i_mdu_op)) 
                                                     & (IData)(vlTOPp->MDU__DOT__a__DOT__is_rem)) 
                                                    & (vlTOPp->io_i_mdu_rs1 
                                                       >> 0x1fU)));
        }
    }
}

VL_INLINE_OPT void VMDU::_combo__TOP__4(VMDU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMDU::_combo__TOP__4\n"); );
    VMDU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_o_mdu_rd = ((4U & (IData)(vlTOPp->io_i_mdu_op))
                            ? vlTOPp->MDU__DOT__a__DOT__div_rd
                            : (((0U != (IData)(vlTOPp->io_i_mdu_op)) 
                                & (~ ((IData)(vlTOPp->io_i_mdu_op) 
                                      >> 2U))) ? (IData)(
                                                         (vlTOPp->MDU__DOT__a__DOT__rd 
                                                          >> 0x20U))
                                : (IData)(vlTOPp->MDU__DOT__a__DOT__rd)));
    vlTOPp->io_o_mdu_ready = (((IData)(vlTOPp->MDU__DOT__a__DOT__mul_done) 
                               & (IData)(vlTOPp->io_i_mdu_valid)) 
                              | (IData)(vlTOPp->MDU__DOT__a__DOT__div_ready));
    vlTOPp->MDU__DOT__a__DOT__is_rem = (1U & (((IData)(vlTOPp->io_i_mdu_op) 
                                               >> 2U) 
                                              & ((IData)(vlTOPp->io_i_mdu_op) 
                                                 >> 1U)));
    vlTOPp->MDU__DOT__a__DOT__is_div = (1U & (((IData)(vlTOPp->io_i_mdu_op) 
                                               >> 2U) 
                                              & (~ 
                                                 ((IData)(vlTOPp->io_i_mdu_op) 
                                                  >> 1U))));
    vlTOPp->MDU__DOT__a__DOT__prep = ((((IData)(vlTOPp->io_i_mdu_valid) 
                                        & ((IData)(vlTOPp->MDU__DOT__a__DOT__is_div) 
                                           | (IData)(vlTOPp->MDU__DOT__a__DOT__is_rem))) 
                                       & (~ (IData)(vlTOPp->MDU__DOT__a__DOT__running))) 
                                      & (~ (IData)(vlTOPp->MDU__DOT__a__DOT__div_ready)));
}

void VMDU::_eval(VMDU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMDU::_eval\n"); );
    VMDU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    if (((IData)(vlTOPp->MDU__DOT__a_i_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__MDU__DOT__a_i_clk)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
        vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__MDU__DOT__a_i_clk = vlTOPp->MDU__DOT__a_i_clk;
}

void VMDU::_eval_initial(VMDU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMDU::_eval_initial\n"); );
    VMDU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__MDU__DOT__a_i_clk = vlTOPp->MDU__DOT__a_i_clk;
}

void VMDU::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMDU::final\n"); );
    // Variables
    VMDU__Syms* __restrict vlSymsp = this->__VlSymsp;
    VMDU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VMDU::_eval_settle(VMDU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMDU::_eval_settle\n"); );
    VMDU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

VL_INLINE_OPT QData VMDU::_change_request(VMDU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMDU::_change_request\n"); );
    VMDU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VMDU::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMDU::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((io_i_mdu_op & 0xf8U))) {
        Verilated::overWidthError("io_i_mdu_op");}
    if (VL_UNLIKELY((io_i_mdu_valid & 0xfeU))) {
        Verilated::overWidthError("io_i_mdu_valid");}
}
#endif  // VL_DEBUG

void VMDU::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMDU::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_i_mdu_rs1 = VL_RAND_RESET_I(32);
    io_i_mdu_rs2 = VL_RAND_RESET_I(32);
    io_i_mdu_op = VL_RAND_RESET_I(3);
    io_i_mdu_valid = VL_RAND_RESET_I(1);
    io_o_mdu_ready = VL_RAND_RESET_I(1);
    io_o_mdu_rd = VL_RAND_RESET_I(32);
    MDU__DOT__a_i_clk = VL_RAND_RESET_I(1);
    MDU__DOT__a__DOT__rdata_a = VL_RAND_RESET_Q(33);
    MDU__DOT__a__DOT__rdata_b = VL_RAND_RESET_Q(33);
    MDU__DOT__a__DOT__rd = VL_RAND_RESET_Q(64);
    MDU__DOT__a__DOT__mul_en = VL_RAND_RESET_I(1);
    MDU__DOT__a__DOT__mul_done = VL_RAND_RESET_I(1);
    MDU__DOT__a__DOT__outsign = VL_RAND_RESET_I(1);
    MDU__DOT__a__DOT__dividend = VL_RAND_RESET_I(32);
    MDU__DOT__a__DOT__quotient = VL_RAND_RESET_I(32);
    MDU__DOT__a__DOT__quotient_msk = VL_RAND_RESET_I(32);
    MDU__DOT__a__DOT__div_rd = VL_RAND_RESET_I(32);
    MDU__DOT__a__DOT__divisor = VL_RAND_RESET_Q(63);
    MDU__DOT__a__DOT__div_ready = VL_RAND_RESET_I(1);
    MDU__DOT__a__DOT__running = VL_RAND_RESET_I(1);
    MDU__DOT__a__DOT__is_div = VL_RAND_RESET_I(1);
    MDU__DOT__a__DOT__is_rem = VL_RAND_RESET_I(1);
    MDU__DOT__a__DOT__prep = VL_RAND_RESET_I(1);
    __Vm_traceActivity = 0;
}
