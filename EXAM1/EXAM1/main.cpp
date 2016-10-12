//I affirm that all code given below was written solely by me, Brady Simmelink, 
//and that any help I received adhered to the rules stated for this exam.

#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

namespace Exam1 // NAMESPACE
{
	class Wheel
	{
	private:
		int _radius;
	public:
		Wheel(int radius) { _radius = radius; }
		void setRadius(int radius) { _radius = radius; }
	};

	// STEP 1: Complete the implementation of the Vehicle base class 
	// as described in the UML diagram
	class Vehicle
	{
	protected:
		string _color;
		int _topspeed;
		vector<Wheel> wheels;

	public:

		Vehicle(string color) {
			// Complete the implementation
			_color = color;

			//creates four wheels with an arbitrary radius of 1
			Wheel wheel1(1);
			Wheel wheel2(1);
			Wheel wheel3(1);
			Wheel wheel4(1);

			//places the four wheels in the wheels vector
			wheels.push_back(wheel1);
			wheels.push_back(wheel2);
			wheels.push_back(wheel3);
			wheels.push_back(wheel4);

		}
		virtual void Description() = 0;
	};

	// STEP 2:  Define the RaceCar, Sedan, and Pickup classes as described
	// in the UML diagram.   For this test, you do not need to separate
	// the class implementation into a cpp file.
	class RaceCar : public Vehicle {
		//Top speed: 250mph
		//Wheel radius: 305mm
	public:
		RaceCar(string color) : Vehicle(color) {

			_topspeed = 250;
			//changes the radius of each wheel in the wheels vector from the arbitrary 1 to 305
			for (int i = 0; i < wheels.size(); i++)
			{
				wheels[i].setRadius(305);
			}

		}
		void Description()
		{
			cout << "I am a " << _color << " race car that can race " << _topspeed << "mph. Kachow!" << endl;
		}

	};

	class Sedan : public Vehicle {
		//Top speed: 95mph
		//Wheel radius: 381mm
	private:
		int number_of_seats;
	public:
		Sedan(string color, int seats) : Vehicle(color) {

			_topspeed = 95;
			number_of_seats = seats;

			//changes the radius of each wheel in the wheels vector from the arbitrary 1 to 381
			for (int i = 0; i < wheels.size(); i++)
			{
				wheels[i].setRadius(381);
			}
		}
		int get_number_of_seats() { return number_of_seats; }
		void Description()
		{
			cout << "I am a " << _color << " sedan that can carry " << get_number_of_seats() << " people at " << _topspeed << "mph!" << endl;

		}
	};

	class Pickup : public Vehicle {
		//Top speed: 85mph
		//Wheel radius: 432mm
	private:
		int hauling_capacity;
	public:
		Pickup(string color, int capacity) : Vehicle(color) {

			_topspeed = 85;
			hauling_capacity = capacity;

			//changes the radius of each wheel in the wheels vector from the arbitrary 1 to 432
			for (int i = 0; i < wheels.size(); i++)
			{
				wheels[i].setRadius(432);
			}
		}
		int get_hauling_capacity() { return hauling_capacity; }
		void Description()
		{
			cout << "I am a " << _color << " pick up that can haul " << get_hauling_capacity() << " sq. feet at " << _topspeed << "mph!" << endl;
		}
	};
}


int main()
{
	Exam1::Vehicle * Garage[3];

	// STEP 3: Assign ONE RaceCar, ONE Sedan, AND ONE Pickup object to each of the elements 
	// in the Garage array.  Remember the classes are defined in the namespace Exam1.
	Garage[0] = new Exam1::RaceCar("Red");
	Garage[1] = new Exam1::Sedan("Blue", 5);
	Garage[2] = new Exam1::Pickup("Silver", 800);

	for (int i = 0; i < 3; ++i)
	{
		// The method Description() should display an output like 
		// "I am a red sedan (or racecar/pickup) and I can go 95 (or 250 or 85) mph"
		Garage[i]->Description();

	}

}
