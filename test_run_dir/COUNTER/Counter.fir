;buildInfoPackage: chisel3, version: 3.4.2, scalaVersion: 2.12.12, sbtVersion: 1.3.10
circuit Counter : 
  extmodule counter : 
    input clk : UInt<1>
    input reset : UInt<1>
    output counter : UInt<4>
    
    defname = counter
    
    
  module Counter : 
    input clock : Clock
    input reset : UInt<1>
    output io : {output : UInt<4>}
    
    inst a of counter @[Counter.scala 35:19]
    a.counter is invalid
    a.reset is invalid
    a.clk is invalid
    node _clk_T = asUInt(clock) @[Counter.scala 36:36]
    node _clk_T_1 = bits(_clk_T, 0, 0) @[Counter.scala 36:38]
    wire clk : UInt<1>
    clk <= _clk_T_1
    node _a_io_clk_T = not(clk) @[Counter.scala 37:17]
    a.clk <= _a_io_clk_T @[Counter.scala 37:14]
    node _rst_T = bits(reset, 0, 0) @[Counter.scala 38:38]
    wire rst : UInt<1>
    rst <= _rst_T
    a.reset <= rst @[Counter.scala 39:16]
    io.output <= a.counter @[Counter.scala 40:15]
    
