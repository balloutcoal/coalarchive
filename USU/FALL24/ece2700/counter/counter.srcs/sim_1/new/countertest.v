`timescale 1ns / 1ps

module countertest(    );
    reg incr, rst, mclk;
    wire [7:0] o;
    
    countertop UUT(.mclk(mclk), .incr(incr), .rst(rst), .o(o));
    
    initial begin 
        incr = 0;
        rst = 1;
        mclk = 1;
        #100;
        incr = 1;
        rst = 0;
    end 
    
    always #10 mclk = ~mclk;
endmodule
