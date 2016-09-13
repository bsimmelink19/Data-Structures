#include <iostream>
#include <string>
#include <vector>
using namespace std;

//#18
//class capable of holding a generic type T
template<typename T>
class MyVec {
private:
	T *array;  // dynamically allocated array

public:
	MyVec(int size) { // constructor creates array of size “size”
		array = new T[size];
	}

	~MyVec() {  // destructor returns memory back to system
		delete[] array;
	}
};


//#17
//swap function capable of handling any 
template<typename T>
void Swap(T & A, T & B)
{
	T tmp = A;
	A = B;
	B = tmp;
}

int main()
{
	//demonstrates the swap function works with integers
	int A = 4, B = 5;
	cout << "A: " << A << endl;
	cout << "B: " << B << endl;
	Swap(A, B);
	cout << "A: " << A << endl;
	cout << "B: " << B << endl;
	cout << endl;

	//demonstrates the swap function works with doubles
	double C = 3.14, D = 2.9;
	cout << "C: " << C << endl;
	cout << "D: " << D << endl;
	Swap(C, D);
	cout << "C: " << C << endl;
	cout << "D: " << D << endl;
	cout << endl;

	//demonstrates the swap function works with Chars
	char E = 'e', F = 'f';
	cout << "E: " << E << endl;
	cout << "F: " << F << endl;
	Swap(E, F);
	cout << "E: " << E << endl;
	cout << "F: " << F << endl;
	cout << endl;

	//demonstrates the swap function works with strings
	string G = "first", H = "second";
	cout << "G: " << G << endl;
	cout << "H: " << H << endl;
	Swap(G, H);
	cout << "G: " << G << endl;
	cout << "H: " << H << endl;
	cout << endl;

	//#19
	//declares a myVec variable capable of holding double variables
	MyVec<double> doubVec(10);

	//#20
	//vector capable of hold char variables 
	vector<char> charVector;

	//#21
	//assigns 24 to every element of the vector
	for (int i = 0; i < 10; i++)
	{
		charVector.push_back('w');
	}

	//#22
	//returns the size of the vector 
	cout << "Size of vector: " << charVector.size() << endl;


}
