`timescale 1ns / 1ps

module RotateTest(  );
    reg mclk, shift, rst;
    reg [7:0] sw;
    wire [7:0] led;
    
    reg [1:0] clksw;
    
    rotateLED UUT(.mclk(mclk), .shift(shift), .rst(rst), .sw(sw), .led(led));

    initial begin 
        clksw = 0;
        mclk = 1;
        shift = 0;
        rst = 1;
        sw = 5;
        #100;
        rst = 0;
    end 
    
    always #10 mclk = ~mclk;
    
    always @(posedge mclk)begin
        #10;
        shift = clksw[1];
        clksw = clksw + 1;
    end 
endmodule