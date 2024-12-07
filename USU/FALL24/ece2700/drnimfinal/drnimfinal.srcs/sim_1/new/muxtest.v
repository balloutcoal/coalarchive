`timescale 1ns / 1ps

module muxtest(     );
    reg [1:0] a, b;
    reg sel;
    wire [1:0] out;
    
    reg clk;
    
    mux DUT(.a(a), .b(b), .sel(sel), .out(out));
    
    initial begin
        clk = 0;
        {a, b, sel} = 0;
        #50;
    end
    
    always #10 clk = ~clk;
    
    always @(posedge clk)begin
        #50;
        a = 2;
        b = 3;
        #100;
        sel = 1;
        #100;
        sel = 0;
    end
endmodule
