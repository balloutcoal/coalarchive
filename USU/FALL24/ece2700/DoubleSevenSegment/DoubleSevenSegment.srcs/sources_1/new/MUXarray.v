`timescale 1ns / 1ps

module MUXarray(
    input [3:0] a, b,
    input sel,
    output [3:0] o
    );
    
    genvar i;
    
    generate
        for(i = 0; i < 3; i = i + 1) begin: MUXarray
            mux m(.i({a[i], b[i]}), .sel(sel), .o(o[i]));
        end
    endgenerate
endmodule
