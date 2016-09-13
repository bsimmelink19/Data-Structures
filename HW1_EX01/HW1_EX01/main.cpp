#include <iostream> 
using namespace std;

//double the capacity of an array; 
int* doubleCapacity(int* list, int size);

int main()
{
	//#1
	//declares a pointer variable capable of storing the memory address of a double variable
	double* pVar;

	//#2
	//dynamically allocates memory for a double variable
	double* pVar1 = new double;
	//stores the address of the newly allocated double in the previously created pointer
	pVar = pVar1;
	//displays the memory address stored at pVar
	cout << "pVar: " << pVar << endl;

	//#3
	//assigns the double value 4.12 to the memory address stored in the pointer from the previous step (pVar)
	*pVar = 4.12;
	//displays the value in the memory location stored at pVar1
	cout << "*pVar: " << *pVar << endl;

	//#4
	//releases the memory that was allocated using the new operator
	delete pVar1;

	//#6
	//declares an int variable and displays the memory address of the variable 
	int myVar;
	cout << &myVar << endl;


	//#7
	//declares and allocates an array of 10 int using dynamic array allocation
	int* dynamArray;
	dynamArray = new int[10];

	//#8
	//assigns 42 to every element in the array
	for (int i = 0; i < 10; i++)
	{
		*(dynamArray + i) = 42;
	}

	//displays the memory location and value of every element in the array 
	for (int i = 0; i < 10; i++)
	{
		cout << (dynamArray + i) << ": " << *(dynamArray + i) << endl;
	}
	cout << endl;

	//#9
	//releases the memory allocated for the array 
	delete[] dynamArray;



	return 0;
}

//#10
int* doubleCapacity(int* list, int size)
{
	//allocates a pointer with twice the size of the original size
	int* list2 = new int[size * 2];

	return list2;
}