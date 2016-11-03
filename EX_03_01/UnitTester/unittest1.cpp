#include <fstream>
#include "stdafx.h"
#include "CppUnitTest.h"
#include "readint.h"
#include <stdexcept> 
#include <iostream>
using namespace std; 
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTester
{		
	TEST_CLASS(READINT_TEST)
	{
	public:
		
		TEST_METHOD(TestCase1)
		{
			ifstream ss("..\\UnitTester\\zeroinput.txt");
			if (ss.fail())
				throw int(-1);
				streambuf *orig_cin = cin.rdbuf(ss.rdbuf());
				Assert::AreEqual(read_int("My Prompt: ", -3, 3), 0);
				cin.rdbuf(orig_cin);
				ss.close();
			
		}

		TEST_METHOD(TestMethod2)
		{
			auto func = []() {
				read_int("Myprompt: ", 5, 1); 
			};
			Assert::ExpectException<std::invalid_argument>(func); 
		}
		

	};
}