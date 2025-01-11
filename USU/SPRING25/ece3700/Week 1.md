1/6/25
# LOGIN
username: cot620
password: tEgg8GIqPWZH6rIOMWtyo1dMSkEF0ZtW

SSH Server URL:
   miranda.bluezone.usu.edu (requires VPN or campus network connection)

Git Server URLs:
   https://left.engr.usu.edu/git/cot620/gitting_started
   https://left.engr.usu.edu/git/cot620/3700
# TODO
* get Diligent Basys3 FPGA PMod Pack whenever
* get Vivado running on laptop (need product key)
# NOTES
ssh into miranda.bluezone.usu.edu

# BASICS
* Combinational circuit are not reliant on states or a clock
## Compilation
* xvlog filename.v to compile
## Verilog Syntax
ALWAYS HAVE
```
`timescale 1ns/1ps

module Modulename(
	input x,
	output y
);

endmodule
```

Example adder:
(adder.v)
```
`timescale 1ns/1ps

module Adder(
	input [3:0] a, b,
	output [4:0] q
);

//since q is a wire we use continuous assignment 'assign'
assign q = a + b;

endmodule
```

testbench.v
```
`timescale 1ns/1ps

module testbench();
	reg [3:0] a, b;
	reg clk;
	wire [4:0] q;
	
	Adder DUT(.a(a), .b(b), .q(q)); //DUT: Device/Design Under Test
	
	integer clk_count;
	
	initial begin
	{a, b, clk}  = 0;
	clk_count = 0;
	forever #10 clk = ~clk;
	end
	
	always @(posedge clk)begin
		clk_count <= clk_count + 1;
	end
	
endmodule
```