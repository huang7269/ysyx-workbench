`timescale 1ns / 1ps

module top (
    input wire reset,
    input wire clock
);

    wire [31:0] Instruction;
    wire [31:0] PC_PLUS_4;
    wire [31:0] IR;
    wire [31:0] Instruction_imm;
    wire [4:0]  rs1;
    wire [4:0]  rs2;
    wire [4:0]  rd;
    wire [6:0]  opcode;
    wire [2:0]  fun_1;
    wire [31:0] rdata_1;
    wire [31:0] rdata_2;
    wire [3:0]  alu_ctrl;
    wire [31:0] alu_result;

    //control sign
    wire        RegWrite;
    wire        AluSrc;
    wire [2:0]  Aluop;

    assign opcode = Instruction[6:0];
    assign fun_1  = Instruction[14:12];

    Rom rom (
        .PC                    (PC_PLUS_4),
        .Instruction           (IR)
    );

    Ifetc ifetch (
        .reset                 (reset),
        .clock                 (clock),
        .Instruction           (Instruction),
        .PC_PLUS_4_out         (PC_PLUS_4),
        .IR                    (IR)
    );

    Idecode idecode (
        .Instruction           (IR),
        .Instruction_imm       (Instruction_imm),
        .read_register_addr_1  (rs1),
        .read_register_addr_2  (rs2),
        .write_register_addr   (rd)
    );
    
    Icontrol iconctrol (
        .opcode                (opcode),
        .fun_1                 (fun_1),
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
        .Immediate             (Instruction_imm),
        .Alu_result            (alu_result)
    );

endmodule
