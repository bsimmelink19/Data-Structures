//sublcass of customer
//has specific constant data fields defined for student customers
#ifndef _STUDENT_
#define _STUDENT_
#include "Customer.h"
class Student : public Customer
{
private:
	//constant member variables, depends on customer type
	const double SAVINGS_INTEREST = 0.01;
	const double CHECK_INTEREST = 0.005;
	const double CHECK_CHARGE = 2;
	const double OVERDRAFT_PENALTY = 10;
public:
	//constructor
	Student(std::string N, std::string A, int ag, std::string num, int Cnum) : Customer(N, A, ag, num, Cnum) {};
	//standard getter and setter functions
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


