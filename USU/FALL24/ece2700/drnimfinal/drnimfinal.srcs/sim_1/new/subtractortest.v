`timescale 1ns / 1ps

module subtractortest(  );
    reg [3:0] a, b;
    wire [3:0] out;
    wire negative;
    
    reg clk;
    subtractor DUT(.a(a), .b(b), .out(out), .negative(negative));
    
    initial begin
        clk = 0;
        {a,b} = 0;
        #100;
    end
    
    always #10 clk = ~clk;
    
    always @(posedge clk)begin
        #100;
        a = 12;
        b = 4;
        #100;
        a = 4;
        b = 12;
    end
endmodule
