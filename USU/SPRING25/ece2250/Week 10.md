# Capacitors and Inductors
* Capacitor:
	* Electric Fields -> charge
* Inductor:
	* Magnetic Fields -> current (flow of charge)
## Permittivity
* $\frac{v}{d}=\frac{q(t)}{\epsilon A}$
* $V_c(t)=\frac{dq(t)}{\epsilon A}$ where $i=\frac{dq}{dt}$ so $i(t)=\frac{\epsilon A}{d}\frac{dV_c(t)}{dt}$
	* $\frac{\epsilon A}{d}$ is unit capacitance C (Farads)
	* $C = \frac{ampsec}{volt}=\frac{coul}{volt}$
* $V_c(t)=\frac{1}{c}\int\limits^{t}_{0}i_c(t)dt+V_c(0)$
### Example
3/17/25 on notebook

## Power and Energy
* $p_c(t)=i_c(t)V_c(t)=c\frac{dV_c(t)}{dt}V_c(t)=\frac{d}{dt}[\frac{1}{2}cV^2_c(t)]$
* Power is the time rate of change of energy
### Facts about capacitance
1. Current through a capacitor is always zero. For DC voltages a capacitor acts as an open circuit
2. The voltage across the capacitor is a continuous function of time
3. The capacitor absorbs power when charging, and it releases power when discharging (both a load and a source)
4. Capacitors come in to versions: polarized and unpolarized
# AC Power
## Filtration circuits
* AC into resistor into capacitor (Low Pass)
	* Cleans up wavelength
* AC into capacitor into resistor (High Pass)
	* Filters lower frequencies
# Capacitors and Inductors pt. 2
## Capacitors
* On AC power:
	* High current is a short, Low current is open
* Lets AC pass, blocks DC
### Capacitors in Series
* 2 or more capacitors in series yield the equation $\frac{1}{\frac{1}{c_1}+...+\frac{1}{c_n}}$
	* Very very similar to how to calculate resistance in parallel
* $V_{c_k}=\frac{1}{c_k}\int\limits^{t}_{0}i(t)dt+V_{c_k}(0)$
* 
## Inductors
![[Pasted image 20250319110214.webp|250]]
* Magnetic flux
	* $\phi(t)=K_1Ni_L(t)$ -> $\lambda(t)=K_1N^2i_L(t)$
		* $K_1N^2$ Known as proportionality with symbol L 
	* So $V_L=L\frac{di_L}{dt}$ and $i_c=C\frac{dv_c}{dt}$
* Lets DC pass, blocks AC
### Power and Energy in an Inductor
* Power: $p_L(t)=\frac{d}{dt}[\frac{1}{2}Li^2_L(t)]$
* Energy: $\frac{1}{2}Li^2_L(t)$ see power equation
### Inductor Characteristics
1. Voltage is zero unless there is a charging current. Inductors act like short circuits for DC
2. Current through an inductor is a continuous inductor function of time
3. Absorbs and releases energy
### Series/Parallel Inductors
* Series inductors add like series resistors
* Parallel Inductors are combined like parallel resistors
