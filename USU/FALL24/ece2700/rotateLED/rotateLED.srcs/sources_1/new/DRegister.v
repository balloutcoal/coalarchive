`timescale 1ns / 1ps

module DRegister(
    input d, d0, rst, shift, clk,
    output q
    );
    wire din;
    
    //assign din = (~rst & ~shift & q) | (rst & d0) | (~rst & shift & d);
    assign din = (((q&~shift)|(d&shift))&~rst)|(d0&rst);
    
    DFF D1(.d(din), .clk(clk), .q(q));

endmodule