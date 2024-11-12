#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Account 
{
	// YOU MAY MODIFY ANYTHING HERE

	protected:
		Account* next;
		int acc_number;
		string acc_name;
		float balance;
		float interest;
		

	public:

		virtual void update() = 0;
		virtual void transaction(float amount) = 0;	//2 functions for accounts
		string getName() const;
		
		int getAccNum() const; 
		float getBalance() const;
		float getInterest() const;
		
		Account* getNext() const;
		void setNext(Account* _n);
		Account(int acc_number, string acc_name, float balance, float interest)
			: acc_number(acc_number), acc_name(acc_name), balance(balance), interest(interest), next(nullptr) {} // Constructor
		
};

string Account::getName() const{
	return acc_name;
}

int Account::getAccNum() const{
	return acc_number;
}

float Account::getBalance() const{
	return balance;
}

float Account::getInterest() const{
	return interest;
}

Account* Account::getNext() const{
	return next;
}

void Account::setNext(Account* _n){
	this->next = _n;
}

#endif