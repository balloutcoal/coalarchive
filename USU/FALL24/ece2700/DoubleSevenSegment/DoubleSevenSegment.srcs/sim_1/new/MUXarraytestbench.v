`timescale 1ns / 1ps

module MUXarraytestbench(   );
    reg [3:0] a, b;
    reg sel;
    wire [3:0] o;
    
    MUXarray DUT(.a(a), .b(b), .sel(sel), .o(o));
    
    integer i, j, k;
    
    initial begin
        i = 0;
        j = 0;
        k = 0;
        #100;
        for(i = 0; i < 16; i = i + 1)begin
            for(j = 0; j < 16; j = j + 1)begin
                for(k = 0; k < 2; k = k + 1)begin
                    #10;
                    a = i;
                    b = j;
                    sel = k;
                end
            end
        end
    end
endmodule
