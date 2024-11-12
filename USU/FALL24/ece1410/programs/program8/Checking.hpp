#ifndef CHECKING_HPP
#define CHECKING_HPP
#include <iostream>
#include "Account.hpp"

class Checking : public Account{
	public:
		Checking(int acc_number, string acc_name, float balance, float interest);
		
		void transaction(float amount);
		void update();
	
};

Checking::Checking(int acc_number, string acc_name, float balance, float interest) : 
	Account(acc_number, acc_name, balance, interest){}

void Checking::transaction(float amount) { //transaction function
	cout << "PRE CHECKING BALANCE TRANSACTION: " << balance << endl;
    if (amount < 0 && balance + amount < 0) { //withdrawal check
        balance -= 25; //overdraft fee
        cout << "OVERDRAFT FEE APPLIED: -25" << endl; //DEBUG
    }
    
    balance += amount;
    
    cout << "POST CHECKING BALANCE TRANSACTION: " << balance << endl; //DEBUG
}

void Checking::update(){
	cout << "PRE CHECKING BALANCE CHECK: " << balance << endl; //DEBUG
	balance -= interest; //CHECK FEE
	cout << "POST CHECKING BALANCE CHECK: " << balance << endl; //DEBUG
}

#endif