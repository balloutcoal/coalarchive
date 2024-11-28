`timescale 1ns / 1ps

module buttontop(
    input mclk,
    input [1:0] b,
    output [7:0] led
    );
    
    wire clk, incr, rst;
    
    //testbench clk:
    assign clk = mclk;
    //ClockDivider clkdiv(.clkin(mclk), .clkout(clk));
    
    debouncer i(.clk(clk), .b(b[0]), .d(incr));
    debouncer o(.clk(clk), .b(b[1]), .d(rst));
    counter c(.clk(clk), .incr(incr), .rst(rst), .q(led));
endmodule
