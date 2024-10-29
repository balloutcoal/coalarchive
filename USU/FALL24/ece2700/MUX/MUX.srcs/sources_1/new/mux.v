`timescale 1ns / 1ps

module mux(
    input [0:1] i,
    input sel,
    output o
    );
    
    assign o = sel ? i[0] : i[1];
endmodule
