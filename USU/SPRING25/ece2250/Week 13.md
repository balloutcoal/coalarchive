# 555 Timer Circuit
4/7/25 circuit 1 and 2
## Explanations
* Circuit 1:
	* Output and discharge are open when $V_2\le V{cc}$
	* They close when $V_1\ge V_{cc}$
* Circuit 2
	* Initially the switch is open
	* For $t_1$
		* $V_c(t)=V_{cc}(1-e^{-t/\tau})$
		* $\tau=(R_1+R_2)C$
		* $t_1=-\tau ln\frac{1}{3}$ 
	* For $t \ge t_1$
		* $V_c(t)=\frac{2}{3}V_{cc}e^{-t/R_2 C}$ 
		* The device opens the switch when $V_c(t)=\frac{1}{3}V_{cc}$
		* $t_2=-R_2Cln\frac{1}{2}$
		* $t_3=-ln\frac{1}{2}(R_1+R_2)C$
	* This forms a sharkfin like waveform
	* $t_2+t_3=-ln\frac{1}{2}(2R_2+R_1)C=t_{period}$ 
# Maximum Power Transfer
4/9/25 circuit 1
## Designing an Interface:
### Example 1
4/9/25 circuit 2
1. Solve for $R_L$
	1. Select $R_L$ where $V_{RL}>3V$
	2. Expand $V_{RL}$ where $V_{RL}=\frac{5R_L}{R_L+10\Omega}>3V$
	3. Solve $R_L>15\Omega$
2.  We want $i_{R_L} < 0.1A$
	1. $\frac{5}{10+R_L}<0.1A$
	2. $R_L>40\Omega$
3. So $R_L>40\Omega$ or $R_L>15\Omega$
### Example 2
4/9/25 circuit 3
1. Want $100V=V_{R_L}$ so we put a series resistor on the interface
	1. $V_{R_L}=\frac{500(50)}{50+R_S+50}=100V$
	2. $R_S=150\Omega$
2. We try a parallel resistor
	1. $V_{R_L}=\frac{500\frac{50R_P}{50+R_P}}{50+\frac{50R_P}{50+R_P}}=100V$
	2. $R_P=16.67\Omega$
### Example 3
4/9/25 circuit 4
1. Want $75\Omega$ from voltage source across circuit
	1. Short the voltage and load
		1. $R_2||50+R_1=75$ and $R_2||(R_1+75)=50$
	2. Build and solve the equations
		1. $R_1 = 43.3\Omega$ and $R_2=86.6\Omega$
# Review
## Supernode
* When a circuit has multiple voltage sources, you can isolate the nodes connected to the source and treat it as one big node using node voltage analysis
	* Superposition is better
## Supermesh
* When a circuit has a voltage and current source you treat the current as an open circuit and do mesh analysis on the big mesh
	* Superposition is better
## Natural Response
* Let a circuit with a capacitor charge until it opens, then flip switch from capacitor to resistor