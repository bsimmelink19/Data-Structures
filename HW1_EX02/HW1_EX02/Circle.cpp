//also #11
#include "Circle.h"

circle::circle()
{
	radius = 0;
}

circle::circle(double newRadius)
{
	radius = newRadius;
}

double circle::getArea()
{
	return 3.14159 * radius * radius;
}

double circle::getRadius()
{
	return radius;
}

void circle::setRadius(double newRadius)
{
	radius = newRadius;
}