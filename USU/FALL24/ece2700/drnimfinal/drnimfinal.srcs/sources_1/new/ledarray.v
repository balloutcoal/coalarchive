`timescale 1ns / 1ps

module ledarray(
    input [4:0] sw,
    input clk,
    output reg [15:0] led
    );
    always @(posedge clk)begin
        if(sw > 0 && sw < 16) led <= (16'b1 << sw) - 1;
        else led <= 16'b0;
    end
endmodule
