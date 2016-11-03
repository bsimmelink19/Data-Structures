#ifndef _SAVINGS_ACCOUNT_
#define _SAVINGS_ACCOUNT_
#include "Account.h"

class Savings_Account : public Account
{
public:
	//constructor
	Savings_Account(Customer *cust, int id)
	{
		customer = cust;
		balance = 0;
		account_number = id;
	}
	virtual std::string to_string()
	{
		std::stringstream ss; // for composing the string that describes this account

						  // FIXME: Add information about the customer who owns this account.
						  //displays the customer associated with the account's name and customer ID
		ss << " Customer Name: " << customer->get_name() << std::endl;
		ss << " Customer ID: " << customer->get_customer_number() << std::endl;
		ss << " Account Type: Savings" << std::endl;
		ss << "  Balance: " << balance << std::endl;
		ss << "  Account ID: " << account_number << std::endl;
		return ss.str();
	}
	//adds interest depending on the type of customer
	void add_interest()
	{
		//interest is the savings interest depending on the type of customer
		double interest = customer->get_SAVINGS_INTEREST();
		double amt = balance*interest;
		balance = balance + amt;
		std::string fees = get_fees();
		std::string type = "Interest";
		int num = customer->get_customer_number();
		Transaction *tran = new Transaction(num, type, amt, get_fees());
		transactions.push_back(tran);
	}

	virtual void withdraw(double amt) {
		// FIXME: Create a Transaction object and assign it to tran.
		//if the balance exceeds the amount
		if (balance - amt > 0)
		{
			balance -= amt;
			std::string fees = get_fees();
			std::string type = "Withdrawal";
			int num = customer->get_customer_number();
			//creates a new transaction object
			Transaction *tran = new Transaction(num, type, amt, get_fees());
			//stores the new transaction in the transactions vector
			transactions.push_back(tran);
		}
		//displays an error message if the amount exceeds the current balance
		else std::cout << "Your request exceeds the current balance." << std::endl;
	}

	virtual void deposit(double amt) {
		// FIXME: Create a Transaction object and assign it to transaction vector.
		balance += amt;
		std::string fees = get_fees();
		std::string type = "Deposit";
		int num = customer->get_customer_number();
		//creates a new transaction object
		Transaction *tran = new Transaction(num, type, amt, get_fees());
		//stores the new transaction object in the transactions vector
		transactions.push_back(tran);
	}
};

#endif

