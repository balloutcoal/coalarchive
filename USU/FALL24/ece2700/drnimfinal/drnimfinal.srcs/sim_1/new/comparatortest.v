`timescale 1ns / 1ps

module comparatortest(  );
    reg [3:0] a, b;
    wire less;
    
    reg clk;
    
    comparator DUT(.a(a), .b(b), .less(less));
    
    initial begin
        clk = 0;
        {a,b} = 0;
        #50;
    end
    
    always #10 clk = ~clk;
    
    always @(posedge clk)begin
        #50;
        a = 2;
        b = 3;
        #50;
        b = 2;
        #50;
        a = 5;
        b = 5;
        #50;
        a = 8;
        b = 5;
        #50;
        a = 11;
        b = 2;
    end
endmodule
