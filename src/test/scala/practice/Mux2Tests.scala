package practice

import chisel3._
import chisel3 . util._
import org.scalatest._
import chisel3.experimental._
import chiseltest._
import chisel3.experimental.BundleLiterals._
import chiseltest.experimental.TestOptionBuilder._
import chiseltest.internal.VerilatorBackendAnnotation
// import org.scalatest.flatspec.AnyFlatSpec



class Mux2Tests extends FreeSpec with ChiselScalatestTester {

  "Multiplexer 2-BIT" in {
    test(new Mux2()).withAnnotations(Seq(VerilatorBackendAnnotation)) { c =>
        c.io.D0.poke(1.B)
        c.io.D1.poke(0.B)
        c.io.S.poke(1.B)
        c.clock.step(20)
    
    }
  }
}