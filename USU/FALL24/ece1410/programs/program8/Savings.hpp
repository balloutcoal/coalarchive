#ifndef SAVINGS_HPP
#define SAVINGS_HPP
#include <iostream>
#include "Account.hpp"

class Savings : public Account{	
	public:
		Savings(int acc_number, string acc_name, float balance, float interest);
		
		void transaction(float amount);
		void update();
	
};

Savings::Savings(int acc_number, string acc_name, float balance, float interest) : 
	Account(acc_number, acc_name, balance, interest){}

void Savings::transaction(float amount) {
	std::cout << "PRE SAVINGS BALANCE TRANSACTION: " << balance << std::endl; //DEBUG
    balance += amount;
    std::cout << "POST SAVINGS BALANCE TRANSACTION: " << balance << std::endl; //DEBUG
}

void Savings::update(){ //interest function
	cout << "PRE SAVINGS BALANCE INTEREST: " << balance << endl; //DEBUG
	balance += (balance * interest);
	cout << "POST SAVINGS BALANCE INTEREST: " << balance << endl; //DEBUG
}

#endif