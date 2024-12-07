`timescale 1ns / 1ps

module mux(
    input [1:0] a, b, 
    input sel,
    output [1:0] out
    );
    
    assign out = sel ? a : b;
endmodule
