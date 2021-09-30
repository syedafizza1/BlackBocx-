module Adder(
  input        clock,
  input        reset,
  input  [3:0] io_a,
  input  [3:0] io_b,
  output [3:0] io_sum
);
  wire [3:0] a_a; // @[Adder.scala 32:19]
  wire [3:0] a_b; // @[Adder.scala 32:19]
  wire [3:0] a_sum; // @[Adder.scala 32:19]
  adder a ( // @[Adder.scala 32:19]
    .a(a_a),
    .b(a_b),
    .sum(a_sum)
  );
  assign io_sum = a_sum; // @[Adder.scala 34:10]
  assign a_a = io_a; // @[Adder.scala 34:10]
  assign a_b = io_b; // @[Adder.scala 34:10]
endmodule
