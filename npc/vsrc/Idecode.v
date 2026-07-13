`timescale 1ns / 1ps

module Idecode (
    input  wire [31:0] instruction,
    output wire [31:0] instruction_imm,
    output wire [4:0]  read_register_addr_1,   //rs1
    output wire [4:0]  read_register_addr_2,   //rs2
    output wire [4:0]  write_register_addr    //rd
);
    
    wire [11:0] I_immediate;
    wire sign;

    assign read_register_addr_1 = instruction[19:15];
    assign read_register_addr_2 = instruction[24:20];
    assign write_register_addr = instruction[11:7];

    assign sign = instruction[31];
    assign I_immediate = instruction[31:20];
    assign instruction_imm = {{20{sign}},I_immediate};


endmodule
