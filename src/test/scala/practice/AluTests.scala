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



class AluTests extends FreeSpec with ChiselScalatestTester {

  "ALU - Arithmetic Logical Unit" in {
    test(new Alu()).withAnnotations(Seq(VerilatorBackendAnnotation)) { c =>
        c.io.A.poke(4.U)
        c.io.B.poke(3.U)
        c.io.ALU_Sel.poke(2.U)
        // c.io.ALU_Out.poke(3.U)

        
        // c.io.i_clk.poke(Clock().asInstanceOf[Bool])
        
        // c.io.clk.poke(clock.asUInt()(0).asClock())
        // c.io.rst_n.poke(0.B)
        // c.io.data_in.poke(8.U)
        // c.io.start.poke(1.B)


        c.clock.step(20)
    }
  }
}