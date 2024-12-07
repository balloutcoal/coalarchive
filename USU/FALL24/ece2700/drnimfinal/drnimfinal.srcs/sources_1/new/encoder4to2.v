`timescale 1ns / 1ps

module encoder4to2(
    input [2:0] sw,
    input en,
    output reg [1:0] out
    );
    always @(*)begin
        if(en) begin 
            if(sw[2] == 1) out = 2'b11; 
            else if(sw[1] == 1) out = 2'b10;
            else if(sw[0] == 1) out = 2'b01;
            //else if(sw[0] == 1) out = 2'b00; //ignore instantiate as .sw(sw[3:1](sw[2:0])
        end else out = 2'b00;
    end
endmodule
