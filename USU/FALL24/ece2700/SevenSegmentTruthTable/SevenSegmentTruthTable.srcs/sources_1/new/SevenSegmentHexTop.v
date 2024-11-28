`timescale 1ns / 1ps

module SevenSegmentHexTop #(parameter PRESCALER = 50000)(
    input [3:0] sw,
    output [6:0] seg,
    output [3:0] an
);

    assign an = ~sw[7:4];
    
    SevenSegmentHex one(.wxyz(sw), .seg(seg));
    
endmodule