#ifndef _CIRCLE_
#define _CIRCLE_

//#11
class circle
{
private:
	double radius;
public:
	circle(); //default constructor 
	circle(double newRadius); //overloaded constructor 
	double getArea(); //returns the area of the circle 
	double getRadius(); //getter
	void setRadius(double newRadius); //setter

};

#endif 
