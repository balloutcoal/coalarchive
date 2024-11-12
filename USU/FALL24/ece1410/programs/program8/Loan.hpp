#ifndef LOAN_HPP
#define LOAN_HPP
#include <iostream>
#include "Account.hpp"

class Loan : public Account{
	public:
		Loan(int acc_number, string acc_name, float balance, float interest);
		
		void transaction(float amount);
		void update();
	
};

Loan::Loan(int acc_number, string acc_name, float balance, float interest) : 
	Account(acc_number, acc_name, balance, interest){}

void Loan::transaction(float amount){ //payment function
	cout << "PRE LOAN BALANCE TRANSACTION: " << balance << endl; //DEBUG
	balance -= amount;
	cout << "POST LOAN BALANCE TRANSACTION: " << balance << endl; //DEBUG
}

void Loan::update(){ //interest function
	cout << "PRE LOAN BALANCE INTEREST: " << balance << endl; //DEBUG
	balance += (balance * interest);
	cout << "POST LOAN BALANCE INTEREST: " << balance << endl; //DEBUG
}

#endif