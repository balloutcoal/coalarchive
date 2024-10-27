`timescale 1ns / 1ps

module DoubleSevenSegmentTest(  );
    reg clk;
    reg [3:0] sw1, sw2;
    wire [6:0] seg1, seg2;

    // Instantiate the DoubleSevenSegment module
    DoubleSevenSegment #(. PRESCALER (8))DUT (
        .clk(clk),
        .sw1(sw1),
        .sw2(sw2),
        .seg1(seg1),
        .seg2(seg2)
    );

    // Clock generation
    initial begin
        clk = 0;
        forever #5 clk = ~clk; // 10 ns period for simulation
    end
    
    integer i;

    // Test stimuli
    initial begin
        // Initialize switches
        sw1 = 4'b0000; // 0
        sw2 = 4'b0000; // 0
        i = 0;
        
        // Wait for a few clock cycles
        #20;

        // Test all values for sw1 and sw2
        for (i = 0; i < 16; i = i + 1) begin
            sw1 = i[3:0]; // Set sw1
            #20;          // Wait to observe changes
            sw2 = i[3:0]; // Set sw2
            #20;          // Wait to observe changes
        end
        
        $stop; // Stop simulation
    end

endmodule
