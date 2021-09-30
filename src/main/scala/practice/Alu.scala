//  input [7:0] A,B,  // ALU 8-bit Inputs                 
//            input [3:0] ALU_Sel,// ALU Selection
//            output [7:0] ALU_Out, // ALU 8-bit Output
//            output CarryOut // Carry Out Flag

package practice

import chisel3._
import chisel3.util._
import chisel3.experimental._

class IOA extends Bundle{
    val A = Input(UInt(8.W))
    val B = Input(UInt(8.W))
    val ALU_Sel = Input(UInt(4.W))
    val ALU_Out = Output(UInt(8.W))
    val CarryOut = Output(Bool())
    // clock    input(bool)
    // reset    == = = = = 
}

class alu extends BlackBox with HasBlackBoxResource{
    val io = IO(new IOA)
    addResource("/alu.v")
}

class Alu extends Module{

    val io = IO(new IOA)

    // val io = IO(new Bundle{
    //     a
    //     B
    //     sum
    // })
    // val clk = WireInit(clock.asUInt()(0))
    // a.io.clock := ~clk

    val a = Module(new alu)

    a.io <> io

}