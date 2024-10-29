`timescale 1ns / 1ps

module csAdder(
    input [3:0] a, b,
    input cin,
    output [3:0] s,
    output cout
    );
    wire [3:0] sum0, sum1;
    wire cout0, cout1;
    
    rcAdd ra0(.a(a), .b(b), .cin(1'b0), .s(sum0), .cout(cout0));
    rcAdd ra1(.a(a), .b(b), .cin(1'b1), .s(sum1), .cout(cout1));
    
    mux muxsum0 (.i({sum1[0], sum0[0]}), .sel(cin), .o(s[0]));
    mux muxsum1 (.i({sum1[1], sum0[1]}), .sel(cin), .o(s[1]));
    mux muxsum2 (.i({sum1[2], sum0[2]}), .sel(cin), .o(s[2]));
    mux muxsum3 (.i({sum1[3], sum0[3]}), .sel(cin), .o(s[3]));
    mux muxcout (.i({cout1, cout0}), .sel(cin), .o(cout));
endmodule
