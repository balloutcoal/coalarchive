# Superposition
* When a circuit has multiple sources, you have to replace other sources with another element (voltage to shorts, current to open)
## Example
![[IMG_2680.webp|400]]
1. Voltage Source:
	1. Isolate 5V source $V_{A_{5V}}=\frac{5V 10\Omega||15\Omega}{10\Omega||15\Omega+10\Omega}$
	2. Isolate 6V source $V_{A_{6V}}=\frac{6V 10\Omega||10\Omega}{10\Omega||10\Omega+15\Omega}$
	3. Combine for $V_A = V_{A_{5V}}+V_{A_{6V}}=\frac{5V 10\Omega||15\Omega}{10\Omega||15\Omega+10\Omega}+\frac{6V 10\Omega||10\Omega}{10\Omega||10\Omega+15\Omega}$
2. Current Source:
	4. Isolate 5V source $V_{A_{5V}}=2.5V$
	5. Isolate 1A source $V_{A_{1A}}=0.5V$
	6. Combine for $V_A = 2.5V+0.5V = 3V$
# Thevenin's and Norton's Equivalents
![[IMG_2681.webp|300]]
* Sources
	* Batteries
	* Power supplies
	* Other circuits
	* Current sources
	* Power lines
* Loads
	* Lights
	* Resistor in the lab
	* Test instruments
## Example
![[IMG_2683.webp||300]]
* Top is source, right part added on is the load, use superposition to simplify the circuit and make calculation much easier