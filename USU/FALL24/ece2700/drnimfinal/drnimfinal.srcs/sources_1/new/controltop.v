`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: Utah State University
// Engineer: Cole Thorpe
// 
// Create Date: 12/03/2024 07:07:55 PM
// Design Name: 
// Module Name: controltop
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


module controltop(
    input[5:0] sw, //in start set amount of marbles, in play set as player turn
    input start, confirm, clk, //start/rst game and confirm player turn and clock
    output reg [4:0] pwin, bwin, //flags for bot win or player win
    output wire [15:0] led //array of leds on board
    );
    reg [5:0] marbles;
    wire [5:0] marbles_result; //marble count and the from each turn
    reg [2:0] state, playturn;
    wire [2:0] encodedplayturn;
    
    subtractor #(.N(6)) subturn(.a({3'b000, playturn}), .b(marbles), .out(marbles_result));
    subtractor #(.N(3)) subbot(.a(), .b(), .out());
    ledarray leds(.sw(marbles), .clk(clk), .led(led));
    encoder4to2 encoder(.sw(sw[2:0]), .en(start), .out(encodedplayturn[1:0]));
    
    always @(posedge clk)begin
        if(~start) state = 3'b000;
        case(state)
            3'b000: //wait for start
                if(start)begin
                    marbles = sw;
                    state = 3'b001;
                end else state = 3'b000;
            3'b001: //wait for player turn
                if(sw > 0 && sw < 4 && confirm && sw <= marbles) state = 3'b010;
                else state = 3'b001;
            3'b010: begin//play out player turn
                playturn = encodedplayturn;
                if(playturn > 0 && sw < 4 && confirm && sw <= marbles)begin
                    marbles = marbles_result;
                    state = 3'b100;
                end else state = 3'b001;
            end
            3'b011: begin //calculate and play out bot move
                playturn = 4 - playturn;
                marbles = marbles_result;
                state = 3'b101;
            end
            3'b100: //check if player wins
                if(marbles == 0)begin
                    pwin = pwin + 1;
                    state = 3'b110;
                end else state = 3'b011;
            3'b101: //check if bot wins
                if(marbles == 0)begin
                    bwin = bwin + 1;
                    state = 3'b110;
                end else state = 3'b001;
            3'b110: //win state, wait for reset
                if(!start) state = 3'b000;
                else state = 3'b110;
        endcase
    end
endmodule
