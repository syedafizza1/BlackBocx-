//module up_counter(input clk, reset, output[3:0] counter

package practice

import chisel3._
import chisel3.util._
import chisel3.experimental._

class IOd extends Bundle{
    val clk = Input(Bool())
    val reset = Input(Bool())
    val counter = Output(UInt(4.W))
    // clock    input(bool)
    // reset    == = = = = 
}

class counter extends BlackBox with HasBlackBoxResource{
    val io = IO(new IOd)
    addResource("/counter.v")
    
}

class Counter extends Module{

    val io = IO(new Bundle{
        val output = Output(UInt(4.W))

    })

    // val io = IO(new Bundle{
    //     a
    //     B
    //     sum
    // })
    val a = Module(new counter)
    val clk = WireInit(clock.asUInt()(0))
    a.io.clk := ~clk
    val rst = WireInit(reset.asUInt()(0))
    a.io.reset := rst
    io.output := a.io.counter
   

    //a.io <> io

}