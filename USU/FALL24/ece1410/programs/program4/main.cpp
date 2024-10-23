/******************************************************************************

File: main.cpp

Functions main, displayMenu, takeFraction

******************************************************************************/

#include <iostream>
#include <stdexcept>
#include <numeric>
#include <tuple>
#include "rational.h"

using namespace std;

void displayMenu();
pair<int, int> takeFraction();

int main(){
	int num, den;
	int choice = -1;
	tie(num, den) = takeFraction();
	try{
		Rational r(num, den);
		cout << "Fraction reduces to ";
		r.disp();
		
		while(choice != 0){
			displayMenu();
			cin >> choice;
			try{
				switch(choice){
					case 1:{
						tie(num, den) = takeFraction();
						r.add(num, den);
						r.disp();
						break;
					}
					case 2:{
						tie(num, den) = takeFraction();
						r.sub(num, den);
						r.disp();
						break;
					}
					case 3:{
						tie(num, den) = takeFraction();
						r.mul(num, den);
						r.disp();
						break;
					}
					case 4:{
						tie(num, den) = takeFraction();
						r.div(num, den);
						r.disp();
						break;
					}
					case 0:{
						break;
					}
					default:{
						cout << "Invalid input, please try again." << endl;
						break;
					}
				}
			}catch(const invalid_argument& e) {
                cout << "Error: " << e.what() << endl;
			}
		}
	}catch(const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
	}
}

void displayMenu(){ //displays menu options
	cout << endl << "1. Add a Rational" << endl << "2. Subtract a rational" << endl <<
		"3. Mulitply by a rational" << endl << "4. Divide by a rational" <<
		endl << "0. Exit" << endl << "Enter selection: " << endl;
}

pair<int, int> takeFraction(){
	int num, den;
	cout << "Enter numerator: ";
	cin >> num;
	cout << "Enter denominator: ";
	cin >> den;
	return make_pair(num, den);
}