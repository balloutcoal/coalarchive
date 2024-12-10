`timescale 1ns / 1ps

module FSMtest(     );
    reg clk, rstn, w;
    wire z;
    
    FSM DUT(.clk(clk), .rstn(rstn), .w(w), .z(z));
    
    initial begin
        {clk, rstn, w} = 0;
    end
    
    always #10 clk = ~clk;
    
    initial begin
        #100
        rstn = 1;
        #100;
        rstn = 0;
        w = 1;
    end
endmodule
