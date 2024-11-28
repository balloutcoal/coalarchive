`timescale 1ns / 1ps

module JKFF(
    input j, k, clk,
    output q
    );
    wire jq, kq, d;
    
    assign jq = (j & ~q);
    assign kq = (~k & q);
    assign d = (jq | kq);
    
    newLatch L(.clk(clk), .d(d), .q(q));
    
    
endmodule
