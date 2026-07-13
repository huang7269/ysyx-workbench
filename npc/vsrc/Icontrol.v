`timescale 1ns / 1ps

module Icontrol(
    input wire [6:0] opcode,
    input wire [2:0] funct3,
    output wire RegWrite,
    output wire AluSrc,
    output wire [2:0] Aluop
);

    wire I_format;

    assign I_format = (opcode == 7'b0010011);

    assign RegWrite = I_format;
    assign AluSrc = (I_format && funct3 == 3'b100);
    assign Aluop = (I_format == 1'b1) ? 3'b001 : 3'b000;

endmodule
