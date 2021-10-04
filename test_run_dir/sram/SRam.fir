;buildInfoPackage: chisel3, version: 3.4.2, scalaVersion: 2.12.12, sbtVersion: 1.3.10
circuit SRam : 
  extmodule sram : 
    input clk0 : UInt<1>
    input csb0 : UInt<1>
    input web0 : UInt<1>
    input addr0 : UInt<7>
    input din0 : UInt<32>
    output dout0 : UInt<32>
    
    defname = sram
    
    
  module SRam : 
    input clock : Clock
    input reset : UInt<1>
    output io : {flip clk0 : UInt<1>, flip csb0 : UInt<1>, flip web0 : UInt<1>, flip addr0 : UInt<7>, flip din0 : UInt<32>, dout0 : UInt<32>}
    
    inst a of sram @[SRam.scala 86:19]
    a.dout0 is invalid
    a.din0 is invalid
    a.addr0 is invalid
    a.web0 is invalid
    a.csb0 is invalid
    a.clk0 is invalid
    node _clk_T = asUInt(clock) @[SRam.scala 89:36]
    node _clk_T_1 = bits(_clk_T, 0, 0) @[SRam.scala 89:38]
    wire clk : UInt<1>
    clk <= _clk_T_1
    node _a_io_clk0_T = not(clk) @[SRam.scala 90:18]
    a.clk0 <= _a_io_clk0_T @[SRam.scala 90:15]
    a.csb0 <= io.csb0 @[SRam.scala 91:14]
    a.web0 <= io.web0 @[SRam.scala 92:14]
    a.addr0 <= io.addr0 @[SRam.scala 93:15]
    a.din0 <= io.din0 @[SRam.scala 94:14]
    io.dout0 <= a.dout0 @[SRam.scala 95:14]
    
