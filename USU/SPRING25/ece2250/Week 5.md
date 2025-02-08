# Node Analysis
## Mesh Current Method
![[mesh.png|250x200]]
* A mesh is defined as a circuit loop that encloses no circuit elements
	* Branch from KVL
	* Each loop is a mesh
### Steps to Mesh Current
1. Each mesh of the circuit is identified and assigned to a current
	1. Don't worry about the direction
2. Write a mesh equation for each mesh and expand that equation using Ohm's Law
#### Example:
* A circuit of 2 squares stacked on each other with a voltage sources on the left, resistor on the right
	* Top mesh has voltage $V_A$ on left, $R_1$ on top, $R_2$ on the right $i_1$ flows around
		* KVL Mesh 1: $-V_A+V_{R_1}+V_{R_2}+V_{R_{3_{i_1}}}+V_{R_{3_{i_2}}}=0$
			* $i_1R_1+i_1R_2+i_1R_3-i_2R_3=0$
	* Bottom mesh has voltage $V_B$ on left, $R_3$ on top, $R_4$ on right, $i_1$ flows around