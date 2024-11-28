`timescale 1ns / 1ps

 module DFFDataflow(
    input clk, d,
    output q
    );
    
    wire q1;
    wire clkb = ~clk;
    
    latchDataflow d1(.clk(clk), .d(d), .q(q1));
    latchDataflow d2(.clk(clkb), .d(q1), .q(q));
endmodule
