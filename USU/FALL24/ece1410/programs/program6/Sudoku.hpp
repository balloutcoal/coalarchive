/*******************************************************************************


*******************************************************************************/

#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <iostream>
#include <fstream>

using namespace std;

class Sudoku{
	public:
	
	Sudoku(); //Initializes grid
	bool solve(); //Solves puzzle
	void printGrid() const; //Prints grid 
	int getValue(int i, int j); //Get value at location in grid
	
	private:
	
	int grid[9][9]; //9x9 grid
	
	bool isValid(int row, int col, int num) const; //Checks if spot can be used
	bool findEmpty(int &row, int &col) const; //Looks for empty location
	friend istream& operator>>(istream& in, Sudoku& sudoku); //Overloader
};

Sudoku::Sudoku(){//Builds empty grid
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			grid[i][j] = 0;
		}
	}
}

bool Sudoku::solve(){//Basic solve loop
	int row, col;
	
	if(!findEmpty(row, col)){ //Checks if solved
		return true;
	}
	
	for(int i = 1; i < 10; ++i){
		if(isValid(row, col, i)){
			grid[row][col] = i;
			
			if(solve()){ //Returns to start of function recursively
				return true;
			}
			
			grid[row][col] = 0; //Backtrack if i leads to nothing
		}
	}
	
	return false; //Backtrack further
}

void Sudoku::printGrid() const{ //Prints out the grid
	for(int i = 0; i < 9; ++i){
		for(int j = 0; j < 9; ++j){
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}

int Sudoku::getValue(int i, int j){ //Prints specific value of grid
	return grid[i][j];
}

bool Sudoku::findEmpty(int &row, int &col) const{ //Looks for empty spot in grid
	for(row = 0; row < 9; ++row){
		for(col = 0; col < 9; ++col){
			if(grid[row][col] == 0){
				return true; //Found empty location
			}
		}
	}
	return false; //Nothing found
}

bool Sudoku::isValid(int row, int col, int num) const{ //Checks if empty spot is good
	for(int i = 0; i < 9; ++i){ //Checks row
		if(grid[row][i] == num){
			return false;
		}
	}
	for(int i = 0; i < 9; ++i){ //Checks column
		if(grid[i][col] == num){
			return false;
		}
	}
	
	//Checks the 3x3 grids
	int subRow = row / 3 * 3;
	int subCol = col / 3 * 3;
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			if(grid[subRow + i][subCol + j] == num){
				return false;
			}
		}
	}
	return true;
}

 istream& operator>>(istream& in, Sudoku& sudoku){
	for(int i = 0; i < 9; ++i){
		for(int j = 0; j < 9; ++j){
			in >> sudoku.grid[i][j];
		}
	}
	return in;
}

#endif