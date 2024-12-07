`timescale 1ns / 1ps

module comparator(
    input [3:0] a, b,
    output less //, equal, greater <<NOT NEEDED
    );
    assign less = (a <= b) ? 1 : 0;
endmodule
