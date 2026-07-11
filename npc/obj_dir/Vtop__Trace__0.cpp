// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelf->top__DOT__IR),32);
        bufp->chgIData(oldp+1,((((IData)(1U) + (vlSelf->top__DOT__ifetch__DOT__pc 
                                                >> 2U)) 
                                << 2U)),32);
        bufp->chgIData(oldp+2,((((- (IData)((vlSelf->top__DOT__IR 
                                             >> 0x1fU))) 
                                 << 0xcU) | (vlSelf->top__DOT__IR 
                                             >> 0x14U))),32);
        bufp->chgCData(oldp+3,((0x1fU & (vlSelf->top__DOT__IR 
                                         >> 0xfU))),5);
        bufp->chgCData(oldp+4,((0x1fU & (vlSelf->top__DOT__IR 
                                         >> 0x14U))),5);
        bufp->chgCData(oldp+5,((0x1fU & (vlSelf->top__DOT__IR 
                                         >> 7U))),5);
        bufp->chgCData(oldp+6,((0x7fU & vlSelf->top__DOT__IR)),7);
        bufp->chgCData(oldp+7,((7U & (vlSelf->top__DOT__IR 
                                      >> 0xcU))),3);
        bufp->chgIData(oldp+8,(((0U == (0x1fU & (vlSelf->top__DOT__IR 
                                                 >> 0xfU)))
                                 ? 0U : vlSelf->top__DOT__regs__DOT__regs
                                [(0x1fU & (vlSelf->top__DOT__IR 
                                           >> 0xfU))])),32);
        bufp->chgIData(oldp+9,(((0U == (0x1fU & (vlSelf->top__DOT__IR 
                                                 >> 0x14U)))
                                 ? 0U : vlSelf->top__DOT__regs__DOT__regs
                                [(0x1fU & (vlSelf->top__DOT__IR 
                                           >> 0x14U))])),32);
        bufp->chgCData(oldp+10,(((1U == ((0x13U == 
                                          (0x7fU & vlSelf->top__DOT__IR))
                                          ? 1U : 0U))
                                  ? 1U : 0U)),4);
        bufp->chgIData(oldp+11,(vlSelf->top__DOT__alu_result),32);
        bufp->chgBit(oldp+12,((0x13U == (0x7fU & vlSelf->top__DOT__IR))));
        bufp->chgBit(oldp+13,((IData)((0x4013U == (0x707fU 
                                                   & vlSelf->top__DOT__IR)))));
        bufp->chgCData(oldp+14,(((0x13U == (0x7fU & vlSelf->top__DOT__IR))
                                  ? 1U : 0U)),3);
        bufp->chgIData(oldp+15,(((IData)((0x4013U == 
                                          (0x707fU 
                                           & vlSelf->top__DOT__IR)))
                                  ? (((- (IData)((vlSelf->top__DOT__IR 
                                                  >> 0x1fU))) 
                                      << 0xcU) | (vlSelf->top__DOT__IR 
                                                  >> 0x14U))
                                  : ((0U == (0x1fU 
                                             & (vlSelf->top__DOT__IR 
                                                >> 0x14U)))
                                      ? 0U : vlSelf->top__DOT__regs__DOT__regs
                                     [(0x1fU & (vlSelf->top__DOT__IR 
                                                >> 0x14U))]))),32);
        bufp->chgSData(oldp+16,((vlSelf->top__DOT__IR 
                                 >> 0x14U)),12);
        bufp->chgBit(oldp+17,((vlSelf->top__DOT__IR 
                               >> 0x1fU)));
        bufp->chgIData(oldp+18,(vlSelf->top__DOT__ifetch__DOT__pc),32);
        bufp->chgIData(oldp+19,(vlSelf->top__DOT__regs__DOT__regs[0]),32);
        bufp->chgIData(oldp+20,(vlSelf->top__DOT__regs__DOT__regs[1]),32);
        bufp->chgIData(oldp+21,(vlSelf->top__DOT__regs__DOT__regs[2]),32);
        bufp->chgIData(oldp+22,(vlSelf->top__DOT__regs__DOT__regs[3]),32);
        bufp->chgIData(oldp+23,(vlSelf->top__DOT__regs__DOT__regs[4]),32);
        bufp->chgIData(oldp+24,(vlSelf->top__DOT__regs__DOT__regs[5]),32);
        bufp->chgIData(oldp+25,(vlSelf->top__DOT__regs__DOT__regs[6]),32);
        bufp->chgIData(oldp+26,(vlSelf->top__DOT__regs__DOT__regs[7]),32);
        bufp->chgIData(oldp+27,(vlSelf->top__DOT__regs__DOT__regs[8]),32);
        bufp->chgIData(oldp+28,(vlSelf->top__DOT__regs__DOT__regs[9]),32);
        bufp->chgIData(oldp+29,(vlSelf->top__DOT__regs__DOT__regs[10]),32);
        bufp->chgIData(oldp+30,(vlSelf->top__DOT__regs__DOT__regs[11]),32);
        bufp->chgIData(oldp+31,(vlSelf->top__DOT__regs__DOT__regs[12]),32);
        bufp->chgIData(oldp+32,(vlSelf->top__DOT__regs__DOT__regs[13]),32);
        bufp->chgIData(oldp+33,(vlSelf->top__DOT__regs__DOT__regs[14]),32);
        bufp->chgIData(oldp+34,(vlSelf->top__DOT__regs__DOT__regs[15]),32);
        bufp->chgIData(oldp+35,(vlSelf->top__DOT__regs__DOT__regs[16]),32);
        bufp->chgIData(oldp+36,(vlSelf->top__DOT__regs__DOT__regs[17]),32);
        bufp->chgIData(oldp+37,(vlSelf->top__DOT__regs__DOT__regs[18]),32);
        bufp->chgIData(oldp+38,(vlSelf->top__DOT__regs__DOT__regs[19]),32);
        bufp->chgIData(oldp+39,(vlSelf->top__DOT__regs__DOT__regs[20]),32);
        bufp->chgIData(oldp+40,(vlSelf->top__DOT__regs__DOT__regs[21]),32);
        bufp->chgIData(oldp+41,(vlSelf->top__DOT__regs__DOT__regs[22]),32);
        bufp->chgIData(oldp+42,(vlSelf->top__DOT__regs__DOT__regs[23]),32);
        bufp->chgIData(oldp+43,(vlSelf->top__DOT__regs__DOT__regs[24]),32);
        bufp->chgIData(oldp+44,(vlSelf->top__DOT__regs__DOT__regs[25]),32);
        bufp->chgIData(oldp+45,(vlSelf->top__DOT__regs__DOT__regs[26]),32);
        bufp->chgIData(oldp+46,(vlSelf->top__DOT__regs__DOT__regs[27]),32);
        bufp->chgIData(oldp+47,(vlSelf->top__DOT__regs__DOT__regs[28]),32);
        bufp->chgIData(oldp+48,(vlSelf->top__DOT__regs__DOT__regs[29]),32);
        bufp->chgIData(oldp+49,(vlSelf->top__DOT__regs__DOT__regs[30]),32);
        bufp->chgIData(oldp+50,(vlSelf->top__DOT__regs__DOT__regs[31]),32);
        bufp->chgIData(oldp+51,(vlSelf->top__DOT__regs__DOT__unnamedblk1__DOT__i),32);
    }
    bufp->chgBit(oldp+52,(vlSelf->reset));
    bufp->chgBit(oldp+53,(vlSelf->clock));
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
