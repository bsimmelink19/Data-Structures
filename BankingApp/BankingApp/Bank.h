#ifndef BANK_H_
#define BANK_H_
#include <vector>
#include <stdexcept>
#include "Account.h"
#include "Customer.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Adult.h"
#include "Senior.h"
#include "Student.h"
/**
The CS273 Bank has Accounts and Customers

@author: Ed Walker
*/
class Bank
{
private:
	std::vector<Account *> accounts; // Bank HAS accounts
	std::vector<Customer *> customers;  // Bank HAS customers

								 // Counters for generating unique account and customer IDs
	int account_id;
	int customer_id;


	/**
	Return a vector of accounts owned by the specified name of the customer.
	Remember a customer can have many accounts.
	@param name The customer name
	@return vector of account ids
	*/
	std::vector<int> find_accounts_by_name(std::string name)
	{
		std::vector<int> user_accounts;
		for (unsigned int i = 0; i < accounts.size(); i++)
		{
			// FIXME: Find all the accounts belonging to a customer name and add it to the vector of account numbers.
			//pointer to the account in the ith position of the vector
			Account *testAccount = accounts[i];
			//pointer to the customer associated with that account
			Customer *testCustomer = testAccount->get_customer();
			//the name of that customer
			std::string testName = testCustomer->get_name();
			//checks if that account has the name entered associated with it
			if (testName == name)
			{
				//the account number for that account
				int acct = accounts[i]->get_account();
				//stores that account ID in a vector
				user_accounts.push_back(acct);
			}
		}
		return user_accounts;
	}

	/**
	Find a customer based on his/her name
	@param name The customer name
	@return customer object if found, NULL otherwise
	*/
	Customer *find_customer(std::string name)
	{
		// FIXME: Find and return the Customer object with the parameter name
		//searches the vector of customers for one with the entered name
		for (unsigned int i = 0; i < customers.size(); i++)
		{
			std::string testName = customers[i]->get_name();
			if (testName == name)
			{
				//returns the customer at the ith position of the vector
				return customers[i];
			}
		}
		//if no math is found, returns NULL
		return NULL;
	}

	/**
	Add a new account to a customer object (irrespective of its specific type: adult, senior, or student)
	@param cust The customer object
	@param account_type The account type, i.e. "savings" or "checking"
	@return the newly created account object
	*/
	Account * add_account(Customer *cust, std::string account_type)
	{
		//Account *acct = NULL;
		// FIXME: Factory method for creating a Account object (could be a Saving_Account or a Checking_Account).
		//return acct;
		if (account_type == "Savings")
		{

			//creates a new savings account
			Account *acct = new Savings_Account(cust, account_id);
			//stores that account in the accounts vector
			accounts.push_back(acct);
			//increments the account ID, so next account will have different ID
			account_id++;
			return acct;
		}
		if (account_type == "Checking")
		{
			//creates a new checking account
			Account *acct = new Checking_Account(cust, account_id);
			//stores that account in the accounts vector
			accounts.push_back(acct);
			//increments the account ID, so next account will have a different ID
			account_id++;
			return acct;
		}
	}

public:
	/** Constructor
	*/
	Bank() : account_id(1000), customer_id(1000) {}

	/**
	Add account for an existing user
	@param name The customer name
	@param account_type The account type, i.e. "checking" or "savings"
	@return the newly created account object if the customer exist, or NULL otherwise
	*/
	Account* add_account(std::string name, std::string account_type)
	{
		Customer *cust = find_customer(name);
		if (cust == NULL)
			return NULL;
		return add_account(cust, account_type);
	}

	/**
	Add account for new user.  This creates a new customer and adds an account to him/her.
	@param name Customer name
	@param address Customer address
	@param telephone Customer telephone number
	@param age Customer age
	@param cust_type Customer type, i.e. "adult", "senior" or "student"
	@param account_type Account type, i.e. "checking" or "savings"
	@return the newly created account object
	*/
	Account* add_account(std::string name, std::string address, std::string telephone, int age,
		std::string cust_type, std::string account_type)
	{
		// FIXME: Depending on the customer type, we want to create an Adult, Senior, or Student object.
		Customer *cust;
		//checks type of customer
		if (cust_type == "Senior")
		{
			//creates a new senior customer
			cust = new Senior(name, address, age, telephone, customer_id);
			//increments customer ID, so next customer will have different ID
			customer_id++;
		}
		if (cust_type == "Adult")
		{
			//creates a new adult customer
			cust = new Adult(name, address, age, telephone, customer_id);
			//increments customer ID, so next customer will have different ID
			customer_id++;
		}
		if (cust_type == "Student")
		{
			//creates new student customer
			cust = new Student(name, address, age, telephone, customer_id);
			//incrememnts customer ID, so next customer will have a different ID
			customer_id++;
		}
		customers.push_back(cust);
		return add_account(cust, account_type);
	}

	/**
	Make a deposit in an account identified by the account id
	@param acct_number	The account id
	@param amt			The amount to deposit
	*/
	void make_deposit(int acct_number, double amt)
	{
		// FIXME: Deposit the amt in the account
		//creates a pointer to the account specified by the account number
		Account *acct = get_account(acct_number);
		//if that account exists, adds the amount to the balance
		if (acct) {
			acct->deposit(amt);
		}
		//displays error message if the specified account does not exist
		else std::cout << "The specified account could not be found." << std::endl;
	}

	/**
	Make a withdrawal in an account identified by the account id
	@param acct_number	The account id
	@param amt			The amount to withdraw
	*/
	void make_withdrawal(int acct_number, double amt)
	{	// FIXME: Withdraw the amt from the account
		//creates a pointer to the account specified by the account number
		Account *acct = get_account(acct_number);
		//if the account exists
		if (acct) {
			//subtracts the ampount from the balance
			acct->withdraw(amt);
		}
		else std::cout << "The specified account could not be found." << std::endl;
	}

	/**
	Get the list of account numbers associated with a user, identified by his/her name
	@param name The customer name
	@return vector of account ids
	*/
	std::vector<int> get_account(std::string name)
	{
		return find_accounts_by_name(name);
	}

	/**
	Get the account object for an account identified by an account id
	@param acct_name The account id
	@return the account object if it exists, NULL otherwise
	*/
	Account *get_account(int acct_number)
	{
		for (size_t i = 0; i < accounts.size(); i++) {
			if (accounts[i]->get_account() == acct_number)
				return accounts[i];
		}
		return NULL;
	}

};

#endif

