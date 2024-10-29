#ifndef SAVINGS_HPP
#define SAVINGS_HPP

#include "Account.hpp"

class Savings : public Account{
	protected:
		float balance, interest;
		
	public:
		Savings(int acc_number, string acc_name, float balance, float interest);
		
		//void deposit(float amount);

	
};

Savings::Savings(int acc_number, string acc_name, float balance, float interest) : 
	Account(acc_number, acc_name, balance, interest){}
	
#endif