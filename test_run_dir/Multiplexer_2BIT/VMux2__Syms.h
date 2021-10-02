// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VMUX2__SYMS_H_
#define _VMUX2__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "VMux2.h"

// SYMS CLASS
class VMux2__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    VMux2*                         TOPp;
    
    // CREATORS
    VMux2__Syms(VMux2* topp, const char* namep);
    ~VMux2__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
