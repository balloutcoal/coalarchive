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
		virtual void transaction(float trans) = 0;											//2 functions for accounts
		string getName();
		
		int getAccNum(); 
		float getBalance();
		float getInterest();
		
		Account* getNext();
		void setNext(Account* _n);
		Account(int acc_number, string acc_name, float balance, float interest); // Constructor
		
};

string Account::getName(){
	return acc_name;
}

int Account::getAccNum(){
	return acc_number;
}

float Account::getBalance(){
	return balance;
}

float Account::getInterest(){
	return interest;
}

Account* Account::getNext(){
	return next;
}

void Account::setNext(Account* _n){
	this->next = next;
}

#endif