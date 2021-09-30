module Alu(
  input        clock,
  input        reset,
  input  [7:0] io_A,
  input  [7:0] io_B,
  input  [3:0] io_ALU_Sel,
  output [7:0] io_ALU_Out,
  output       io_CarryOut
);
  wire [7:0] a_A; // @[Alu.scala 39:19]
  wire [7:0] a_B; // @[Alu.scala 39:19]
  wire [3:0] a_ALU_Sel; // @[Alu.scala 39:19]
  wire [7:0] a_ALU_Out; // @[Alu.scala 39:19]
  wire  a_CarryOut; // @[Alu.scala 39:19]
  alu a ( // @[Alu.scala 39:19]
    .A(a_A),
    .B(a_B),
    .ALU_Sel(a_ALU_Sel),
    .ALU_Out(a_ALU_Out),
    .CarryOut(a_CarryOut)
  );
  assign io_ALU_Out = a_ALU_Out; // @[Alu.scala 41:10]
  assign io_CarryOut = a_CarryOut; // @[Alu.scala 41:10]
  assign a_A = io_A; // @[Alu.scala 41:10]
  assign a_B = io_B; // @[Alu.scala 41:10]
  assign a_ALU_Sel = io_ALU_Sel; // @[Alu.scala 41:10]
endmodule
