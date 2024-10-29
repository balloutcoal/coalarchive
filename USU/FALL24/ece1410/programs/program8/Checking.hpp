#ifndef CHECKING_HPP
#define CHECKING_HPP

#include "Account.hpp"

class Checking : public Account{
	protected:
		float balance, interest;
		
	public:
		Checking(int acc_number, string acc_name, float balance, float interest);
		
		//void deposit(float amount);

	
};

Checking::Checking(int acc_number, string acc_name, float balance, float interest) : 
	Account(acc_number, acc_name, balance, interest){}

#endif