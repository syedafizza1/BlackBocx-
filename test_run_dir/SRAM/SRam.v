module SRam(
  input         clock,
  input         reset,
  input         io_clk0,
  input         io_csb0,
  input         io_web0,
  input  [6:0]  io_addr0,
  input  [31:0] io_din0,
  output [31:0] io_dout0
);
  wire  a_clk0; // @[SRam.scala 47:19]
  wire  a_csb0; // @[SRam.scala 47:19]
  wire  a_web0; // @[SRam.scala 47:19]
  wire [6:0] a_addr0; // @[SRam.scala 47:19]
  wire [31:0] a_din0; // @[SRam.scala 47:19]
  wire [31:0] a_dout0; // @[SRam.scala 47:19]
  sram a ( // @[SRam.scala 47:19]
    .clk0(a_clk0),
    .csb0(a_csb0),
    .web0(a_web0),
    .addr0(a_addr0),
    .din0(a_din0),
    .dout0(a_dout0)
  );
  assign io_dout0 = a_dout0; // @[SRam.scala 57:14]
  assign a_clk0 = ~clock; // @[SRam.scala 50:18]
  assign a_csb0 = io_csb0; // @[SRam.scala 51:15]
  assign a_web0 = io_web0; // @[SRam.scala 52:15]
  assign a_addr0 = io_addr0; // @[SRam.scala 53:16]
  assign a_din0 = io_din0; // @[SRam.scala 54:15]
endmodule
