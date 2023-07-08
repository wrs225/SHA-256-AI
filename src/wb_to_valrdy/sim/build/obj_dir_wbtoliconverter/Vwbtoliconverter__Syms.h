// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VWBTOLICONVERTER__SYMS_H_
#define _VWBTOLICONVERTER__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vwbtoliconverter.h"

// SYMS CLASS
class Vwbtoliconverter__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vwbtoliconverter*              TOPp;
    
    // CREATORS
    Vwbtoliconverter__Syms(Vwbtoliconverter* topp, const char* namep);
    ~Vwbtoliconverter__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
