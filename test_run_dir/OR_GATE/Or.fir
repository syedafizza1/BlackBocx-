;buildInfoPackage: chisel3, version: 3.4.2, scalaVersion: 2.12.12, sbtVersion: 1.3.10
circuit Or : 
  extmodule orGate : 
    input A : UInt<1>
    input B : UInt<1>
    output Y : UInt<1>
    
    defname = orGate
    
    
  module Or : 
    input clock : Clock
    input reset : UInt<1>
    output io : {flip A : UInt<1>, flip B : UInt<1>, Y : UInt<1>}
    
    inst a of orGate @[Or.scala 32:19]
    a.Y is invalid
    a.B is invalid
    a.A is invalid
    io.Y <= a.Y @[Or.scala 34:10]
    a.B <= io.B @[Or.scala 34:10]
    a.A <= io.A @[Or.scala 34:10]
    
