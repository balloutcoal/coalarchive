/******************************************************************************
Functions: main, openFile, count, printResult
******************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include <iomanip>

using namespace std;

struct letterCount{
	char letters;
	int count;
};

void openFile(ifstream &fInput, ofstream &fOutput);
void count(ifstream &fInput, letterCount letters[], int &totalCount);
void printResult(ofstream &fOutput, letterCount letters[], int &totalCount);

int main(){
	ifstream fInput;
	ofstream fOutput;
	int totalCount = 0;
	openFile(fInput, fOutput);
	//initialize struct for count function
	letterCount letters[52];
	for (int i = 0; i < 26; i++) {
		//upper
		letters[i].letters = 'A' + i;  
        letters[i].count = 0;
		//lower
        letters[26 + i].letters = 'a' + i;  
        letters[26 + i].count = 0;
    }
	count(fInput, letters, totalCount);
	printResult(fOutput, letters, totalCount);
	return 0;
}

/******************************************************************************
Function: openFile

Use: Asks for input/output files, inputs them and uses the previously declared
ofstream and ifstream values and opens them to the inputs accordingly
******************************************************************************/

void openFile(ifstream &fInput, ofstream &fOutput){
	string input, output;
	cout << "Enter input file: ";
	cin >> input;
	cout << "Enter output file: ";
	cin >> output;
	fInput.open(input);
	fOutput.open(output);
	if (!fInput.is_open()){
		cout << "Failed to open input file";
		exit(0);
	}
	if (!fOutput.is_open()){
		cout << "Failed to open output file";
		exit(0);
	}
	return;
}

/******************************************************************************
Function: count

Use: Goes through every letter in the ifstream file and counts what character
it is
******************************************************************************/

void count(ifstream &fInput, letterCount letters[], int &totalCount){
	char c;
	while(fInput.get(c)){
		if(isupper(c)){
			letters[c - 'A'].count++;
			totalCount++;
		}else if(islower(c)){
			letters[c - 'a' + 26].count++;
			totalCount++;
		}
	}
	return;
}

/******************************************************************************
Function: printResult

Use: 
******************************************************************************/

void printResult(ofstream &fOutput, letterCount letters[], int &totalCount){
	float percent;
	fOutput << fixed << setprecision(2);
	fOutput << "Letter";
	fOutput.width(7);
	fOutput << "Count";
	fOutput.width(25);
	fOutput << "Percentage of Occurrence" << endl;
	for(int i = 0; i < 52; i++) {
		percent = (float(letters[i].count) / float(totalCount)) * 100;
		fOutput << letters[i].letters;
		fOutput.width(10);
		fOutput << letters[i].count;
		fOutput.width(15);
		fOutput << percent << "%" << endl;
    } 
	return;
}