#include "readint.h"
#include <stdexcept>
#include <iostream>
#include <limits>
#include <ios>

using namespace std;

int read_int(const string &prompt, int low, int high)
{
	cin.exceptions(ios_base::failbit);
	int num = 0;
	while (true)
	{
		if (low >= high)
			throw invalid_argument("Your lower bound exceeds your upper bound, please try again.");

		try
		{
			cout << prompt;
			cin >> num;
			if (num > high || num < low)
				throw range_error("Out of range, please try again. ");
			return num;
		}
		catch (ios_base::failure &ex)
		{
			cout << "Invalid entry, please try again. " << endl;
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
		catch (range_error & ex)
		{
			cout << ex.what() << endl;
		}

	}
}