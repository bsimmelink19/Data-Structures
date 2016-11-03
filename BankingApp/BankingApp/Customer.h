#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <string>

/**
The Bank has Customers.  Each Customer has a name, address, age, and telephone number.
Additionally, there are specialized types of Customers: Adult, Senior, and Student.
Each type of Customer has its own checking and savings interest rates,
as well as its own checking and overdraft fees.

@author: Ed Walker
*/
class Customer // FIXME: Complete the implementation! Done
{
protected:
	std::string name;
	std::string address;
	int age;
	std::string telephone_number;
	int customer_number;
public:
	//constructor
	Customer(std::string N, std::string A, int ag, std::string num, int Cnum)
	{
		name = N;
		address = A;
		age = ag;
		telephone_number = num;
		customer_number = Cnum;
	}
	//standard accessor and setter functions
	std::string get_name()
	{
		return name;
	}
	void set_name(std::string N)
	{
		name = N;
	}
	std::string get_address()
	{
		return address;
	}
	void set_address(std::string A)
	{
		address = A;
	}
	int get_age()
	{
		return age;
	}
	void set_age(int A)
	{
		age = A;
	}
	std::string get_telephone_number()
	{
		return telephone_number;
	}
	void set_telephone_number(std::string num)
	{
		telephone_number = num;
	}
	int get_customer_number()
	{
		return customer_number;
	}
	void set_customer_number(int num)
	{
		customer_number = num;
	}
	//implemented in the senior, adult, and student classes
	virtual double get_SAVINGS_INTEREST() = 0;
	virtual double get_CHECK_INTEREST() = 0;
	virtual double get_CHECK_CHARGE() = 0;
	virtual double get_OVERDRAFT_PENALTY() = 0;
};


#endif
