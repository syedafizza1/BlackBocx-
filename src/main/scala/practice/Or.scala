package practice

import chisel3._
import chisel3.util._
import chisel3.experimental._

class IO_2 extends Bundle{
    val A = Input(Bool())
    val B = Input(Bool())
    val Y = Output(Bool())
    // clock    input(bool)
    // reset    == = = = = 
}

class orGate extends BlackBox with HasBlackBoxResource{
    val io = IO(new IO_2)
    addResource("/orGate.v")
}

class Or extends Module{

    val io = IO(new IO_2)

    // val io = IO(new Bundle{
    //     a
    //     B
    //     sum
    // })
    // val clk = WireInit(clock.asUInt()(0))
    // a.io.clock := ~clk

    val a = Module(new orGate)

    a.io <> io

}