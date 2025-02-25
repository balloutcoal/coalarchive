`timescale 1ns / 1ps

module mealmachine(
    input b, clk,
    output reg d
    );
    reg [1:0] state = 2'b00;
    always @(posedge clk)begin
        case(state)
            2'b00: begin
                state <= b ? 2'b01 : 2'b00;
                d <= 0;
            end
            2'b01: begin
                state <= b ? 2'b10 : 2'b00;
                d <= 0;
            end 
            2'b10: begin
                state <= b ? 2'b10 : 2'b11;
                d <= 0;
            end 
            2'b11: begin
                state <= b ? 2'b10 : 2'b00;
                d <= 1;
            end 
            default: begin
                state <= 2'b00;
                d <= 0;
            end
        endcase
    end
endmodule
