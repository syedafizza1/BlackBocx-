package practice

import chisel3._
import chisel3.util._
import chisel3.experimental._

class IOs extends Bundle{
    val A = Input(Bool())
    val B = Input(Bool())
    val Y = Output(Bool())
    // clock    input(bool)
    // reset    == = = = = 
}

class andGate extends BlackBox with HasBlackBoxResource{
    val io = IO(new IOs)
    addResource("/andGate.v")
}

class And extends Module{

    val io = IO(new IOs)

    // val io = IO(new Bundle{
    //     a
    //     B
    //     sum
    // })
    // val clk = WireInit(clock.asUInt()(0))
    // a.io.clock := ~clk

    val a = Module(new andGate)

    a.io <> io

}