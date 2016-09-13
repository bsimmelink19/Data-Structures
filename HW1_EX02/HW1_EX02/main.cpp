#include <iostream>
#include "Circle.h"
using namespace std;

int main()
{
	//#12
	//declares a circle with the default constructor
	circle myCircle1;
	//tests the default constructor
	cout << "Radius of myCircle1: " << myCircle1.getRadius() << endl;

	//#13
	//declares a circle with the overloaded constructor, initialized to 10
	circle myCircle2(10);
	//tests the overloaded constructor
	cout << "Radius of myCircle2: " << myCircle2.getRadius() << endl;

	//#14
	//declares a pointer to a circle and allocates memory using the overloaded constructor
	circle* myCircle3 = new circle(12);

	//tests allocating memory for an object with the overloaded constructor
	cout << "Radius of myCircle3: " << myCircle3->getRadius() << endl;

	//#15
	//declares an array of ten circles; 
	circle circleList[10];

	//#16
	//assigns 15 to the radius of every circle in the array
	for (int i = 0; i < 10; i++)
	{
		circleList[i].setRadius(15);
	}
	//tests that the previous loop assigned 15 to every radius 
	for (int i = 0; i < 10; i++)
	{
		cout << circleList[i].getRadius() << endl;
	}

	return 0;
}