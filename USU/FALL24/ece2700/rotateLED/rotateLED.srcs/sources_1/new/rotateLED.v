`timescale 1ns / 1ps

module rotateLED #(parameter PRESCALER = 8)(
    input mclk, shift, rst,
    input [7:0] sw,
    output [7:0] led
    );
    
    wire clk;
    ClockDivider clkdiv(.clkin(mclk), .clkout(clk));
    
    genvar i;
    
    DRegister u0(.d(led[7]), .d0(sw[0]), .rst(rst), .shift(shift), .clk(clk), .q(led[0]));
    
    generate 
        for(i = 1; i < PRESCALER; i = i + 1) begin 
            DRegister u1(.d(led[i-1]), .d0(sw[i]), .rst(rst), .shift(shift), .clk(clk), .q(led[i]));
        end 
    endgenerate 
    
endmodule
