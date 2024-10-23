/******************************************************************************

File: rational.cpp

Functions Rational, gcd, simplify, add, sub, div, mul

Purpose: tied to rational.h to run fraction calculations

******************************************************************************/

#include <iostream>
#include <stdexcept>
#include <numeric>
#include <tuple>
#include "rational.h"

using namespace std;

Rational::Rational(int n, int d):num(n), den(d){
	if (d == 0){ //if denominator is zero
		throw invalid_argument("Denominator cannot be zero");
	}
	simplify();
}

int Rational::gcd(int a, int b){
	while (b != 0){
		int temp = b;
		b = a % b;
		a = temp;
	}
	return abs(a);
}

void Rational::simplify(){
	int temp = gcd(num, den); //find greatest common denominator
	num /= temp;
	den /= temp;
	if(den < 0){ //keep negative up with numerator
		num = -num;
		den = -den;
	}
}

void Rational::add(int n, int d){
	if (d == 0){ //if denominator is zero
		throw invalid_argument("Denominator cannot be zero");
	}
	num = (num * d) + (den * n);
	den *= d;
	simplify();
}

void Rational::sub(int n, int d){
	if (d == 0){ //if denominator is zero
		throw invalid_argument("Denominator cannot be zero");
	}
	num = (num * d) - (den * n);
	den *= d;
	simplify();
}

void Rational::div(int n, int d){
	if (d == 0){ //if denominator is zero
		throw invalid_argument("Denominator cannot be zero");
	}
	num *= d;
	den *= n;
	simplify();
}

void Rational::mul(int n, int d){
	if (d == 0){ //if denominator is zero
		throw invalid_argument("Denominator cannot be zero");
	}
	num *= n;
	den *= d;
	simplify();
}

void Rational::disp(){
	cout << num << "/" << den << endl;
}