`timescale 1ns / 1ps

module DoubleSevenSegmenTopTest();
    reg [3:0] sw1, sw2;
    wire [6:0] seg;
    wire [3:0] an;
    
    //make a clock and a clock counter
    reg clk;
    reg [7:0] clk_count;
    //the number of bits the counter should have equals the sum of the number of bits of your inputs
    //In this case, I have 2 N bit input vectors so my counter has 2*N bits

    DoubleSevenSegment DUT(.clk(clk), .sw1(sw1), .sw2(sw2), .seg(seg), .an(an));
    
    initial begin
        //initialize your inputs and clock to zero
        sw1 = 0;
        sw2 = 0;
        clk_count = 0;
        clk = 0;
        
        forever #10 clk = ~clk;
        //make your clock oscillate
    end
    //make a clocked always block
    always @(posedge clk) begin
        {sw1, sw2} <= clk_count;
        clk_count <= clk_count + 1;
        //X and Y are concatenated and given the value of the counter
        //The counter is incremented by 1.
        //Once the counter reaches its maximum value, adding 1 resets it to zero; no check is needed.
    end



endmodule
