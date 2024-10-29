`timescale 1ns / 1ps

module SevenSegmentTest;
    reg [3:0] wxyz;
    wire [6:0] seg;
    
    NewSevenSegment DUT(.wxyz(wxyz), .seg(seg));
    
    reg clk;
    reg [4:0] clk_count;
    
    initial begin
        wxyz = 0;
        clk_count = 0;
        clk = 0;
        
        forever #10 clk = ~clk;
    end
    
    always@(posedge clk) begin
        wxyz <= clk_count;
        clk_count <= clk_count + 1;
    end
    
endmodule
