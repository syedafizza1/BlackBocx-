module Mux2(
  input   clock,
  input   reset,
  input   io_D0,
  input   io_D1,
  input   io_S,
  output  io_Y
);
  wire  a_D0; // @[Mux2.scala 28:19]
  wire  a_D1; // @[Mux2.scala 28:19]
  wire  a_S; // @[Mux2.scala 28:19]
  wire  a_Y; // @[Mux2.scala 28:19]
  mux2 a ( // @[Mux2.scala 28:19]
    .D0(a_D0),
    .D1(a_D1),
    .S(a_S),
    .Y(a_Y)
  );
  assign io_Y = a_Y; // @[Mux2.scala 30:10]
  assign a_D0 = io_D0; // @[Mux2.scala 30:10]
  assign a_D1 = io_D1; // @[Mux2.scala 30:10]
  assign a_S = io_S; // @[Mux2.scala 30:10]
endmodule
