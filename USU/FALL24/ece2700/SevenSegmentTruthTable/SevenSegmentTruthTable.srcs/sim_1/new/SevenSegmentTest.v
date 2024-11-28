`timescale 1ns / 1ps

module SevenSegmentTest;
    //inputs
    reg [7:0] sw;
    reg clk;
    
    //outputs
    wire [6:0] seg;
    wire [3:0] an;
    
    //instaniate the design under test
    SevenSegmentTop DUT(
        .seg(seg),
        .an(an),
        .sw(sw)
    );
    
    
    
    initial begin
        //init inputs
        sw = 0;
        clk = 0;
        //wait 100 ns for global reset to finish
        #100;
        
     forever #10 clk = ~clk;
     end
     
     always @(posedge clk) begin
        if(sw >= 9)
            sw <= 0;
        else
            sw <= sw + 1;
     end
endmodule
