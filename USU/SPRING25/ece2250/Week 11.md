# Recap
## Inductors
* Inductor in series: $L_{eq}=L_1+L_2+...+L_n$
	* Voltages: $V(t)=V_{L_1}(t)+V_{L_2}(t)+...+V_{L_n}(t)$
	* $= L_1\frac{di(t)}{dt}+L_2\frac{di(t)}{dt}+...+L_n\frac{di(t)}{dt}$
	* $= (L_1+L_2+...+L_n)\frac{di(t)}{dt}$
* Inductor in Parallel:
	* Current: $i(t)=i_1(t)+i_2(t)$
	* $=i_1(0)+i_2(0)+[\frac{1}{L_1}+\frac{1}{L_2}]\int i(t)dt$
# New
## Transformers
3/24/25 drawing 1
* Changes voltages, used in power grid to step dangerous voltages down, current losses are tiny
* The current in the coil produces a magnetic flux:
	* $\phi=K_1N_1i_1(t)$
		* where K is the proportionality constant, and N is the number of turns/coils in the inductor
	* $V_1(t)=N_1\frac{d\phi}{dt}=K_1N^2_1\frac{di_1(t)}{dt}=L\frac{di_1(t)}{dt}$
### Multiple Transformers Interactions
* Multiple transformers would interact with each other's magnetic flux but voltages are unaffected
1. Building Voltage Equations:
	1. $V_1=L_1\frac{di(1)}{dt}+$ stuff (due to the magnetic flux from coil #2 ($i_2(t)$))
	2. $V_2$ same as $V_1$ but swapped between coils
2. Plug in "stuff"
	1. $V_1=L_1\frac{di_1(t)}{dt}+K_{1 2}N_1N_2\frac{d_1(t)}{dt}$
	2. $V_2=L_1\frac{di_2(t)}{dt}+K_{2 1}N_2N_1\frac{d_1(t)}{dt}$
3. Simplify "stuff"
	1. You're able to turn $K_{12}N_1N_2$ into $M_{12}$ and $K_{21}N_2N_1$ into $M_{21}$
	2. Where $M_{12}=M_{21}=M$
4. Final Voltages:
	1. $V_1=L_1\frac{di_1(t)}{dt}+M\frac{di_2(t)}{dt}$
	2. $V_2=L_2\frac{di_2(t)}{dt}+M\frac{di_1(t)}{dt}$
#### Positive vs Negative
3/24/25 drawing 2
#### Power in Multiple Transformers
* $p_1(t)=V_1(t)i_1(t) = L_1i_1(t)\frac{di_1(t)}{dt}\pm Mi_1(t)\frac{di_2(t)}{dt}$
* $p_2(t)=V_2(t)i_2(t)= L_2i_2(t)\frac{di_2(t)}{dt}\pm Mi_2(t)\frac{di_1(t)}{dt}$
* $p_{total}(t)=p_1+p_2$
	* $=L_1[i_t\frac{di_1(t)}{dt}]\pm M[i_1(t)\frac{di_2(t)}{dt}+i_2(t)\frac{di_1(t)}{dt}]+L_2[i_2(t)\frac{di_1(t)}{dt}]$
	* $= \frac{d}{dt}[\frac{1}{2}L_1i^2_1(t)\pm Mi_1(t)i_2(t)+\frac{1}{2}L_2i^2_2(t)]$
	* $=\frac{d}{dt}\omega(t)$ where $\omega$ is energy, Joules/sec
	* $\omega(t)=[\frac{1}{2}L_1i^2_1(t)\pm Mi_1(t)i_2(t)+\frac{1}{2}L_2i^2_2(t)]$
* $f=\frac{\omega(t)}{i^2_2(t)}=\frac{1}{2}L_1x^2\pm Mx+\frac{1}{2}L_2$
	* where $x=\frac{i_1(t)}{i_2(t)}$ this equation is derived really strangely just roll with it
	* The x makes the equation quadratic, making it easier to work with
	* $x_{min}=\pm\frac{M}{L_1}$
	* $f(x_{min}): L_2-\frac{M^2}{L_1}\ge 0, L^2 \ge \frac{M^2}{L_1}, L_1L_2 \ge M^2$ or $\sqrt{L_1L_2} \ge M$
!!Euler's Identity: $e^{j\pi}+1=cos\pi+jsin\pi+1=0$!!
# Review
* Capacitors
	* Power first applied acts like a short
	* Power been applied acts like an open circuit
* Inductors
	* Power first applied acts like an open circuit
	* Power been applied acts like a short
* Transformers
	* Does not work on DC power