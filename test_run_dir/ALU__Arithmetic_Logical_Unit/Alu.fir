;buildInfoPackage: chisel3, version: 3.4.2, scalaVersion: 2.12.12, sbtVersion: 1.3.10
circuit Alu : 
  extmodule alu : 
    input A : UInt<8>
    input B : UInt<8>
    input ALU_Sel : UInt<4>
    output ALU_Out : UInt<8>
    output CarryOut : UInt<1>
    
    defname = alu
    
    
  module Alu : 
    input clock : Clock
    input reset : UInt<1>
    output io : {flip A : UInt<8>, flip B : UInt<8>, flip ALU_Sel : UInt<4>, ALU_Out : UInt<8>, CarryOut : UInt<1>}
    
    inst a of alu @[Alu.scala 39:19]
    a.CarryOut is invalid
    a.ALU_Out is invalid
    a.ALU_Sel is invalid
    a.B is invalid
    a.A is invalid
    io.CarryOut <= a.CarryOut @[Alu.scala 41:10]
    io.ALU_Out <= a.ALU_Out @[Alu.scala 41:10]
    a.ALU_Sel <= io.ALU_Sel @[Alu.scala 41:10]
    a.B <= io.B @[Alu.scala 41:10]
    a.A <= io.A @[Alu.scala 41:10]
    
