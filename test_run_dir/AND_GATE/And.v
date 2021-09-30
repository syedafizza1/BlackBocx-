module And(
  input   clock,
  input   reset,
  input   io_A,
  input   io_B,
  output  io_Y
);
  wire  a_A; // @[And.scala 32:19]
  wire  a_B; // @[And.scala 32:19]
  wire  a_Y; // @[And.scala 32:19]
  andGate a ( // @[And.scala 32:19]
    .A(a_A),
    .B(a_B),
    .Y(a_Y)
  );
  assign io_Y = a_Y; // @[And.scala 34:10]
  assign a_A = io_A; // @[And.scala 34:10]
  assign a_B = io_B; // @[And.scala 34:10]
endmodule
