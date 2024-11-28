`timescale 1ns / 1ps

module decoder4_16(
    input [2:0] d,
    input en,
    output [15:0] o
);
    wire en1, en2;
    assign en1 = en;
    assign en2 = ~en;
    
    decoder3_8 low(.en(en1), .d(d), .o(o[7:0]));
    decoder3_8 high(.en(en2), .d(d), .o(o[15:8]));

endmodule