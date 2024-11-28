`timescale 1ns / 1ps

module DFF(
    input d, clk,
    output q
    );
    
    wire q1;
    wire clkb = ~clk;
    
    dLatch d1(.d(d), .clk(clk), .q(q1));
    dLatch d2(.d(q1), .clk(clkb), .q(q));

endmodule