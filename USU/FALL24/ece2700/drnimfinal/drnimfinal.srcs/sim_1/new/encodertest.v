`timescale 1ns / 1ps

module encodertest(     );
    reg [3:0] sw;
    reg en;
    wire [1:0] out;
    
    reg clk;
    encoder4to2 DUT(.clk(clk), .sw(sw), .en(en), .out(out));
    
    initial begin
        clk = 0;
        sw = 0;
        en = 0;
        #50;
    end
    
    always #10 clk = ~clk;
    
    always @(posedge clk)begin
        #50;
        en = 1;
        sw = 4'b0001;
        #50;
        sw = 4'b0010;
        #50;
        sw = 4'b0100;
        #50;
        sw = 4'b1000;
        #50;
        sw = 4'b1111;
        #50;
        en = 0;
        sw = 4'b0001;
        #50;
        sw = 4'b0010;
        #50;
        sw = 4'b0100;
        #50;
        sw = 4'b1000;
        #50;
        sw = 4'b1111;
    end
endmodule
