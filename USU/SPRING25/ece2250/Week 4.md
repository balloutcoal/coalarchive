# Circuit Elements (again)
## Load
![[load.png|275x200]]
* A load is a circuit element we have tied to the ideal source and the series resistance
	* The load can be anything with a voltage-current relationship
	* Load is a resistance, could also be a voltage source
### Load Cases
#### Open
* If the load were open current would be cut off above it and the voltage source
	* $V_{LOAD}=V_S$, $I=0$
#### Short
* If the load were shorted circuit would continue as normal
	* $V_{LOAD}=0$, $I_{SHORT}=\frac{V_S}{R}$ (Ohm's Law)
#### Theory
* Assume a load with arbitrary voltage V'
	* $i=\frac{V_S-V'}{R} = -\frac{1}{R}V'+\frac{V_S}{R}$
		* Awfully similar to equation of a line (y=mx+b)
## Diode
![[Pasted image 20250127103805.png|275x100]]
* Current threshold where current shoots up after voltage gets high enough
## Nodes
* Define ALL currents out of a node
	* Because they all need to sum to zero
* Nodes:
![[IMG_2534.webp|250x250]]
	* Node A: $V_A=V_S$
	* Node B: $\frac{V_B-V_A}{R_1}+\frac{V_B-0}{R_2}+\frac{V_B-V_C}{R_3}=0$
	* Node C: $\frac{V_C-V_B}{R_3}+\frac{V_C-0}{R_4}$
# HOMEWORK
* Resistance per temperature $V_i$ chart 2 lines
* Don't worry about self heating problems :3
# Systematic Circuit Analysis
## Rules of Node Voltage Analysis
1. Choose one of your circuit's nodes to be zero volts (ground (earth))
2. Assign a voltage (unknown at this point) to every other node in the circuit
3. At each node, assume that the currents are fall flowing out of the node
	1. Not true, pure bookkeeping; Method used to eliminate error
4. Solve for each of the currents leaving the nodes using Ohm's Law, properties of current sources, properties of voltage sources
5. Steps 1-4 result in N-1 simultaneous equations for an N-node circuit. Solve these equations
### EX
* Turn each node into a system of equations, plug into a matrix and multiply by $[V_AV_BV_C]_{1x3}$
