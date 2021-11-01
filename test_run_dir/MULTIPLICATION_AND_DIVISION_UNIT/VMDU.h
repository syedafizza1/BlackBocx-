// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VMDU_H_
#define _VMDU_H_  // guard

#include "verilated.h"

//==========

class VMDU__Syms;
class VMDU_VerilatedVcd;


//----------

VL_MODULE(VMDU) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(io_i_mdu_op,2,0);
    VL_IN8(io_i_mdu_valid,0,0);
    VL_OUT8(io_o_mdu_ready,0,0);
    VL_IN(io_i_mdu_rs1,31,0);
    VL_IN(io_i_mdu_rs2,31,0);
    VL_OUT(io_o_mdu_rd,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ MDU__DOT__a_i_clk;
    CData/*0:0*/ MDU__DOT__a__DOT__mul_en;
    CData/*0:0*/ MDU__DOT__a__DOT__mul_done;
    CData/*0:0*/ MDU__DOT__a__DOT__outsign;
    CData/*0:0*/ MDU__DOT__a__DOT__div_ready;
    CData/*0:0*/ MDU__DOT__a__DOT__running;
    CData/*0:0*/ MDU__DOT__a__DOT__is_div;
    CData/*0:0*/ MDU__DOT__a__DOT__is_rem;
    CData/*0:0*/ MDU__DOT__a__DOT__prep;
    IData/*31:0*/ MDU__DOT__a__DOT__dividend;
    IData/*31:0*/ MDU__DOT__a__DOT__quotient;
    IData/*31:0*/ MDU__DOT__a__DOT__quotient_msk;
    IData/*31:0*/ MDU__DOT__a__DOT__div_rd;
    QData/*32:0*/ MDU__DOT__a__DOT__rdata_a;
    QData/*32:0*/ MDU__DOT__a__DOT__rdata_b;
    QData/*63:0*/ MDU__DOT__a__DOT__rd;
    QData/*62:0*/ MDU__DOT__a__DOT__divisor;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__MDU__DOT__a_i_clk;
    IData/*31:0*/ __Vm_traceActivity;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VMDU__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VMDU);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VMDU(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VMDU();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VMDU__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VMDU__Syms* symsp, bool first);
  private:
    static QData _change_request(VMDU__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(VMDU__Syms* __restrict vlSymsp);
    static void _combo__TOP__4(VMDU__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VMDU__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VMDU__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VMDU__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__3(VMDU__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(VMDU__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void traceChgThis(VMDU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(VMDU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(VMDU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__4(VMDU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(VMDU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceFullThis__1(VMDU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis(VMDU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis__1(VMDU__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
