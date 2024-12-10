`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: Utah State University
// Engineer: Cole Thorpe
// 
// Create Date: 12/03/2024 07:07:55 PM
// Design Name: DR NIM FINAL
// Module Name: controltop
// Project Name: DR NIM FINAL
// Target Devices: basys 3 fpga
// Tool Versions: 
// Description: I HATE VIVADO!!!!
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module controltop(
    input [4:0] sw, //player turn and start switch
    input start, btnC, mclk, nobot, //start/rst game and confirm player turn and clock
    output wire [15:0] led //array of leds on board
    );
    reg [2:0] state;
    reg[4:0] marbles;
    
    //led behavior
    ledarray leds(.clk(mclk), .sw(marbles), .led(led));
    
    //button behavior
    wire confirm;
    debouncer debounceconfirm(.b(btnC), .clk(mclk), .d(confirm));
    
    //player behavior
    wire [1:0] play;
    encoder4to2 encodeturn(.clk(mclk), .sw({1'b0, sw[2:0]}), .en(start), .out(play));
    
    //bot behavior 
    reg [1:0] botplay;
    always @(*)begin
        botplay = 4 - play;
    end
    
    //math behavior 
    //TODO: ADD PROPER SUBTRACTORS FOR MARBLES IF BUILT IN MODULES AREN'T ALLOWED
    
    //delay behavior
    //TODO: ADD DELAY INBETWEEN STATES TO IMPROVE READABILITY AND REMOVE TURN PLAYING TWICE OCCASIONALY
    
    //state behavior
    always @(posedge mclk)begin
        if(~start) state <= 3'b000;
        case(state)
            3'b000: //IDLE
                if(start)begin
                    marbles <= sw[4:0];
                    state <= 3'b001;
                end
            3'b001: //WAIT
                if(confirm && play < 4 && play > 0 && play <= marbles) state <= 3'b010;
            3'b010: begin //PLAYEPLAYER
                marbles <= marbles - play;
                state = 3'b100;
            end
            3'b011: begin //PLAYBOT
                marbles <= marbles - botplay;
                state = 3'b101;
            end
            3'b100: //CHECKPLAYER
                if(marbles == 0) state <= 3'b110;
                else if(nobot) state <= 3'b001;
                else state <= 3'b011;
            3'b101: //CHECKBOT
                state <= (marbles == 0) ? 3'b110 : 3'b001;
            3'b110: //WIN
                state <= start ? 3'b110 : 3'b000;
        endcase
    end
endmodule
