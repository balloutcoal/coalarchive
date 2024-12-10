`timescale 1ns / 1ps

module encoder4to2(
    input [3:0] sw,
    input clk, en,
    output reg [1:0] out
    );
    always @(posedge clk)begin
        if(en) begin 
            case(sw)
                4'b0001: out = 2'b01; //sw0
                4'b0010: out = 2'b10; //sw1
                4'b0100: out = 2'b11; //sw2
                4'b1000: out = 2'b00; //invalid sw don't include in instantiation
                default: out = 2'b00; //just in case
            endcase
        end else out = 2'b00;
    end
endmodule
