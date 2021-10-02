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
        c.io.ALU_Sel.poke(0.U)
        c.clock.step(1)
        c.io.ALU_Sel.poke(1.U)
        c.clock.step(1)
        c.io.ALU_Sel.poke(2.U)
        c.clock.step(1)
        c.io.ALU_Sel.poke(3.U)
        c.clock.step(1)
        c.io.ALU_Sel.poke(4.U)
        c.clock.step(1)
        c.io.ALU_Sel.poke(5.U)
        c.clock.step(1)
        c.io.ALU_Sel.poke(6.U)
        c.clock.step(1)
        c.io.ALU_Sel.poke(7.U)
        c.clock.step(1)
        c.io.ALU_Sel.poke(8.U)
        c.clock.step(1)
        c.io.ALU_Sel.poke(9.U)
        c.clock.step(1)
        c.io.ALU_Sel.poke(10.U)
        c.clock.step(1)
        c.io.ALU_Sel.poke(11.U)
        c.clock.step(1)
        c.io.ALU_Sel.poke(12.U)
        c.clock.step(1)
        c.io.ALU_Sel.poke(13.U)
        c.clock.step(1)
        c.io.ALU_Sel.poke(14.U)
        c.clock.step(1)
        c.io.ALU_Sel.poke(15.U)
        c.clock.step(20)
    }
  }
}