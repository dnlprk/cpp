#include <stdlib.h>
#include <iostream>
#include <memory>

class emptyClass
{
public:
	emptyClass();
	~emptyClass();

private:
	int* values;
};

emptyClass::emptyClass()
{
	values = new int[5];
}

emptyClass::~emptyClass()
{
	if (values != nullptr)
	{
		delete[] values;
	}
}

void func2(char* pointer)
{
	pointer = new char[7];
}

void func1(char* pointer)
{
	func2(pointer);
}

int main()
{
	//primitive data types
	//c++ allocation
	int* intArray = new int[20];
	char* charArray = new char[15];
	double* doubleArray = new double[10];

	//c allocation
	int* cIntArray = (int*)malloc(sizeof(int));


	//std::cout << intArray[-1000000]; //buffer underflow
	//std::cout MM intArray[30]; //buffer overflow
	//std::cout << intArray[5]; //uninitialized memory read
	delete intArray;

	emptyClass test[5];
	//test[3].~emptyClass(); //system error before inspector error

	//c++ deallocation
	delete[] intArray;
	delete[] charArray;
	delete[] doubleArray;

	//c deallocation
	free(cIntArray);


	//func1(charArray);
}