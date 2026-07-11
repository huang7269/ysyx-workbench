// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ __Vdlyvset__top__DOT__regs__DOT__regs__v0;
    __Vdlyvset__top__DOT__regs__DOT__regs__v0 = 0;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__regs__DOT__regs__v32;
    __Vdlyvdim0__top__DOT__regs__DOT__regs__v32 = 0;
    IData/*31:0*/ __Vdlyvval__top__DOT__regs__DOT__regs__v32;
    __Vdlyvval__top__DOT__regs__DOT__regs__v32 = 0;
    CData/*0:0*/ __Vdlyvset__top__DOT__regs__DOT__regs__v32;
    __Vdlyvset__top__DOT__regs__DOT__regs__v32 = 0;
    // Body
    __Vdlyvset__top__DOT__regs__DOT__regs__v0 = 0U;
    __Vdlyvset__top__DOT__regs__DOT__regs__v32 = 0U;
    if (vlSelf->reset) {
        vlSelf->top__DOT__regs__DOT__unnamedblk1__DOT__i = 0x20U;
        __Vdlyvset__top__DOT__regs__DOT__regs__v0 = 1U;
        vlSelf->top__DOT__ifetch__DOT__pc = 0x7ffffffcU;
    } else {
        if (((0x13U == (0x7fU & vlSelf->top__DOT__IR)) 
             & (0U != (0x1fU & (vlSelf->top__DOT__IR 
                                >> 7U))))) {
            __Vdlyvval__top__DOT__regs__DOT__regs__v32 
                = vlSelf->top__DOT__alu_result;
            __Vdlyvset__top__DOT__regs__DOT__regs__v32 = 1U;
            __Vdlyvdim0__top__DOT__regs__DOT__regs__v32 
                = (0x1fU & (vlSelf->top__DOT__IR >> 7U));
        }
        vlSelf->top__DOT__ifetch__DOT__pc = vlSelf->top__DOT__ifetch__DOT__pc_plus_4;
    }
    if (__Vdlyvset__top__DOT__regs__DOT__regs__v0) {
        vlSelf->top__DOT__regs__DOT__regs[0U] = 0U;
        vlSelf->top__DOT__regs__DOT__regs[1U] = 0U;
        vlSelf->top__DOT__regs__DOT__regs[2U] = 0U;
        vlSelf->top__DOT__regs__DOT__regs[3U] = 0U;
        vlSelf->top__DOT__regs__DOT__regs[4U] = 0U;
        vlSelf->top__DOT__regs__DOT__regs[5U] = 0U;
        vlSelf->top__DOT__regs__DOT__regs[6U] = 0U;
        vlSelf->top__DOT__regs__DOT__regs[7U] = 0U;
        vlSelf->top__DOT__regs__DOT__regs[8U] = 0U;
        vlSelf->top__DOT__regs__DOT__regs[9U] = 0U;
        vlSelf->top__DOT__regs__DOT__regs[0xaU] = 0U;
        vlSelf->top__DOT__regs__DOT__regs[0xbU] = 0U;
        vlSelf->top__DOT__regs__DOT__regs[0xcU] = 0U;
        vlSelf->top__DOT__regs__DOT__regs[0xdU] = 0U;
        vlSelf->top__DOT__regs__DOT__regs[0xeU] = 0U;
        vlSelf->top__DOT__regs__DOT__regs[0xfU] = 0U;
        vlSelf->top__DOT__regs__DOT__regs[0x10U] = 0U;
        vlSelf->top__DOT__regs__DOT__regs[0x11U] = 0U;
        vlSelf->top__DOT__regs__DOT__regs[0x12U] = 0U;
        vlSelf->top__DOT__regs__DOT__regs[0x13U] = 0U;
        vlSelf->top__DOT__regs__DOT__regs[0x14U] = 0U;
        vlSelf->top__DOT__regs__DOT__regs[0x15U] = 0U;
        vlSelf->top__DOT__regs__DOT__regs[0x16U] = 0U;
        vlSelf->top__DOT__regs__DOT__regs[0x17U] = 0U;
        vlSelf->top__DOT__regs__DOT__regs[0x18U] = 0U;
        vlSelf->top__DOT__regs__DOT__regs[0x19U] = 0U;
        vlSelf->top__DOT__regs__DOT__regs[0x1aU] = 0U;
        vlSelf->top__DOT__regs__DOT__regs[0x1bU] = 0U;
        vlSelf->top__DOT__regs__DOT__regs[0x1cU] = 0U;
        vlSelf->top__DOT__regs__DOT__regs[0x1dU] = 0U;
        vlSelf->top__DOT__regs__DOT__regs[0x1eU] = 0U;
        vlSelf->top__DOT__regs__DOT__regs[0x1fU] = 0U;
    }
    if (__Vdlyvset__top__DOT__regs__DOT__regs__v32) {
        vlSelf->top__DOT__regs__DOT__regs[__Vdlyvdim0__top__DOT__regs__DOT__regs__v32] 
            = __Vdlyvval__top__DOT__regs__DOT__regs__v32;
    }
    vlSelf->top__DOT__ifetch__DOT__pc_plus_4 = (((IData)(1U) 
                                                 + 
                                                 (vlSelf->top__DOT__ifetch__DOT__pc 
                                                  >> 2U)) 
                                                << 2U);
    vlSelf->top__DOT__IR = ((0x80000000U == (((IData)(1U) 
                                              + (vlSelf->top__DOT__ifetch__DOT__pc 
                                                 >> 2U)) 
                                             << 2U))
                             ? 0x10c093U : ((0x80000004U 
                                             == (((IData)(1U) 
                                                  + 
                                                  (vlSelf->top__DOT__ifetch__DOT__pc 
                                                   >> 2U)) 
                                                 << 2U))
                                             ? 0x20c093U
                                             : ((0x80000008U 
                                                 == 
                                                 (((IData)(1U) 
                                                   + 
                                                   (vlSelf->top__DOT__ifetch__DOT__pc 
                                                    >> 2U)) 
                                                  << 2U))
                                                 ? 0x30c093U
                                                 : 0x100073U)));
    vlSelf->top__DOT__alu_result = ((1U == ((1U == 
                                             ((0x13U 
                                               == (0x7fU 
                                                   & vlSelf->top__DOT__IR))
                                               ? 1U
                                               : 0U))
                                             ? 1U : 0U))
                                     ? (((0U == (0x1fU 
                                                 & (vlSelf->top__DOT__IR 
                                                    >> 0xfU)))
                                          ? 0U : vlSelf->top__DOT__regs__DOT__regs
                                         [(0x1fU & 
                                           (vlSelf->top__DOT__IR 
                                            >> 0xfU))]) 
                                        + ((IData)(
                                                   (0x4013U 
                                                    == 
                                                    (0x707fU 
                                                     & vlSelf->top__DOT__IR)))
                                            ? (((- (IData)(
                                                           (vlSelf->top__DOT__IR 
                                                            >> 0x1fU))) 
                                                << 0xcU) 
                                               | (vlSelf->top__DOT__IR 
                                                  >> 0x14U))
                                            : ((0U 
                                                == 
                                                (0x1fU 
                                                 & (vlSelf->top__DOT__IR 
                                                    >> 0x14U)))
                                                ? 0U
                                                : vlSelf->top__DOT__regs__DOT__regs
                                               [(0x1fU 
                                                 & (vlSelf->top__DOT__IR 
                                                    >> 0x14U))])))
                                     : 0U);
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vtop___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vtop___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("vsrc/top.v", 3, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vtop___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("vsrc/top.v", 3, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vtop___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
}
#endif  // VL_DEBUG
