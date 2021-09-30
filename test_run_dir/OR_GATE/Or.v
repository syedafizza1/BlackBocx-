module Or(
  input   clock,
  input   reset,
  input   io_A,
  input   io_B,
  output  io_Y
);
  wire  a_A; // @[Or.scala 32:19]
  wire  a_B; // @[Or.scala 32:19]
  wire  a_Y; // @[Or.scala 32:19]
  orGate a ( // @[Or.scala 32:19]
    .A(a_A),
    .B(a_B),
    .Y(a_Y)
  );
  assign io_Y = a_Y; // @[Or.scala 34:10]
  assign a_A = io_A; // @[Or.scala 34:10]
  assign a_B = io_B; // @[Or.scala 34:10]
endmodule
