// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+53,"reset", false,-1);
    tracep->declBit(c+54,"clock", false,-1);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+53,"reset", false,-1);
    tracep->declBit(c+54,"clock", false,-1);
    tracep->declBus(c+1,"Instruction", false,-1, 31,0);
    tracep->declBus(c+2,"PC_PLUS_4", false,-1, 31,0);
    tracep->declBus(c+1,"IR", false,-1, 31,0);
    tracep->declBus(c+3,"Instruction_imm", false,-1, 31,0);
    tracep->declBus(c+4,"rs1", false,-1, 4,0);
    tracep->declBus(c+5,"rs2", false,-1, 4,0);
    tracep->declBus(c+6,"rd", false,-1, 4,0);
    tracep->declBus(c+7,"opcode", false,-1, 6,0);
    tracep->declBus(c+8,"fun_1", false,-1, 2,0);
    tracep->declBus(c+9,"rdata_1", false,-1, 31,0);
    tracep->declBus(c+10,"rdata_2", false,-1, 31,0);
    tracep->declBus(c+11,"alu_ctrl", false,-1, 3,0);
    tracep->declBus(c+12,"alu_result", false,-1, 31,0);
    tracep->declBit(c+13,"RegWrite", false,-1);
    tracep->declBit(c+14,"AluSrc", false,-1);
    tracep->declBus(c+15,"Aluop", false,-1, 2,0);
    tracep->pushNamePrefix("alu ");
    tracep->declBus(c+11,"alu_ctrl", false,-1, 3,0);
    tracep->declBit(c+14,"AluSrc", false,-1);
    tracep->declBus(c+9,"rs1", false,-1, 31,0);
    tracep->declBus(c+10,"rs2", false,-1, 31,0);
    tracep->declBus(c+3,"Immediate", false,-1, 31,0);
    tracep->declBus(c+12,"Alu_result", false,-1, 31,0);
    tracep->declBus(c+9,"Ainput", false,-1, 31,0);
    tracep->declBus(c+16,"Binput", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("alu_ctl ");
    tracep->declBus(c+15,"Aluop", false,-1, 2,0);
    tracep->declBus(c+11,"alu_ctrl", false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("iconctrol ");
    tracep->declBus(c+7,"opcode", false,-1, 6,0);
    tracep->declBus(c+8,"fun_1", false,-1, 2,0);
    tracep->declBit(c+13,"RegWrite", false,-1);
    tracep->declBit(c+14,"AluSrc", false,-1);
    tracep->declBus(c+15,"Aluop", false,-1, 2,0);
    tracep->declBit(c+13,"I_format", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("idecode ");
    tracep->declBus(c+1,"Instruction", false,-1, 31,0);
    tracep->declBus(c+3,"Instruction_imm", false,-1, 31,0);
    tracep->declBus(c+4,"read_register_addr_1", false,-1, 4,0);
    tracep->declBus(c+5,"read_register_addr_2", false,-1, 4,0);
    tracep->declBus(c+6,"write_register_addr", false,-1, 4,0);
    tracep->declBus(c+17,"I_immediate", false,-1, 11,0);
    tracep->declBit(c+18,"sign", false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ifetch ");
    tracep->declBit(c+53,"reset", false,-1);
    tracep->declBit(c+54,"clock", false,-1);
    tracep->declBus(c+1,"Instruction", false,-1, 31,0);
    tracep->declBus(c+2,"PC_PLUS_4_out", false,-1, 31,0);
    tracep->declBus(c+1,"IR", false,-1, 31,0);
    tracep->declBus(c+2,"pc_plus_4", false,-1, 31,0);
    tracep->declBus(c+19,"pc", false,-1, 31,0);
    tracep->declBus(c+2,"next_pc", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("regs ");
    tracep->declBus(c+55,"ADDR_WIDTH", false,-1, 31,0);
    tracep->declBus(c+56,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+53,"reset", false,-1);
    tracep->declBit(c+54,"clock", false,-1);
    tracep->declBus(c+12,"wdata", false,-1, 31,0);
    tracep->declBus(c+6,"waddr", false,-1, 4,0);
    tracep->declBit(c+13,"RegWrite", false,-1);
    tracep->declBus(c+4,"raddr1", false,-1, 4,0);
    tracep->declBus(c+5,"raddr2", false,-1, 4,0);
    tracep->declBus(c+9,"rdata1_out", false,-1, 31,0);
    tracep->declBus(c+10,"rdata2_out", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+20+i*1,"regs", true,(i+0), 31,0);
    }
    tracep->pushNamePrefix("unnamedblk1 ");
    tracep->declBus(c+52,"i", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("rom ");
    tracep->declBus(c+2,"PC", false,-1, 31,0);
    tracep->declBus(c+1,"Instruction", false,-1, 31,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vtop___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->top__DOT__IR),32);
    bufp->fullIData(oldp+2,((((IData)(1U) + (vlSelf->top__DOT__ifetch__DOT__pc 
                                             >> 2U)) 
                             << 2U)),32);
    bufp->fullIData(oldp+3,((((- (IData)((vlSelf->top__DOT__IR 
                                          >> 0x1fU))) 
                              << 0xcU) | (vlSelf->top__DOT__IR 
                                          >> 0x14U))),32);
    bufp->fullCData(oldp+4,((0x1fU & (vlSelf->top__DOT__IR 
                                      >> 0xfU))),5);
    bufp->fullCData(oldp+5,((0x1fU & (vlSelf->top__DOT__IR 
                                      >> 0x14U))),5);
    bufp->fullCData(oldp+6,((0x1fU & (vlSelf->top__DOT__IR 
                                      >> 7U))),5);
    bufp->fullCData(oldp+7,((0x7fU & vlSelf->top__DOT__IR)),7);
    bufp->fullCData(oldp+8,((7U & (vlSelf->top__DOT__IR 
                                   >> 0xcU))),3);
    bufp->fullIData(oldp+9,(((0U == (0x1fU & (vlSelf->top__DOT__IR 
                                              >> 0xfU)))
                              ? 0U : vlSelf->top__DOT__regs__DOT__regs
                             [(0x1fU & (vlSelf->top__DOT__IR 
                                        >> 0xfU))])),32);
    bufp->fullIData(oldp+10,(((0U == (0x1fU & (vlSelf->top__DOT__IR 
                                               >> 0x14U)))
                               ? 0U : vlSelf->top__DOT__regs__DOT__regs
                              [(0x1fU & (vlSelf->top__DOT__IR 
                                         >> 0x14U))])),32);
    bufp->fullCData(oldp+11,(((1U == ((0x13U == (0x7fU 
                                                 & vlSelf->top__DOT__IR))
                                       ? 1U : 0U)) ? 1U
                               : 0U)),4);
    bufp->fullIData(oldp+12,(vlSelf->top__DOT__alu_result),32);
    bufp->fullBit(oldp+13,((0x13U == (0x7fU & vlSelf->top__DOT__IR))));
    bufp->fullBit(oldp+14,((IData)((0x4013U == (0x707fU 
                                                & vlSelf->top__DOT__IR)))));
    bufp->fullCData(oldp+15,(((0x13U == (0x7fU & vlSelf->top__DOT__IR))
                               ? 1U : 0U)),3);
    bufp->fullIData(oldp+16,(((IData)((0x4013U == (0x707fU 
                                                   & vlSelf->top__DOT__IR)))
                               ? (((- (IData)((vlSelf->top__DOT__IR 
                                               >> 0x1fU))) 
                                   << 0xcU) | (vlSelf->top__DOT__IR 
                                               >> 0x14U))
                               : ((0U == (0x1fU & (vlSelf->top__DOT__IR 
                                                   >> 0x14U)))
                                   ? 0U : vlSelf->top__DOT__regs__DOT__regs
                                  [(0x1fU & (vlSelf->top__DOT__IR 
                                             >> 0x14U))]))),32);
    bufp->fullSData(oldp+17,((vlSelf->top__DOT__IR 
                              >> 0x14U)),12);
    bufp->fullBit(oldp+18,((vlSelf->top__DOT__IR >> 0x1fU)));
    bufp->fullIData(oldp+19,(vlSelf->top__DOT__ifetch__DOT__pc),32);
    bufp->fullIData(oldp+20,(vlSelf->top__DOT__regs__DOT__regs[0]),32);
    bufp->fullIData(oldp+21,(vlSelf->top__DOT__regs__DOT__regs[1]),32);
    bufp->fullIData(oldp+22,(vlSelf->top__DOT__regs__DOT__regs[2]),32);
    bufp->fullIData(oldp+23,(vlSelf->top__DOT__regs__DOT__regs[3]),32);
    bufp->fullIData(oldp+24,(vlSelf->top__DOT__regs__DOT__regs[4]),32);
    bufp->fullIData(oldp+25,(vlSelf->top__DOT__regs__DOT__regs[5]),32);
    bufp->fullIData(oldp+26,(vlSelf->top__DOT__regs__DOT__regs[6]),32);
    bufp->fullIData(oldp+27,(vlSelf->top__DOT__regs__DOT__regs[7]),32);
    bufp->fullIData(oldp+28,(vlSelf->top__DOT__regs__DOT__regs[8]),32);
    bufp->fullIData(oldp+29,(vlSelf->top__DOT__regs__DOT__regs[9]),32);
    bufp->fullIData(oldp+30,(vlSelf->top__DOT__regs__DOT__regs[10]),32);
    bufp->fullIData(oldp+31,(vlSelf->top__DOT__regs__DOT__regs[11]),32);
    bufp->fullIData(oldp+32,(vlSelf->top__DOT__regs__DOT__regs[12]),32);
    bufp->fullIData(oldp+33,(vlSelf->top__DOT__regs__DOT__regs[13]),32);
    bufp->fullIData(oldp+34,(vlSelf->top__DOT__regs__DOT__regs[14]),32);
    bufp->fullIData(oldp+35,(vlSelf->top__DOT__regs__DOT__regs[15]),32);
    bufp->fullIData(oldp+36,(vlSelf->top__DOT__regs__DOT__regs[16]),32);
    bufp->fullIData(oldp+37,(vlSelf->top__DOT__regs__DOT__regs[17]),32);
    bufp->fullIData(oldp+38,(vlSelf->top__DOT__regs__DOT__regs[18]),32);
    bufp->fullIData(oldp+39,(vlSelf->top__DOT__regs__DOT__regs[19]),32);
    bufp->fullIData(oldp+40,(vlSelf->top__DOT__regs__DOT__regs[20]),32);
    bufp->fullIData(oldp+41,(vlSelf->top__DOT__regs__DOT__regs[21]),32);
    bufp->fullIData(oldp+42,(vlSelf->top__DOT__regs__DOT__regs[22]),32);
    bufp->fullIData(oldp+43,(vlSelf->top__DOT__regs__DOT__regs[23]),32);
    bufp->fullIData(oldp+44,(vlSelf->top__DOT__regs__DOT__regs[24]),32);
    bufp->fullIData(oldp+45,(vlSelf->top__DOT__regs__DOT__regs[25]),32);
    bufp->fullIData(oldp+46,(vlSelf->top__DOT__regs__DOT__regs[26]),32);
    bufp->fullIData(oldp+47,(vlSelf->top__DOT__regs__DOT__regs[27]),32);
    bufp->fullIData(oldp+48,(vlSelf->top__DOT__regs__DOT__regs[28]),32);
    bufp->fullIData(oldp+49,(vlSelf->top__DOT__regs__DOT__regs[29]),32);
    bufp->fullIData(oldp+50,(vlSelf->top__DOT__regs__DOT__regs[30]),32);
    bufp->fullIData(oldp+51,(vlSelf->top__DOT__regs__DOT__regs[31]),32);
    bufp->fullIData(oldp+52,(vlSelf->top__DOT__regs__DOT__unnamedblk1__DOT__i),32);
    bufp->fullBit(oldp+53,(vlSelf->reset));
    bufp->fullBit(oldp+54,(vlSelf->clock));
    bufp->fullIData(oldp+55,(5U),32);
    bufp->fullIData(oldp+56,(0x20U),32);
}
