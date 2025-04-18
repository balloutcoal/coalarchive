* Bloodlands - Timothy Snyder
# RC+RL Natural Response Examples
3/31/25 example 1 and 2 (capacitor and inductors)
# Forced Response
3/31/25 example 3
# RC system
RC circuit
* Over time Vc will become Va and the circuit will become open
	* $RC\frac{dV_c(t)}{dt}+V_c(t)=V_au(t)$
	* $RC\frac{dV_f(t)}{dt}+V_f(t)=V_a$
		* After a long time $dV_f(t)$ goes to 0 so $V_f(t)=V_a$
* Forced solution: $V_c(t)=V_{cn}+V_{cf}=Ke^{-t/RC}+V_A$
	* Where $V_{cn}$ is natural
	* $V_{cf}=K+V_A=V_0$
	* $K=V_0-V_a$
	* $V_c(t)=(V_0-V_A)e^{-t/RC}+V_A$
	* $V_c(0)=V_0$
	* $\lim_{t \to \infty}V_c(t)=V_A$
## Example
4/2/25 example 1