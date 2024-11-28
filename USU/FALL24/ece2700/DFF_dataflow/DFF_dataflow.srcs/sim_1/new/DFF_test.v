`timescale 1ns / 1ps

module DFF_test(    );
    reg d, clk;
    
    wire q;
    
    reg mclk;
    reg [2:0] count;
    
    DFFDataflow UUT(.clk(clk), .d(d), .q(q));
    //latchDataflow UUT(.clk(clk), .d(d), .q(q));
    
    initial begin
        clk = 0;
        d = 0;
        count = 0;
        mclk = 0;
        clk = 0;
        
        #100;
    end
    
    always #10 mclk=~mclk;
        always @(posedge mclk) begin
        count = count + 1;
        clk = count[2]^count[0];
        d = count[1];
        end
endmodule
