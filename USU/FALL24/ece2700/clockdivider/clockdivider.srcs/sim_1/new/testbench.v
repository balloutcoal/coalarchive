`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/11/2024 03:42:40 PM
// Design Name: 
// Module Name: testbench
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module testbench();
    reg clk; 
    wire slow_clk;
    ClockDivider #(.PRESCALER(8)) DUT(
        .clkin(clk),
        .clkout(slow_clk)
    );
    
    initial begin
        clk = 0;
     
        forever #10 clk = ~clk;
    end
endmodule
