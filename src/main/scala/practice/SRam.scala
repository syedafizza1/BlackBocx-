// input  clk0; // clock
//   input   csb0; // active low chip select
//   input  web0; // active low write control
//   input [ADDR_WIDTH-1:0]  addr0;
//   input [DATA_WIDTH-1:0]  din0;
//   output [DATA_WIDTH-1:0] dout0;

package practice

import chisel3._
import chisel3.util._
import chisel3.experimental._

class IOR extends Bundle{
    val clk0 = Input(Bool())
    val csb0 = Input(Bool())
    val web0 = Input(Bool())
    val addr0 = Input((UInt(2.W))
    val din0 = Input((UInt(2.W))
    val dout0 = Output(UInt(2.W))
    // clock    input(bool)
    // reset    == = = = = 
}

class sram extends BlackBox with HasBlackBoxResource{
    val io = IO(new IOrR)
    addResource("/sram.v")
    
}

class SRam extends Module{

    val io = IO(new Bundle{
        val dout0 = Output(UInt(2.W))

    })
    // val io = IO(new Bundle{
    //     a
    //     B
    //     sum
    // })
    val a = Module(new sram)
    val clk0 = WireInit(clock.asUInt()(0))
    a.io.clk0 := ~clk0
    // val rst = WireInit(reset.asUInt()(0))
    // a.io.reset := rst
    io.dout0 := a.io.sram
   

    //a.io <> io

}