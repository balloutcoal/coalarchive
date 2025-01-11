`timescale 1ns / 1ps

module marbletoptest(   );
    reg [4:0] sw;
    reg start, btnC, mclk, nobot;
    wire [15:0] led;
    
    controltop DUT(.sw(sw), .start(start), .btnC(btnC), .mclk(mclk), .nobot(nobot), .led(led));
        
    initial begin
        {sw, start, btnC, mclk, nobot} = 0;
        #100;
    end
    
    always #10 mclk = ~mclk;
    initial begin
        sw = 4'b1100;
        #50;
        start = 1;
        btnC = 1;
        #50;
        sw = 3'b010;
        btnC = 0;
        #50;
        btnC = 1;
        #50;
        sw = 3'b001;
        btnC = 0;
        #50;
        btnC = 1;
        #50;
        sw = 3'b100;
        btnC = 0;
        #50;
        btnC = 1;
        #50;
        start = 0;
        sw = 4'b1111;
        #50;
        start = 1;
        nobot = 1;
        btnC = 1;
        #50;
        sw = 3'b100;
        btnC = 0;
        #50;
        btnC=1;
        #50;
        sw = 3'b100;
        btnC = 0;
        #50;
        btnC=0;
        #50;
    end
endmodule
