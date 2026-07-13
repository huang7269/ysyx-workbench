#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtop.h"
#include <iostream>
#include "utils.h"

int is_exit_status();

int main(int argc, char **argv) {
    VerilatedContext* contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);

    // 实例化顶层模块
    Vtop* top = new Vtop(contextp);

    // 开启波形转储
    VerilatedVcdC* tfp = new VerilatedVcdC;
    contextp->traceEverOn(true);
    top->trace(tfp, 99);
    tfp->open("wave.vcd");

    // ---------- 仿真参数 ----------
    const int sim_cycles = 100;        // 运行100个时钟周期
    const int clk_half = 5;            // 时钟半周期（对应 timescale 1ns，即5ns半周期，周期10ns）

    // ---------- 初始状态（高有效复位） ----------
    top->reset = 1;              // 复位有效（高电平）
    top->clock = 0;

    // ---------- 主循环 ----------
    for (int cycle = 0; cycle < sim_cycles; cycle++) {

        // ----- 时钟低半周期 -----
        top->clock = 0;

        // 高有效复位逻辑：前2个周期保持复位有效，之后释放
        if (cycle < 2) {
            top->reset = 1;      // 保持复位
        } else {
            top->reset = 0;      // 释放复位（开始正常工作）
        }

        top->eval();                             // 评估组合逻辑
        tfp->dump(cycle * 2 * clk_half);         // 写入波形

        // ----- 时钟高半周期 -----
        top->clock = 1;
        top->eval();
        tfp->dump(cycle * 2 * clk_half + clk_half);

        if(is_exit_status()) {
            std::cout << "Hit ebreak, stop simulation early." << std::endl;
            break;
        }
    }

    // ---------- 收尾 ----------
    tfp->close();
    delete tfp;
    delete top;
    delete contextp;

    std::cout << "Simulation finished." << std::endl;
    return 0;
}