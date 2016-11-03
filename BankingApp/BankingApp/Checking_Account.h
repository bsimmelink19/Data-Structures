#ifndef _CHECKING_ACCOUNT_
#define _CHECKING_ACCOUNT_
#include "Account.h"

class Checking_Account : public Account
{
public:
	//constructor
	Checking_Account(Customer *cust, int id)
	{
		customer = cust;
		balance = 0;
		account_number = id;
	}
	virtual std::string to_string()
	{
		std::stringstream ss; // for composing the string that describes this account

						  // FIXME: Add information about the customer who owns this account.
						  //displays the name and customer number of the customer
		ss << " Customer Name: " << customer->get_name() << std::endl;
		ss << " Customer ID: " << customer->get_customer_number() << std::endl;
		ss << " Account Type: Checking" << std::endl;
		ss << "  Balance: " << balance << std::endl;
		ss << "  Account ID: " << account_number << std::endl;
		return ss.str();
	}
	//adds interest, depending on the type of customer
	void add_interest()
	{
		//sets the interest to the interest of the customer's type
		double interest = customer->get_CHECK_INTEREST();
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
		if (balance - amt > 0)
		{
			balance -= amt;
			std::string fees = get_fees();
			std::string type = "Withdrawal";
			int num = customer->get_customer_number();
			//creates a new transaction object
			Transaction *tran = new Transaction(num, type, amt, get_fees());
			//stores the new transaction in the trnasactions vector
			transactions.push_back(tran);
		}
		//displays an error message if the amount exceeds the current balance.
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
		//stores that transaction in the transactions vector
		transactions.push_back(tran);
	}

};


#endif

