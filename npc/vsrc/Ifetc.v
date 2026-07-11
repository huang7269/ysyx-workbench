`timescale 1ns / 1ps

module Ifetc (
    input  wire         reset,
    input  wire         clock,
    output wire  [31:0] Instruction,
    output wire  [31:0] PC_PLUS_4_out,
    input  wire  [31:0] IR
);
    wire [31:0] pc_plus_4;
    reg  [31:0] pc;
    reg  [31:0] next_pc;

    assign Instruction = IR;

    assign pc_plus_4[31:2] = pc[31:2] + 1'b1;
    assign pc_plus_4[1:0]  = 2'b00;
    assign PC_PLUS_4_out = pc_plus_4;

    always @(*) begin
        next_pc = pc_plus_4; 
    end

    always @(posedge clock) begin
        if(reset) begin
            pc <= 32'h7fff_fffc;
        end else begin
            pc <= next_pc;
        end
    end 

endmodule
