# Circuit Elements
## Nodes
* Nodes are when a wire connect to 2 or more circuit elements
# Laws
## Kirchhoff's Current Law (KCL)
![[KCL.png|275x200]]
### Definition
* Algebraic sum of currents entering a node is zero at every instance
	* Charge does not bunch up at a node
	* Given an N-node circuit, there are N-1 independent KCL equations
### Usage
* Preserves charge
* $i_1$, $i_2$, $i_3$ are all wires intersecting a node where $i_1+i_2+i_3=0$
* FIGURE
	* $i_3-i_1-i_2=0$
## Kirchhoff's Voltage Law (KVL)
![[KVL.png|275x200]]
### Definition
* Algebraic sum of voltages around a circuit loop is zero at every instance
### Usage
* Preserves potential energy
* Voltage = Joules/coul = energy/unit
### Example
* Closed circuit with 2 resistors and 2 voltage sources
	* KVL: $+V_2+V_3+V_4-V_1=0$
	* Plug in voltages: $+i_LR_{9V}+i_LR_{1.5V}+1.5V-9V=0$
		* $i_L$ is the loop circuit path
		* $V_1$ is the only minus because in the loop the wire enters the positive node except for the final voltage source
## Post Lab (Resistors)
### Series Combinations of Resistors
* $V_S=iR_1+iR_2 = i(R_1+R_2)$
	* Voltage source is equal to the resistors added up times current
* 2 Resistors in a series the total resistance will be both of the resistors added up
### Parallel Combinations of Resistors
* $V = i_1R_1 = i_2R_2$
	* $i_S = i_1 + i_2$
	* $\frac{V_S}{Req}=i_S$
	* $Req = \frac{1}{\frac{1}{R_1}+\frac{1}{R_2}+...+\frac{1}{R_N}}=R_1||R_2||...||R_N$
* Always less than the smallest resistor in the combination