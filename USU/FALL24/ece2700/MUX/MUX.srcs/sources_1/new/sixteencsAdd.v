`timescale 1ns / 1ps

module sixteencsAdd(
    input [15:0] a, b,
    input cin,
    output [15:0] s,
    output cout
    );
    wire [3:0] sum0, sum1;
    wire [2:0] c;
    
    rcAdd rca0(.a(a[3:0]), .b(b[3:0]), .cin(cin), .s(s[3:0]), .cout(c[0]));
    rcAdd rca1(.a(a[7:4]), .b(b[7:4]), .cin(c[0]), .s(s[7:4]), .cout(c[1]));
    rcAdd rca2(.a(a[11:8]), .b(b[11:8]), .cin(c[1]), .s(s[11:8]), .cout(c[2]));
    rcAdd rca3(.a(a[15:12]), .b(b[15:12]), .cin(c[2]), .s(s[15:12]), .cout(cout));
    
    mux muxsum0 (.i({sum1[0], sum0[0]}), .sel(cin), .o(s[0]));
    mux muxsum1 (.i({sum1[1], sum0[1]}), .sel(cin), .o(s[1]));
    mux muxsum2 (.i({sum1[2], sum0[2]}), .sel(cin), .o(s[2]));
    mux muxsum3 (.i({sum1[3], sum0[3]}), .sel(cin), .o(s[3]));
    mux muxcout (.i({cout1, cout0}), .sel(cin), .o(cout));
endmodule
