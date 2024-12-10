`timescale 1ns / 1ps

module FSM(
    input clk, rstn, w,
    output reg z
    );
    parameter S0 = 3'b000, S1 = 3'b001, S2 = 3'b011,
              S3 = 3'b010, S4 = 3'b110, S5 = 3'b111;
    reg [2:0] y, Y; //y:present state, Y:next state
    
    always @(posedge clk)begin
        y = rstn ? S0 : Y;
        case(y)
            S0: begin
                z = 0;
                Y <= w ? S4 : S1;
            end
            S1: begin
                z = 0;
                Y <= w ? S3 : S2;
            end
            S2: begin
                z = 0;
                Y <= S0;
            end
            S3: begin
                if(w) z = 1;
                else z = 0;
                Y <= S0;
            end
            S4: begin
                z = 0;
                Y <= w ? S5 : S3;
            end
            S5: begin
                z = 1;
                Y <= S0;
            end
        endcase    
    end
endmodule
