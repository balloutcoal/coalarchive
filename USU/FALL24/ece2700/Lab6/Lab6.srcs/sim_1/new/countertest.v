`timescale 1ns / 1ps

module countertest(    );
    reg mclk;
    reg [1:0] b;
    wire [7:0] led;
    
    buttontop DUT(.mclk(mclk), .b(b), .led(led));
    
    initial begin
        mclk = 0;
        b = 2'b10;
    end
    always #10 mclk = ~mclk;
    
    always @(posedge mclk)begin
        #50;
        b = 2'b01;
        #50;
        b = 0;
    end
    
endmodule
