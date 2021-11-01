;buildInfoPackage: chisel3, version: 3.4.2, scalaVersion: 2.12.12, sbtVersion: 1.3.10
circuit MDU : 
  extmodule mdu : 
    input i_clk : UInt<1>
    input i_rst : UInt<1>
    input i_mdu_rs1 : UInt<32>
    input i_mdu_rs2 : UInt<32>
    input i_mdu_op : UInt<3>
    input i_mdu_valid : UInt<1>
    output o_mdu_ready : UInt<1>
    output o_mdu_rd : UInt<32>
    
    defname = mdu
    
    
  module MDU : 
    input clock : Clock
    input reset : UInt<1>
    output io : {flip i_mdu_rs1 : UInt<32>, flip i_mdu_rs2 : UInt<32>, flip i_mdu_op : UInt<3>, flip i_mdu_valid : UInt<1>, o_mdu_ready : UInt<1>, o_mdu_rd : UInt<32>}
    
    inst a of mdu @[MDU.scala 47:19]
    a.o_mdu_rd is invalid
    a.o_mdu_ready is invalid
    a.i_mdu_valid is invalid
    a.i_mdu_op is invalid
    a.i_mdu_rs2 is invalid
    a.i_mdu_rs1 is invalid
    a.i_rst is invalid
    a.i_clk is invalid
    node _i_clk_T = asUInt(clock) @[MDU.scala 48:38]
    node _i_clk_T_1 = bits(_i_clk_T, 0, 0) @[MDU.scala 48:40]
    wire i_clk : UInt<1>
    i_clk <= _i_clk_T_1
    node _i_rst_T = asUInt(clock) @[MDU.scala 49:38]
    node _i_rst_T_1 = bits(_i_rst_T, 0, 0) @[MDU.scala 49:40]
    wire i_rst : UInt<1>
    i_rst <= _i_rst_T_1
    node _a_io_i_clk_T = not(i_clk) @[MDU.scala 52:19]
    a.i_clk <= _a_io_i_clk_T @[MDU.scala 52:16]
    a.i_rst <= i_rst @[MDU.scala 53:16]
    a.i_mdu_rs1 <= io.i_mdu_rs1 @[MDU.scala 54:20]
    a.i_mdu_rs2 <= io.i_mdu_rs2 @[MDU.scala 55:20]
    a.i_mdu_op <= io.i_mdu_op @[MDU.scala 56:19]
    a.i_mdu_valid <= io.i_mdu_valid @[MDU.scala 57:22]
    io.o_mdu_ready <= a.o_mdu_ready @[MDU.scala 58:20]
    io.o_mdu_rd <= a.o_mdu_rd @[MDU.scala 59:17]
    
