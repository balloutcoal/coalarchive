#ifndef BANK_HPP
#define BANK_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


#include "Account.hpp" // ONLY BARE minimum skeleton provided


// CREATE these files ...
#include "Checking.hpp"
#include "Savings.hpp"
#include "Loan.hpp"
using namespace std;


// FEEL FREE to ADD/DELETE Anything, but make sure it does not fail compilation of UNMODIFIED test.cpp
class Bank {
	private:
		int accounts = 0;										//starts with no accounts
		Account* head;
		Account* end;
		Account* temp;

	public:
		Bank(); // Constructor
		void account(char f_letter, int acc_number, string acc_name, float balance, float interest);//creates an account
		int process(string line); //processes the input file text
		Account* findNumber(int acc_num); // Finds the account Number
		int getCount()
		{
			return accounts; 
		}
		// Provided for YOU :-)
		Account* operator[](int acc_num)
		{
			return findNumber(acc_num);										//overloads the [] operator to find the account
		}


		// ADD any other functions you deem necessary

};

// ALL IMPLEMENTATION Goes Here
Bank::Bank() : head(nullptr), end(nullptr), accounts(0) {}

void Bank::account(char f_letter, int acc_number, string acc_name, float balance, float interest){
	Account* new_account = nullptr; //Newis  account's pointer
	
	switch(f_letter){ //Checks for account type
		case 'c':
			new_account = new Checking(acc_number, acc_name, balance, interest);
			break;
		case 's':
			new_account = new Savings(acc_number, acc_name, balance, interest);
			break;
		case 'l':
			new_account = new Loan(acc_number, acc_name, balance, interest);
		default:
			break;
	}
	
	if(new_account){ //If a new account is created
		if(head == nullptr){ //If no existing accounts
			head = end = new_account;
		}else{
			end ->setNext(new_account);
			end = new_account;
		}
		accounts++;
	}
}

int Bank::process(string line){ //Processs file input lines
	stringstream ss(line);
	char f_letter;
	int acc_number;
	string acc_name;
	float balance, interest;
	
	ss >> f_letter >> acc_number >> acc_name >> balance >> interest;
	
	account(f_letter, acc_number, acc_name, balance, interest)
}

Account* Bank::findNumber(int acc_num){
	Account* current = head; //Start at front of linked list
	while(current != nullptr){
		if(current->getAccountNumber() == acc_num){ //If account numbers match
			return current;
		}
		current = current->getNext(); //Move down list
	}
	return 0; //If account number does not exist
}

#endif