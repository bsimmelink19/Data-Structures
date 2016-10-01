#include "readint.h"
#include <string>
#include <stdexcept>
#include <iostream>
#include <limits>
#include <ios>
using namespace std;

int read_int(const string &prompt, int low, int high)
{
	cin.exceptions(ios_base::failbit);
	int num = 0;
	while (true) {
		try {

			cout << prompt;
			cin >> num;
			if (num < low || num > high)
			{
				throw std::range_error("Value entered was outside the specified range. ");
			}
			return num;
		}
		catch (ios_base::failure& ex) {
			cout << "Bad numeric string -- try again" << endl;
			//reset the error flag
			cin.clear();
			//skipp current input line
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
		catch (range_error& e)
		{
			cerr << e.what() << endl;
		}
	}

}
