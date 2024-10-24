`timescale 1ns / 1ps

module SegmentCompare;
    wire [6:0] a, b;
    reg [3:0] x;
    reg[6:0] w;
    
    NewSevenSegment REF(.wxyz(x), .seg(a));
    
    SevenSegmentTruthTable DUT(.a(b), .x(x));
    
    //make a clock and a clock counter
    reg clk;
    reg [11:0] clk_count;
    //the number of bits the counter should have equals the sum of the number of bits of your inputs
    //In this case, I have 2 N bit input vectors so my counter has 2*N bits
    
    initial begin
        //initialize your inputs and clock to zero
        x = 0;
        w = 0;
        clk_count = 0;
        clk = 0;
        
        forever #10 clk = ~clk;
        //make your clock oscillate
    end
    //make a clocked always block
    always @(posedge clk) begin
        x <= clk_count;
        clk_count <= clk_count + 1;
        w <= a ^ b;
        //X and Y are concatenated and given the value of the counter
        //The counter is incremented by 1.
        //Once the counter reaches its maximum value, adding 1 resets it to zero; no check is needed.
    end
endmodule
