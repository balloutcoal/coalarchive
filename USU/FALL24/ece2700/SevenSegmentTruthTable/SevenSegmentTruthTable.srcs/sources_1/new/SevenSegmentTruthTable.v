`timescale 1ns / 1ps

module SevenSegmentTruthTable(
    input x3,
    input x2,
    input x1,
    input x0,
    output a,
    output b,
    output c,
    output d,
    output e,
    output f,
    output g
    );

    always @(*) begin
        case (N)
            4'b0000: D = 7'b1111110;
            4'b0001: D = 7'b0110000;
            4'b0010: D = 7'b1101101;
            4'b0011: D = 7'b1111001;
            4'b0100: D = 7'b0110011;
            4'b0101: D = 7'b1011011;
            4'b0110: D = 7'b1011111;
            4'b0111: D = 7'b1110000;
            4'b1000: D = 7'b1111111;
            4'b1001: D = 7'b1111011;
            default: D = 7'b0000000;
        endcase
    end
endmodule
        
