`timescale 1ns / 1ps

module top (
    input wire reset,
    input wire clock
);

    //dpi-c ebreak
    import "DPI-C" function void ebreak();
    always @(posedge clock) begin
        if(!reset && instruction == 32'b0000000_00001_00000_000_00000_1110011) begin
            ebreak();
        end
    end

    wire [31:0] instruction;
    wire [31:0] pc_plus;
    wire [31:0] rom_inst;
    wire [31:0] instruction_imm;
    wire [4:0]  rs1;
    wire [4:0]  rs2;
    wire [4:0]  rd;
    wire [6:0]  opcode;
    wire [2:0]  funct3;
    wire [31:0] rdata_1;
    wire [31:0] rdata_2;
    wire [3:0]  alu_ctrl;
    wire [31:0] alu_result;

    //control sign
    wire        RegWrite;
    wire        AluSrc;
    wire [2:0]  Aluop;

    assign opcode = instruction[6:0];
    assign funct3 = instruction[14:12];

    Rom rom (
        .pc                    (pc_plus),
        .instruction           (rom_inst)
    );

    Ifetc ifetch (
        .reset                 (reset),
        .clock                 (clock),
        .instruction           (instruction),
        .pc_plus_4             (pc_plus),
        .rom_inst              (rom_inst)
    );

    Idecode idecode (
        .instruction           (instruction),
        .instruction_imm       (instruction_imm),
        .read_register_addr_1  (rs1),
        .read_register_addr_2  (rs2),
        .write_register_addr   (rd)
    );
    
    Icontrol icontrol (
        .opcode                (opcode),
        .funct3                (funct3),
        .RegWrite              (RegWrite),
        .AluSrc                (AluSrc),
        .Aluop                 (Aluop)
    );

    RegisterFile regs (
        .reset                 (reset),
        .clock                 (clock),
        .wdata                 (alu_result),
        .waddr                 (rd),
        .RegWrite              (RegWrite),
        .raddr1                (rs1),
        .raddr2                (rs2),
        .rdata1_out            (rdata_1),
        .rdata2_out            (rdata_2)            
    );

    Alu_control alu_ctl (
        .Aluop                 (Aluop),
        .alu_ctrl              (alu_ctrl)
    );

    Alu alu (
        .alu_ctrl              (alu_ctrl),
        .AluSrc                (AluSrc),
        .rs1                   (rdata_1),
        .rs2                   (rdata_2),
        .immediate             (instruction_imm),
        .Alu_result            (alu_result)
    );

endmodule
