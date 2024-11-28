`timescale 1ns / 1ps

module JKKTest( );
    reg j, k, clk;
    wire q;
    integer i;
    
    wire [11:0] jvals = 8'b0110_1010;
    wire [11:0] kvals = 8'b0111_0001;
    
    JKFF DUT(.j(j), .k(k), .clk(clk), .q(q));
    
    initial begin
        j = 0;
        k = 1;
        i = 0;
        clk = 1;
        #100;
    end
    
    always #10 clk = ~clk;
    
    always @(posedge clk) begin
    i = (i + 1) % 8;
    j = jvals[i];
    k = kvals[k];
    end
endmodule
