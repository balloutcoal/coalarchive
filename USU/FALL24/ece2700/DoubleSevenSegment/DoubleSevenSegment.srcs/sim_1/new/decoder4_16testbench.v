`timescale 1ns / 1ps

module decoder4_16testbench(    );
    reg clk;
    reg [3:0] count;
    
    reg [2:0] d;
    reg en;
    wire [15:0] o;
    
    decoder4_16 DUT(
        .d(d),
        .en(en),
        .o(o)
    );
    
    initial begin
        //initiate varialbes
        d = 0;
        en = 0;
        count = 0;
        clk = 0;
        
        #100 //wait
        
        forever #10 clk=~clk;
    end
    
    always @(posedge clk) begin
        count <= count + 1;
        d  <= count [2:0];
        en <= count[3];
    end
endmodule
