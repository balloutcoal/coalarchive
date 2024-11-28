`timescale 1ns / 1ps

module mealtest(    );
    reg b, clk;
    wire d;
    
    debouncer DUT(.b(b), .clk(clk), .d(d));
    
    initial begin
        b = 0;
        clk = 0;
    end
    always #10 clk = ~clk;
    always @(posedge clk)begin
        b = 1;
        #100;
        b = 0;
        #100;
        b = 1;
        #50;
        b = 0;
    end
endmodule
