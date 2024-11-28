`timescale 1ns / 1ps

module dLatch(
    input clk, d,
    output reg q
    );
    
    initial begin
        q = 0;
    end
    
    always @(clk or d) begin
        if(clk) q <= d;
    end
endmodule
