/******************************************************************************
Functions: main, openFile, compute, quadraticEquation(computeRoots,
	printResult)
******************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

/******************************************************************************
Class: quadraticEquation

Use: Has 3 integers to represent a quad polynomial, finds the discriminant,
	and determines if it is a complex, if it is, do not compute and print 
	according, if not, finish computing the equation and print out the two
	x values as double floats
******************************************************************************/

class quadraticEquation{
	public:
		int a, b, c;
		bool complex;
		double xOne, xTwo;
		//construct
		quadraticEquation(int a, int b, int c) : a(a), b(b), c(c), complex(false), xOne(0), xTwo(0) {}
		//internally compute
		void computeRoots(){
			double d = (pow(b, 2) - (4 * a * c)); //discriminate before rooted
			if (d > 0){ //if discriminate is above zero
				xOne = (-b + sqrt(d)) / (2 * a);
				xTwo = (-b - sqrt(d)) / (2 * a);
			}else if (d == 0){ //if discriminate is zero
				xOne = xTwo = -b / (2 * a);
			}else{ //if discriminate is below zero (complex)
				complex = true;
			}
		}
		//internally output
		void printResult(ostream &outStream){
			outStream << a << " " << b << " " << c << " ";
			outStream << fixed << setprecision(4);
			if (!complex){
				outStream << fixed << setprecision(4);
				outStream << xOne << " " << xTwo << " " << endl;
			}else{
				outStream << "complex roots, did not compute" << endl;
			}
		}
};

void openFile(ifstream &fInput, ofstream &fOutput, ostream *&outStream, int argc, char *argv[]);
void compute(ifstream &fInput, ostream *outStream);

int main(int argc, char *argv[]){
	ifstream fInput;
	ofstream fOutput;
	ostream *outStream; //if no output file is given
	openFile(fInput, fOutput, outStream, argc, argv);
	compute(fInput, outStream);
	fInput.close();
	if (fOutput.is_open()){
		fOutput.close();
	}
	return 0;
}

/******************************************************************************
Function: openFile

Use: Takes command line arguments and opens them as input then output
******************************************************************************/

void openFile(ifstream &fInput, ofstream &fOutput, ostream *&outStream, int argc, char *argv[]){
	fInput.open(argv[1]);
	fOutput.open(argv[2]);
	if (!fInput.is_open()){ //if cannot open input
		cout << "Failed to open input file";
		exit(0);
	}
	if (fOutput.is_open()){ //if cannot open output
		outStream = &fOutput;
	}else{
		outStream = &cout;
	}
	return;
}

/******************************************************************************
Function: compute

Use: Utilizes the input file and class functions to compute the quadradic
	equation or not if complex
******************************************************************************/

void compute(ifstream &fInput, ostream *outStream){
	int a, b, c;
	while(fInput >> a >> b >> c){
		quadraticEquation qe(a, b, c);
		qe.computeRoots();
		qe.printResult(*outStream);
		}
	return;
}