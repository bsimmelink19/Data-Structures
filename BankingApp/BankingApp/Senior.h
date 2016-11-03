//sublcass of customer
//has specific constant data fields defined for senior customers
#ifndef _SENIOR_
#define _SENIOR_
#include "Customer.h"
class Senior : public Customer
{
private:
	//constant member variables, depends on customer type
	const double SAVINGS_INTEREST = 0.02;
	const double CHECK_INTEREST = 0.015;
	const double CHECK_CHARGE = 5;
	const double OVERDRAFT_PENALTY = 20;
public:
	//constructor
	Senior(std::string N, std::string A, int ag, std::string num, int Cnum) : Customer(N, A, ag, num, Cnum) {};
	//standard accessor and setter functions
	double get_SAVINGS_INTEREST()
	{
		return SAVINGS_INTEREST;
	}
	double get_CHECK_INTEREST()
	{
		return CHECK_INTEREST;
	}
	double get_CHECK_CHARGE()
	{
		return CHECK_CHARGE;
	}
	double get_OVERDRAFT_PENALTY()
	{
		return OVERDRAFT_PENALTY;
	}

};




#endif

