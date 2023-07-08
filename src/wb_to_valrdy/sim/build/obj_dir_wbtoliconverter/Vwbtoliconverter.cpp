// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vwbtoliconverter.h for the primary calling header

#include "Vwbtoliconverter.h"
#include "Vwbtoliconverter__Syms.h"

//==========

VL_CTOR_IMP(Vwbtoliconverter) {
    Vwbtoliconverter__Syms* __restrict vlSymsp = __VlSymsp = new Vwbtoliconverter__Syms(this, name());
    Vwbtoliconverter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vwbtoliconverter::__Vconfigure(Vwbtoliconverter__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vwbtoliconverter::~Vwbtoliconverter() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vwbtoliconverter::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vwbtoliconverter::eval\n"); );
    Vwbtoliconverter__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vwbtoliconverter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("WbToLiConverter.v", 140, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vwbtoliconverter::_eval_initial_loop(Vwbtoliconverter__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("WbToLiConverter.v", 140, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vwbtoliconverter::_sequent__TOP__1(Vwbtoliconverter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwbtoliconverter::_sequent__TOP__1\n"); );
    Vwbtoliconverter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdly__wbtoliconverter__DOT__v__DOT__fifo_empty;
    CData/*0:0*/ __Vdly__wbtoliconverter__DOT__v__DOT__fifo_full;
    CData/*1:0*/ __Vdly__wbtoliconverter__DOT__v__DOT__state;
    CData/*1:0*/ __Vdlyvdim0__wbtoliconverter__DOT__v__DOT__fifo__v0;
    CData/*0:0*/ __Vdlyvset__wbtoliconverter__DOT__v__DOT__fifo__v0;
    CData/*1:0*/ __Vdlyvdim0__wbtoliconverter__DOT__v__DOT__fifo__v1;
    CData/*0:0*/ __Vdlyvset__wbtoliconverter__DOT__v__DOT__fifo__v1;
    IData/*31:0*/ __Vdly__wbtoliconverter__DOT__v__DOT__fifo_head;
    IData/*31:0*/ __Vdly__wbtoliconverter__DOT__v__DOT__fifo_tail;
    IData/*31:0*/ __Vdlyvlsb__wbtoliconverter__DOT__v__DOT__fifo__v0;
    WData/*96:0*/ __Vdlyvval__wbtoliconverter__DOT__v__DOT__fifo__v0[4];
    IData/*31:0*/ __Vdlyvlsb__wbtoliconverter__DOT__v__DOT__fifo__v1;
    // Body
    __Vdly__wbtoliconverter__DOT__v__DOT__fifo_full 
        = vlTOPp->wbtoliconverter__DOT__v__DOT__fifo_full;
    __Vdly__wbtoliconverter__DOT__v__DOT__fifo_tail 
        = vlTOPp->wbtoliconverter__DOT__v__DOT__fifo_tail;
    __Vdly__wbtoliconverter__DOT__v__DOT__state = vlTOPp->wbtoliconverter__DOT__v__DOT__state;
    __Vdly__wbtoliconverter__DOT__v__DOT__fifo_empty 
        = vlTOPp->wbtoliconverter__DOT__v__DOT__fifo_empty;
    __Vdly__wbtoliconverter__DOT__v__DOT__fifo_head 
        = vlTOPp->wbtoliconverter__DOT__v__DOT__fifo_head;
    __Vdlyvset__wbtoliconverter__DOT__v__DOT__fifo__v0 = 0U;
    __Vdlyvset__wbtoliconverter__DOT__v__DOT__fifo__v1 = 0U;
    if (vlTOPp->wb_rst_i) {
        __Vdly__wbtoliconverter__DOT__v__DOT__fifo_head = 0U;
        __Vdly__wbtoliconverter__DOT__v__DOT__fifo_tail = 0U;
        __Vdly__wbtoliconverter__DOT__v__DOT__fifo_empty = 1U;
        __Vdly__wbtoliconverter__DOT__v__DOT__fifo_full = 0U;
        __Vdly__wbtoliconverter__DOT__v__DOT__state = 0U;
    } else {
        if ((2U & (IData)(vlTOPp->wbtoliconverter__DOT__v__DOT__state))) {
            if ((1U & (IData)(vlTOPp->wbtoliconverter__DOT__v__DOT__state))) {
                if ((((IData)(vlTOPp->wbs_stb_i) & (IData)(vlTOPp->wbs_cyc_i)) 
                     & (~ (IData)(vlTOPp->wbs_we_i)))) {
                    vlTOPp->wbs_ack_o = 1U;
                    __Vdly__wbtoliconverter__DOT__v__DOT__state = 0U;
                } else {
                    vlTOPp->wbs_ack_o = 0U;
                }
            } else {
                if (vlTOPp->recv_val) {
                    vlTOPp->wbs_dat_o = (((QData)((IData)(
                                                          vlTOPp->recv_msg[1U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlTOPp->recv_msg[0U])));
                    __Vdly__wbtoliconverter__DOT__v__DOT__state = 3U;
                }
            }
        } else {
            if ((1U & (IData)(vlTOPp->wbtoliconverter__DOT__v__DOT__state))) {
                if (((IData)(vlTOPp->send_rdy) & (~ (IData)(vlTOPp->wbtoliconverter__DOT__v__DOT__fifo_empty)))) {
                    __Vdly__wbtoliconverter__DOT__v__DOT__fifo_head 
                        = VL_MODDIVS_III(32, ((IData)(1U) 
                                              + vlTOPp->wbtoliconverter__DOT__v__DOT__fifo_head), (IData)(4U));
                    __Vdly__wbtoliconverter__DOT__v__DOT__fifo_full = 0U;
                    __Vdly__wbtoliconverter__DOT__v__DOT__fifo_empty 
                        = (vlTOPp->wbtoliconverter__DOT__v__DOT__fifo_head 
                           == vlTOPp->wbtoliconverter__DOT__v__DOT__fifo_tail);
                    __Vdly__wbtoliconverter__DOT__v__DOT__state = 2U;
                }
            } else {
                if ((((IData)(vlTOPp->wbs_stb_i) & (IData)(vlTOPp->wbs_cyc_i)) 
                     & (~ (IData)(vlTOPp->wbtoliconverter__DOT__v__DOT__fifo_full)))) {
                    __Vdlyvval__wbtoliconverter__DOT__v__DOT__fifo__v0[0U] 
                        = (IData)(vlTOPp->wbs_dat_i);
                    __Vdlyvval__wbtoliconverter__DOT__v__DOT__fifo__v0[1U] 
                        = (IData)((vlTOPp->wbs_dat_i 
                                   >> 0x20U));
                    __Vdlyvval__wbtoliconverter__DOT__v__DOT__fifo__v0[2U] 
                        = vlTOPp->wbs_adr_i;
                    __Vdlyvval__wbtoliconverter__DOT__v__DOT__fifo__v0[3U] 
                        = vlTOPp->wbs_we_i;
                    __Vdlyvset__wbtoliconverter__DOT__v__DOT__fifo__v0 = 1U;
                    __Vdlyvlsb__wbtoliconverter__DOT__v__DOT__fifo__v0 = 1U;
                    __Vdlyvdim0__wbtoliconverter__DOT__v__DOT__fifo__v0 
                        = (3U & vlTOPp->wbtoliconverter__DOT__v__DOT__fifo_tail);
                    __Vdly__wbtoliconverter__DOT__v__DOT__fifo_empty = 0U;
                    __Vdly__wbtoliconverter__DOT__v__DOT__state = 1U;
                    __Vdlyvset__wbtoliconverter__DOT__v__DOT__fifo__v1 = 1U;
                    __Vdlyvlsb__wbtoliconverter__DOT__v__DOT__fifo__v1 = 0U;
                    __Vdlyvdim0__wbtoliconverter__DOT__v__DOT__fifo__v1 
                        = (3U & vlTOPp->wbtoliconverter__DOT__v__DOT__fifo_tail);
                    __Vdly__wbtoliconverter__DOT__v__DOT__fifo_tail 
                        = VL_MODDIVS_III(32, ((IData)(1U) 
                                              + vlTOPp->wbtoliconverter__DOT__v__DOT__fifo_tail), (IData)(4U));
                    __Vdly__wbtoliconverter__DOT__v__DOT__fifo_full 
                        = (vlTOPp->wbtoliconverter__DOT__v__DOT__fifo_tail 
                           == vlTOPp->wbtoliconverter__DOT__v__DOT__fifo_head);
                }
            }
        }
    }
    vlTOPp->wbtoliconverter__DOT__v__DOT__fifo_tail 
        = __Vdly__wbtoliconverter__DOT__v__DOT__fifo_tail;
    vlTOPp->wbtoliconverter__DOT__v__DOT__fifo_full 
        = __Vdly__wbtoliconverter__DOT__v__DOT__fifo_full;
    vlTOPp->wbtoliconverter__DOT__v__DOT__fifo_empty 
        = __Vdly__wbtoliconverter__DOT__v__DOT__fifo_empty;
    vlTOPp->wbtoliconverter__DOT__v__DOT__state = __Vdly__wbtoliconverter__DOT__v__DOT__state;
    vlTOPp->wbtoliconverter__DOT__v__DOT__fifo_head 
        = __Vdly__wbtoliconverter__DOT__v__DOT__fifo_head;
    if (__Vdlyvset__wbtoliconverter__DOT__v__DOT__fifo__v0) {
        VL_ASSIGNSEL_WIIW(97,__Vdlyvlsb__wbtoliconverter__DOT__v__DOT__fifo__v0, 
                          vlTOPp->wbtoliconverter__DOT__v__DOT__fifo
                          [__Vdlyvdim0__wbtoliconverter__DOT__v__DOT__fifo__v0], __Vdlyvval__wbtoliconverter__DOT__v__DOT__fifo__v0);
    }
    if (__Vdlyvset__wbtoliconverter__DOT__v__DOT__fifo__v1) {
        vlTOPp->wbtoliconverter__DOT__v__DOT__fifo[__Vdlyvdim0__wbtoliconverter__DOT__v__DOT__fifo__v1][(__Vdlyvlsb__wbtoliconverter__DOT__v__DOT__fifo__v1 
                                                                                >> 5U)] 
            = (vlTOPp->wbtoliconverter__DOT__v__DOT__fifo
               [__Vdlyvdim0__wbtoliconverter__DOT__v__DOT__fifo__v1][
               (__Vdlyvlsb__wbtoliconverter__DOT__v__DOT__fifo__v1 
                >> 5U)] | ((IData)(1U) << (0x1fU & __Vdlyvlsb__wbtoliconverter__DOT__v__DOT__fifo__v1)));
    }
    vlTOPp->send_val = (1U & (~ (IData)(vlTOPp->wbtoliconverter__DOT__v__DOT__fifo_empty)));
    vlTOPp->recv_rdy = (2U == (IData)(vlTOPp->wbtoliconverter__DOT__v__DOT__state));
    vlTOPp->send_msg[0U] = ((vlTOPp->wbtoliconverter__DOT__v__DOT__fifo
                             [(3U & vlTOPp->wbtoliconverter__DOT__v__DOT__fifo_head)][1U] 
                             << 0x1fU) | (vlTOPp->wbtoliconverter__DOT__v__DOT__fifo
                                          [(3U & vlTOPp->wbtoliconverter__DOT__v__DOT__fifo_head)][0U] 
                                          >> 1U));
    vlTOPp->send_msg[1U] = ((vlTOPp->wbtoliconverter__DOT__v__DOT__fifo
                             [(3U & vlTOPp->wbtoliconverter__DOT__v__DOT__fifo_head)][2U] 
                             << 0x1fU) | (vlTOPp->wbtoliconverter__DOT__v__DOT__fifo
                                          [(3U & vlTOPp->wbtoliconverter__DOT__v__DOT__fifo_head)][1U] 
                                          >> 1U));
    vlTOPp->send_msg[2U] = ((vlTOPp->wbtoliconverter__DOT__v__DOT__fifo
                             [(3U & vlTOPp->wbtoliconverter__DOT__v__DOT__fifo_head)][3U] 
                             << 0x1fU) | (vlTOPp->wbtoliconverter__DOT__v__DOT__fifo
                                          [(3U & vlTOPp->wbtoliconverter__DOT__v__DOT__fifo_head)][2U] 
                                          >> 1U));
    vlTOPp->send_msg[3U] = (1U & (vlTOPp->wbtoliconverter__DOT__v__DOT__fifo
                                  [(3U & vlTOPp->wbtoliconverter__DOT__v__DOT__fifo_head)][3U] 
                                  >> 1U));
}

void Vwbtoliconverter::_settle__TOP__2(Vwbtoliconverter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwbtoliconverter::_settle__TOP__2\n"); );
    Vwbtoliconverter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->send_val = (1U & (~ (IData)(vlTOPp->wbtoliconverter__DOT__v__DOT__fifo_empty)));
    vlTOPp->recv_rdy = (2U == (IData)(vlTOPp->wbtoliconverter__DOT__v__DOT__state));
    vlTOPp->send_msg[0U] = ((vlTOPp->wbtoliconverter__DOT__v__DOT__fifo
                             [(3U & vlTOPp->wbtoliconverter__DOT__v__DOT__fifo_head)][1U] 
                             << 0x1fU) | (vlTOPp->wbtoliconverter__DOT__v__DOT__fifo
                                          [(3U & vlTOPp->wbtoliconverter__DOT__v__DOT__fifo_head)][0U] 
                                          >> 1U));
    vlTOPp->send_msg[1U] = ((vlTOPp->wbtoliconverter__DOT__v__DOT__fifo
                             [(3U & vlTOPp->wbtoliconverter__DOT__v__DOT__fifo_head)][2U] 
                             << 0x1fU) | (vlTOPp->wbtoliconverter__DOT__v__DOT__fifo
                                          [(3U & vlTOPp->wbtoliconverter__DOT__v__DOT__fifo_head)][1U] 
                                          >> 1U));
    vlTOPp->send_msg[2U] = ((vlTOPp->wbtoliconverter__DOT__v__DOT__fifo
                             [(3U & vlTOPp->wbtoliconverter__DOT__v__DOT__fifo_head)][3U] 
                             << 0x1fU) | (vlTOPp->wbtoliconverter__DOT__v__DOT__fifo
                                          [(3U & vlTOPp->wbtoliconverter__DOT__v__DOT__fifo_head)][2U] 
                                          >> 1U));
    vlTOPp->send_msg[3U] = (1U & (vlTOPp->wbtoliconverter__DOT__v__DOT__fifo
                                  [(3U & vlTOPp->wbtoliconverter__DOT__v__DOT__fifo_head)][3U] 
                                  >> 1U));
}

void Vwbtoliconverter::_eval(Vwbtoliconverter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwbtoliconverter::_eval\n"); );
    Vwbtoliconverter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->wb_clk_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__wb_clk_i))) 
         | ((IData)(vlTOPp->wb_rst_i) & (~ (IData)(vlTOPp->__Vclklast__TOP__wb_rst_i))))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__wb_clk_i = vlTOPp->wb_clk_i;
    vlTOPp->__Vclklast__TOP__wb_rst_i = vlTOPp->wb_rst_i;
}

void Vwbtoliconverter::_eval_initial(Vwbtoliconverter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwbtoliconverter::_eval_initial\n"); );
    Vwbtoliconverter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__wb_clk_i = vlTOPp->wb_clk_i;
    vlTOPp->__Vclklast__TOP__wb_rst_i = vlTOPp->wb_rst_i;
}

void Vwbtoliconverter::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwbtoliconverter::final\n"); );
    // Variables
    Vwbtoliconverter__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vwbtoliconverter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vwbtoliconverter::_eval_settle(Vwbtoliconverter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwbtoliconverter::_eval_settle\n"); );
    Vwbtoliconverter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData Vwbtoliconverter::_change_request(Vwbtoliconverter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwbtoliconverter::_change_request\n"); );
    Vwbtoliconverter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vwbtoliconverter::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwbtoliconverter::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((recv_msg[3U] & 0xfffffffeU))) {
        Verilated::overWidthError("recv_msg");}
    if (VL_UNLIKELY((recv_val & 0xfeU))) {
        Verilated::overWidthError("recv_val");}
    if (VL_UNLIKELY((send_rdy & 0xfeU))) {
        Verilated::overWidthError("send_rdy");}
    if (VL_UNLIKELY((wb_clk_i & 0xfeU))) {
        Verilated::overWidthError("wb_clk_i");}
    if (VL_UNLIKELY((wb_rst_i & 0xfeU))) {
        Verilated::overWidthError("wb_rst_i");}
    if (VL_UNLIKELY((wbs_cyc_i & 0xfeU))) {
        Verilated::overWidthError("wbs_cyc_i");}
    if (VL_UNLIKELY((wbs_sel_i & 0xf0U))) {
        Verilated::overWidthError("wbs_sel_i");}
    if (VL_UNLIKELY((wbs_stb_i & 0xfeU))) {
        Verilated::overWidthError("wbs_stb_i");}
    if (VL_UNLIKELY((wbs_we_i & 0xfeU))) {
        Verilated::overWidthError("wbs_we_i");}
}
#endif  // VL_DEBUG

void Vwbtoliconverter::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vwbtoliconverter::_ctor_var_reset\n"); );
    // Body
    reset = VL_RAND_RESET_I(1);
    clk = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(97, recv_msg);
    recv_rdy = VL_RAND_RESET_I(1);
    recv_val = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(97, send_msg);
    send_rdy = VL_RAND_RESET_I(1);
    send_val = VL_RAND_RESET_I(1);
    wb_clk_i = VL_RAND_RESET_I(1);
    wb_rst_i = VL_RAND_RESET_I(1);
    wbs_ack_o = VL_RAND_RESET_I(1);
    wbs_adr_i = VL_RAND_RESET_I(32);
    wbs_cyc_i = VL_RAND_RESET_I(1);
    wbs_dat_i = VL_RAND_RESET_Q(64);
    wbs_dat_o = VL_RAND_RESET_Q(64);
    wbs_sel_i = VL_RAND_RESET_I(4);
    wbs_stb_i = VL_RAND_RESET_I(1);
    wbs_we_i = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
            VL_ZERO_RESET_W(98, wbtoliconverter__DOT__v__DOT__fifo[__Vi0]);
    }}
    wbtoliconverter__DOT__v__DOT__fifo_head = 0;
    wbtoliconverter__DOT__v__DOT__fifo_tail = 0;
    wbtoliconverter__DOT__v__DOT__fifo_empty = VL_RAND_RESET_I(1);
    wbtoliconverter__DOT__v__DOT__fifo_full = VL_RAND_RESET_I(1);
    wbtoliconverter__DOT__v__DOT__state = VL_RAND_RESET_I(2);
}
