;buildInfoPackage: chisel3, version: 3.4.2, scalaVersion: 2.12.12, sbtVersion: 1.3.10
circuit Mux2 : 
  extmodule mux2 : 
    input D0 : UInt<1>
    input D1 : UInt<1>
    input S : UInt<1>
    output Y : UInt<1>
    
    defname = mux2
    
    
  module Mux2 : 
    input clock : Clock
    input reset : UInt<1>
    output io : {flip D0 : UInt<1>, flip D1 : UInt<1>, flip S : UInt<1>, Y : UInt<1>}
    
    inst a of mux2 @[Mux2.scala 28:19]
    a.Y is invalid
    a.S is invalid
    a.D1 is invalid
    a.D0 is invalid
    io.Y <= a.Y @[Mux2.scala 30:10]
    a.S <= io.S @[Mux2.scala 30:10]
    a.D1 <= io.D1 @[Mux2.scala 30:10]
    a.D0 <= io.D0 @[Mux2.scala 30:10]
    
