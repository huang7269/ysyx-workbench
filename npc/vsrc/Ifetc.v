`timescale 1ns / 1ps

module Ifetc (
    input  wire         reset,
    input  wire         clock,
    output wire  [31:0] instruction,
    output wire  [31:0] pc_plus_4,
    input  wire  [31:0] rom_inst
);

    reg  [31:0] pc;
    reg  [31:0] next_pc;

    assign pc_plus_4[31:2] = pc[31:2] + 1'b1;
    assign pc_plus_4[1:0] = 2'b00;  

    initial begin
        pc = 32'h7ffffffc;
    end
    assign instruction = rom_inst;


    always @(*) begin
        next_pc = pc_plus_4; 
    end

    always @(posedge clock) begin
        if(reset) begin
            pc <= 32'h7ffffffc;
        end else begin
            pc <= next_pc;
        end
    end 

endmodule
