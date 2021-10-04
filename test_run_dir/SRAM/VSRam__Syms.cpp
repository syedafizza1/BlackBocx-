// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VSRam__Syms.h"
#include "VSRam.h"



// FUNCTIONS
VSRam__Syms::VSRam__Syms(VSRam* topp, const char* namep)
    // Setup locals
    : __Vm_namep(namep)
    , __Vm_activity(false)
    , __Vm_didInit(false)
    // Setup submodule names
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    // Setup scopes
    __Vscope_SRam__a.configure(this, name(), "SRam.a", "a", VerilatedScope::SCOPE_OTHER);
}
