`timescale 1ns / 1ps

module Alu (
    input  wire [3:0]  alu_ctrl,
    input  wire        AluSrc,
    input  wire [31:0] rs1,
    input  wire [31:0] rs2,
    input  wire [31:0] immediate,
    output reg  [31:0] Alu_result
);
    wire [31:0] Ainput;
    wire [31:0] Binput;

    assign Ainput = rs1;
    assign Binput = (AluSrc == 1'b1) ? immediate : rs2;

    always @(*) begin
        case (alu_ctrl)
            4'b0001: Alu_result =  Ainput + Binput;

            default: Alu_result = 32'd0;
        endcase
    end
    
endmodule
