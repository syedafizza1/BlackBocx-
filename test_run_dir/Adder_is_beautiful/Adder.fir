;buildInfoPackage: chisel3, version: 3.4.2, scalaVersion: 2.12.12, sbtVersion: 1.3.10
circuit Adder : 
  extmodule adder : 
    input a : UInt<4>
    input b : UInt<4>
    output sum : UInt<4>
    
    defname = adder
    
    
  module Adder : 
    input clock : Clock
    input reset : UInt<1>
    output io : {flip a : UInt<4>, flip b : UInt<4>, sum : UInt<4>}
    
    inst a of adder @[Adder.scala 32:19]
    a.sum is invalid
    a.b is invalid
    a.a is invalid
    io.sum <= a.sum @[Adder.scala 34:10]
    a.b <= io.b @[Adder.scala 34:10]
    a.a <= io.a @[Adder.scala 34:10]
    
