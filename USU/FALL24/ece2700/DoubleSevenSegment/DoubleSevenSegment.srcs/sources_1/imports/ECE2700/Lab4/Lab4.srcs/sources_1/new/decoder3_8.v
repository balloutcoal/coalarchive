`timescale 1ns / 1ps

module decoder3_8(
    input [2:0] d,
    input en,
    output reg [7:0] o
    );
    
    always @(*)begin
        if (en) begin
            case(d)
                3'd7: o=8'd1;
                3'd6: o=8'd2;
                3'd5: o=8'd4;
                3'd4: o=8'd8;
                3'd3: o=8'd16;
                3'd2: o=8'd32;
                3'd1: o=8'd64;
                3'd0: o=8'd128;
            endcase
        end
        else
            o=8'd0;
     end
endmodule
