/******************************************************************************

Header: rational.h

Class: Rational

Purpose: to declare the class for rational.cpp

******************************************************************************/

class Rational{
	public:
	int num, den; //numerator, denominator
	
	void simplify(); //simplifies fraction
	
	Rational(int n=0, int d=1); //declares constructor
	int gcd(int n, int d); //finds greatest common denominator
	void add(int n, int d); //addition
	void sub(int n, int d); //subtraction
	void div(int n, int d); //division
	void mul(int n, int d); //multiplication
	void disp(); //prints current fraction
};