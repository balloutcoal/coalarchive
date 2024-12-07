`timescale 1ns / 1ps

module ledarraytest(    );
    reg [4:0] sw;
    wire [15:0] led;
    
    reg clk;
    
    ledarray DUT(.sw(sw), .clk(clk), .led(led));
    
    initial begin
        clk = 0;
        sw = 0;
        #50;
    end
    
    always #10 clk = ~clk;
    
    always @(posedge clk)begin
        #50;
        sw = sw + 3'b001;
    end
endmodule
