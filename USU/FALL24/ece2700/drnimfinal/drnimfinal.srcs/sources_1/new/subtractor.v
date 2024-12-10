`timescale 1ns / 1ps

module subtractor #(parameter N = 6)(
    input clk,
    input [N-1:0] a, b,
    output reg [N-1:0] out,
    output reg negative
    );
    reg [N:0] result;
    
    always @(posedge clk)begin
        result = {1'b0, a} - {1'b0, b};
        
        out <= result[N-1:0];
        negative <= result[N];
    end
endmodule
