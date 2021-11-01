module MDU(
  input         clock,
  input         reset,
  input  [31:0] io_i_mdu_rs1,
  input  [31:0] io_i_mdu_rs2,
  input  [2:0]  io_i_mdu_op,
  input         io_i_mdu_valid,
  output        io_o_mdu_ready,
  output [31:0] io_o_mdu_rd
);
  wire  a_i_clk; // @[MDU.scala 47:19]
  wire  a_i_rst; // @[MDU.scala 47:19]
  wire [31:0] a_i_mdu_rs1; // @[MDU.scala 47:19]
  wire [31:0] a_i_mdu_rs2; // @[MDU.scala 47:19]
  wire [2:0] a_i_mdu_op; // @[MDU.scala 47:19]
  wire  a_i_mdu_valid; // @[MDU.scala 47:19]
  wire  a_o_mdu_ready; // @[MDU.scala 47:19]
  wire [31:0] a_o_mdu_rd; // @[MDU.scala 47:19]
  mdu a ( // @[MDU.scala 47:19]
    .i_clk(a_i_clk),
    .i_rst(a_i_rst),
    .i_mdu_rs1(a_i_mdu_rs1),
    .i_mdu_rs2(a_i_mdu_rs2),
    .i_mdu_op(a_i_mdu_op),
    .i_mdu_valid(a_i_mdu_valid),
    .o_mdu_ready(a_o_mdu_ready),
    .o_mdu_rd(a_o_mdu_rd)
  );
  assign io_o_mdu_ready = a_o_mdu_ready; // @[MDU.scala 58:20]
  assign io_o_mdu_rd = a_o_mdu_rd; // @[MDU.scala 59:17]
  assign a_i_clk = ~clock; // @[MDU.scala 52:19]
  assign a_i_rst = clock; // @[MDU.scala 49:38]
  assign a_i_mdu_rs1 = io_i_mdu_rs1; // @[MDU.scala 54:20]
  assign a_i_mdu_rs2 = io_i_mdu_rs2; // @[MDU.scala 55:20]
  assign a_i_mdu_op = io_i_mdu_op; // @[MDU.scala 56:19]
  assign a_i_mdu_valid = io_i_mdu_valid; // @[MDU.scala 57:22]
endmodule
