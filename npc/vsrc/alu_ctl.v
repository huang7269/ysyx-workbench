`timescale 1ns / 1ps

module Alu_control (
    input wire [2:0] Aluop,
    output wire [3:0] alu_ctrl
);
    assign alu_ctrl = (Aluop == 3'b001) ? 4'b0001 : 4'b0000;
    
endmodule
