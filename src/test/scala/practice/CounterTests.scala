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



class CounterTests extends FreeSpec with ChiselScalatestTester {

  "COUNTER" in {
    test(new Counter()).withAnnotations(Seq(VerilatorBackendAnnotation)) { c =>
        // c.io.A.poke(0.B)
        // c.io.B.poke(1.B)
        
        // c.io.i_clk.poke(Clock().asInstanceOf[Bool])
        
        // c.io.clk.poke(clock.asUInt()(0).asClock())
        // c.io.rst_n.poke(0.B)
        // c.io.data_in.poke(8.U)
        // c.io.start.poke(1.B)


        c.clock.step(20)
    }
  }
}