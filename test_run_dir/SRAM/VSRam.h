// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VSRAM_H_
#define _VSRAM_H_  // guard

#include "verilated_heavy.h"

//==========

class VSRam__Syms;
class VSRam_VerilatedVcd;


//----------

VL_MODULE(VSRam) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(io_clk0,0,0);
    VL_IN8(io_csb0,0,0);
    VL_IN8(io_web0,0,0);
    VL_IN8(io_addr0,6,0);
    VL_IN(io_din0,31,0);
    VL_OUT(io_dout0,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ SRam__DOT__a_clk0;
    CData/*0:0*/ SRam__DOT__a__DOT__csb0_reg;
    CData/*0:0*/ SRam__DOT__a__DOT__web0_reg;
    CData/*6:0*/ SRam__DOT__a__DOT__addr0_reg;
    IData/*31:0*/ SRam__DOT__a_dout0;
    IData/*31:0*/ SRam__DOT__a__DOT__din0_reg;
    IData/*31:0*/ SRam__DOT__a__DOT__mem[128];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__SRam__DOT__a_clk0;
    IData/*31:0*/ __Vm_traceActivity;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VSRam__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VSRam);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VSRam(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VSRam();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VSRam__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VSRam__Syms* symsp, bool first);
  private:
    static QData _change_request(VSRam__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(VSRam__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VSRam__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VSRam__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VSRam__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__3(VSRam__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(VSRam__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(VSRam__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void traceChgThis(VSRam__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(VSRam__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(VSRam__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__4(VSRam__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(VSRam__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceFullThis__1(VSRam__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis(VSRam__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis__1(VSRam__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
