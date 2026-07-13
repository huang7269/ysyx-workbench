`timescale 1ns / 1ps

module RegisterFile #(ADDR_WIDTH = 5, DATA_WIDTH = 32) (
  input  wire                   reset,
  input  wire                   clock,
  input  wire  [DATA_WIDTH-1:0] wdata,
  input  wire  [ADDR_WIDTH-1:0] waddr,
  input  wire                   RegWrite,
  input  wire  [ADDR_WIDTH-1:0] raddr1,
  input  wire  [ADDR_WIDTH-1:0] raddr2,
  output wire  [DATA_WIDTH-1:0] rdata1_out,
  output wire  [DATA_WIDTH-1:0] rdata2_out
);
  reg [DATA_WIDTH-1:0] regs [2**ADDR_WIDTH-1:0];

  assign rdata1_out = (raddr1 == 0) ? 32'd0 : regs[raddr1];
  assign rdata2_out = (raddr2 == 0) ? 32'd0 : regs[raddr2];

  always @(posedge clock) begin
    if (!reset && RegWrite && (waddr != 0)) begin
        regs[waddr] <= wdata;
    end
  end
endmodule
