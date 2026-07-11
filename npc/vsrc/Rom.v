`timescale 1ns / 1ps

module Rom (
    input  wire [31:0] PC,
    output reg  [31:0] Instruction
);

    always @(*) begin
        case(PC)
            32'h80000000: Instruction = 32'b000000000001_00001_100_00001_0010011;  // addi: rd = rs1 + imm
            32'h80000004: Instruction = 32'b000000000010_00001_100_00001_0010011;
            32'h80000008: Instruction = 32'b000000000011_00001_100_00001_0010011;

            default: Instruction = 32'b0000000_00001_00000_000_00000_1110011; // ebreak
        endcase
    end
endmodule
