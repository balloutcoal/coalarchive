# Op Amps
3/3/25 schematic 1
## Inverting
3/3/25 schematic 2
* Attempts to swap the voltages in the positive and negative terminals?
### Solve Vout
* 0*: $\frac{0-V_{in}}{R_{in}}+\frac{0-V_{out}}{R_f}=0$ to $V_{out}=-V{in}\frac{R_f}{R_{in}}$
	* $\frac{R_f}{R_{in}}$ is gain K since $V_{out}=KV_{in}$
* This is important cause it's used to increase frequency (microphones n stuff)
## Non-Inverting
3/3/25 schematic 3
* $V_{out}$ is whatever for the positive and negative terminal to both be $V_{in}$
### Solve Vout
* $\frac{V_{in}-V_{out}}{R_2}+\frac{V_{in}-0}{R_1}=0$ to $V_{out}=V_{in}(\frac{R_2}{R_1}+1)$
* Remove the resistors it becomes a buffer amplifier
# Non-Ideal Effects in Op-Amps
1. Finite voltage supplies means finite output voltages
	1.  +/-15V (split supplies)
2. Op-amps are output current limited (typically +/- 20mA)
	1. 0-5V
3. Small offset voltages