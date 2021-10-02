// output Y;
// input D0, D1, S;
// wire T1, T2, Sbar;

//module up_counter(input clk, reset, output[3:0] counter

package practice

import chisel3._
import chisel3.util._
import chisel3.experimental._

class IOm extends Bundle{
    val D0 = Input(Bool())
    val D1 = Input(Bool())
    val S = Input(Bool())
    val Y = Output(Bool())
}

class mux2 extends BlackBox with HasBlackBoxResource{
    val io = IO(new IOm)
    addResource("/mux2.v")
    
}

class Mux2 extends Module{
    val io = IO(new IOm)
    val a = Module(new mux2)

    a.io <> io
}