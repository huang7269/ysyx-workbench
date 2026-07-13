`timescale 1ns / 1ps

module Rom (
    input  wire [31:0] pc,
    output reg  [31:0] instruction
);

    always @(*) begin
        case(pc)
            32'h80000000: instruction = 32'b000000000001_00001_100_00001_0010011;  // addi: rd = rs1 + imm
            32'h80000004: instruction = 32'b000000000010_00001_100_00001_0010011;
            32'h80000008: instruction = 32'b000000000011_00001_100_00001_0010011;
            32'h8000000c: instruction = 32'b000000000100_00001_100_00001_0010011;
            32'h80000010: instruction = 32'b0000000_00001_00000_000_00000_1110011;  //ebreak
            32'h80000014: instruction = 32'b000000000101_00001_100_00001_0010011;

            default: instruction = 32'b0000000_00001_00000_000_00000_1110011; // ebreak
        endcase
    end
endmodule
