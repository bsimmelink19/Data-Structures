#include <iostream>
using namespace std;
#include "Cat.h"
#include "Circle.h"

int main()
{
	//#27
	cat mittens;

	//#28
	circle c1(1.1);
	circle c2(1.4);
	circle c3(c1 + c2);
	cout << "New Circle's radius: " << c3.getRadius() << endl;


	return 0;
}