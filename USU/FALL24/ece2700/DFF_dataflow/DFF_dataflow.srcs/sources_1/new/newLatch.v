`timescale 1ns / 1ps

module newLatch(
    input clk, d,
    output reg q
    );
    always@(posedge clk)begin
        if(clk == 1) q <= d;
    end
endmodule
