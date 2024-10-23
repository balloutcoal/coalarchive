#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

struct quadraticEquation {
    int a, b, c;
    bool complex;
    double xOne, xTwo;
};

// Function prototypes
void openFile(ifstream &fInput, ofstream &fOutput, int argc, char *argv[]);
void compute(ifstream &fInput, ofstream &fOutput);
void printResult(ofstream &fOutput, const quadraticEquation &qe, bool complex);

int main(int argc, char *argv[]) {
    ifstream fInput;
    ofstream fOutput;

    openFile(fInput, fOutput, argc, argv);
    compute(fInput, fOutput);

    return 0;
}

/******************************************************************************
Function: openFile

Use: Opens the input and output files based on command-line arguments.
******************************************************************************/
void openFile(ifstream &fInput, ofstream &fOutput, int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        cout << "Usage: ./qr input.txt [output.txt]" << endl;
        exit(1);
    }

    // Open input file
    fInput.open(argv[1]);
    if (!fInput.is_open()) {
        cout << "Failed to open input file." << endl;
        exit(1);
    }

    // Open output file if provided, otherwise use the console
    if (argc == 3) {
        fOutput.open(argv[2]);
        if (!fOutput.is_open()) {
            cout << "Failed to open output file." << endl;
            exit(1);
        }
    }
}

/******************************************************************************
Function: compute

Use: Reads coefficients from the input file, computes the roots of the quadratic
      equation, and writes the results to the output file.
******************************************************************************/
void compute(ifstream &fInput, ofstream &fOutput) {
    quadraticEquation qe;
    double discriminant;

    while (fInput >> qe.a >> qe.b >> qe.c) {
        discriminant = pow(qe.b, 2) - (4 * qe.a * qe.c);

        if (discriminant > 0) {
            // Two real roots
            qe.xOne = (-qe.b + sqrt(discriminant)) / (2 * qe.a);
            qe.xTwo = (-qe.b - sqrt(discriminant)) / (2 * qe.a);
            qe.complex = false;
        } else if (discriminant == 0) {
            // One real root (double root)
            qe.xOne = qe.xTwo = -qe.b / (2 * qe.a);
            qe.complex = false;
        } else {
            // Complex roots
            qe.complex = true;
        }

        // Output result
        if (fOutput.is_open()) {
            printResult(fOutput, qe, qe.complex);
        } else {
            printResult(cout, qe, qe.complex);
        }
    }
}

/******************************************************************************
Function: printResult

Use: Outputs the results of the quadratic equation to the file or console.
******************************************************************************/
void printResult(ofstream &fOutput, const quadraticEquation &qe, bool complex) {
    if (complex) {
        fOutput << qe.a << "\t" << qe.b << "\t" << qe.c << "\tcomplex roots, did not compute" << endl;
    } else {
        fOutput << qe.a << "\t" << qe.b << "\t" << qe.c << "\t"
                << fixed << setprecision(4) << qe.xOne << "\t"
                << fixed << setprecision(4) << qe.xTwo << endl;
    }
}