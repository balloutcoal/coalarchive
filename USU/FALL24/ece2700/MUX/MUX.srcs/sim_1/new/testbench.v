`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/02/2024 03:59:21 PM
// Design Name: 
// Module Name: testbench
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module testbench(   );
    reg [3:0] a, b;
    reg cin;
    wire [3:0] s;
    wire cout;
    
    integer i, j , k;
    
    rcAdd DUT(
        .a(a),
        .b(b),
        .cin(cin),
        .s(s),
        .cout(cout)
    );
    
    initial begin
        i = 0;
        j = 0;
        k = 0;
        for(i=0; i <= 16; i = i + 1)begin
        j = 0;
            for(j=0; j <= 16; j = j + 1)begin
            k = 0;
                for(k=0; k <= 2; k = k + 1)begin
                    a = i;
                    b = j;
                    cin = k;
                    #5;
                end
            end
        end
        $finish;
    end
endmodule
