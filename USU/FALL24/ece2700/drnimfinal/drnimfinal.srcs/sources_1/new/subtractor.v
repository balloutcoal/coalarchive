`timescale 1ns / 1ps

module subtractor #(parameter N = 6)(
    input [N-1:0] a, b,
    output wire [N-1:0] out,
    output wire negative
    );
    wire [N:0] result;
    
    assign result = {1'b0, a} - {1'b0, b};
    
    assign out = result[N-1:0];
    assign negative = result[N];
endmodule
