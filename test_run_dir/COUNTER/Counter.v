module Counter(
  input        clock,
  input        reset,
  output [3:0] io_output
);
  wire  a_clk; // @[Counter.scala 35:19]
  wire  a_reset; // @[Counter.scala 35:19]
  wire [3:0] a_counter; // @[Counter.scala 35:19]
  counter a ( // @[Counter.scala 35:19]
    .clk(a_clk),
    .reset(a_reset),
    .counter(a_counter)
  );
  assign io_output = a_counter; // @[Counter.scala 40:15]
  assign a_clk = ~clock; // @[Counter.scala 37:17]
  assign a_reset = reset; // @[Counter.scala 38:38]
endmodule
