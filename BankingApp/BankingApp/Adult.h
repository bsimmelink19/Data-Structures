//sublcass of customer
//has specific constant data fields defined for adult customers
#ifndef _ADULT_
#define _ADULT_
#include "Customer.h"
class Adult : public Customer
{
private:
	//constant member variables, specific to each customer type
	const double SAVINGS_INTEREST = 0.025;
	const double CHECK_INTEREST = 0.02;
	const double CHECK_CHARGE = 7;
	const double OVERDRAFT_PENALTY = 25;
public:
	//constructor
	Adult(std::string N, std::string A, int ag, std::string num, int Cnum) : Customer(N, A, ag, num, Cnum) {};
	//standard accessor functions for member variables
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

