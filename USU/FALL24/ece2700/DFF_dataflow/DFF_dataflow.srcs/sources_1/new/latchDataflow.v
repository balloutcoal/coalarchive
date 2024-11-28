`timescale 1ns / 1ps

module latchDataflow(
    input clk, d,
    output q
    );
    
    wire S, R, qb;
    
    assign #1 S = (~d & clk);
    assign #1 R = (d & clk);
    assign #2 qb = ~(R | q);
    assign #2 q = ~(S | qb);
endmodule