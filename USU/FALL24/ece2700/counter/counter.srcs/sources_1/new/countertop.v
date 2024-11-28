`timescale 1ns / 1ps

module countertop #(parameter PRESCALER = 8)(
    input mclk, incr, rst,
    output [7:0] o
    );
    
    wire[7:0] J, K;
    
    wire clk;
    ClockDivider clkdiv(.clkin(mclk), .clkout(clk));
    
    genvar i;
    
    assign J[0] = incr & ~rst;
    assign K[0] = J[0] | rst;
    JKFF u0(.j(J[0]), .k(K[0]), .clk(clk), .q(o[0]));
    generate 
        for(i = 1; i < PRESCALER; i = i + 1) begin
            assign J[i] = J[i-1] & o[i-1] & ~rst;
            assign K[i] = J[i] | rst;
            JKFF u(.j(J[i]), .k(K[i]), .clk(clk), .q(o[i]));
        end 
    endgenerate
endmodule
