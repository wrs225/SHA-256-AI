// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VWBTOLICONVERTER_H_
#define _VWBTOLICONVERTER_H_  // guard

#include "verilated.h"

//==========

class Vwbtoliconverter__Syms;

//----------

VL_MODULE(Vwbtoliconverter) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(wb_clk_i,0,0);
    VL_IN8(wb_rst_i,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(clk,0,0);
    VL_OUT8(recv_rdy,0,0);
    VL_IN8(recv_val,0,0);
    VL_IN8(send_rdy,0,0);
    VL_OUT8(send_val,0,0);
    VL_OUT8(wbs_ack_o,0,0);
    VL_IN8(wbs_cyc_i,0,0);
    VL_IN8(wbs_sel_i,3,0);
    VL_IN8(wbs_stb_i,0,0);
    VL_IN8(wbs_we_i,0,0);
    VL_INW(recv_msg,96,0,4);
    VL_OUTW(send_msg,96,0,4);
    VL_IN(wbs_adr_i,31,0);
    VL_IN64(wbs_dat_i,63,0);
    VL_OUT64(wbs_dat_o,63,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ wbtoliconverter__DOT__v__DOT__fifo_empty;
    CData/*0:0*/ wbtoliconverter__DOT__v__DOT__fifo_full;
    CData/*1:0*/ wbtoliconverter__DOT__v__DOT__state;
    IData/*31:0*/ wbtoliconverter__DOT__v__DOT__fifo_head;
    IData/*31:0*/ wbtoliconverter__DOT__v__DOT__fifo_tail;
    WData/*97:0*/ wbtoliconverter__DOT__v__DOT__fifo[4][4];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__wb_clk_i;
    CData/*0:0*/ __Vclklast__TOP__wb_rst_i;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vwbtoliconverter__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vwbtoliconverter);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vwbtoliconverter(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vwbtoliconverter();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vwbtoliconverter__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vwbtoliconverter__Syms* symsp, bool first);
  private:
    static QData _change_request(Vwbtoliconverter__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vwbtoliconverter__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vwbtoliconverter__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vwbtoliconverter__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vwbtoliconverter__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vwbtoliconverter__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
