#ifndef LOAN_HPP
#define LOAN_HPP

#include "Account.hpp"

class Loan : public Account{
	protected:
		float balance, interest;
		
	public:
		Loan(int acc_number, string acc_name, float balance, float interest);
		
		//void deposit(float amount);

	
};

Loan::Loan(int acc_number, string acc_name, float balance, float interest) : 
	Account(acc_number, acc_name, balance, interest){}
	
#endif