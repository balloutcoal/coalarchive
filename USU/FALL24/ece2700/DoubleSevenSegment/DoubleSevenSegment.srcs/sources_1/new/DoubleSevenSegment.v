`timescale 1ns / 1ps

module DoubleSevenSegment #(parameter PRESCALER = 50000)(
    input clk,
    input [3:0] sw1, sw2,
    output [6:0] seg,
    output [3:0] an
);
    
    wire sel;
    wire [6:0] tseg1, tseg2;
    wire [6:0] seg1, seg2;

    ClockDivider #(.PRESCALER(PRESCALER)) CKD(.clkin(clk), .clkout(sel));
    
    NewSevenSegment one(.wxyz(sw1), .seg(tseg1));
    NewSevenSegment two(.wxyz(sw2), .seg(tseg2));

    //MUXarray mux(.a(seg1), .b(seg2), .sel(sel), .o(seg));
   
    assign seg = ~(sel ? tseg2 : tseg1);
    
    assign an = {2'b11, ~sel, sel};
    
endmodule
