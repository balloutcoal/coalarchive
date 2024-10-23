/******************************************************************************

File: MyComplex.hpp

Purpose: Calculcates equations with imaginary and real numbers

Class: MyComplex

Functions: add, sub, mul, div, print
******************************************************************************/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class MyComplex{
	private:
	float real, imag;
	
	public:
	MyComplex() : real(0), imag(0){} //default constructor
	MyComplex(float r, float i) : real(r), imag(i){} //constructor with parts
	
	string printMyComplex() const{ //print function
		ostringstream output;
		output << fixed << setprecision(1);
		output << real;
		if (imag >=0){
			output << " + " << imag << "i";
		}else{
			output << " - " << -imag << "i";
		}
		return output.str();
	}
	
	MyComplex operator+(const MyComplex& other){ //add
		return MyComplex(real + other.real, imag + other.imag); 
	}
	MyComplex operator-(const MyComplex& other){ //sub
		return MyComplex(real - other.real, imag - other.imag); 
	}
	MyComplex operator*(const MyComplex& other){ //multiply
		float newReal = (real * other.real) - (imag * other.imag);
		float newImag = (real * other.imag) + (imag * other.real);
		return MyComplex(newReal, newImag); 
	}

};