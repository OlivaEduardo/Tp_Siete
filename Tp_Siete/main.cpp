#include <iostream>
#include "StaticArray.h"

int main() {

	const index size = 20;
	StaticArray<int> myArray(size);
	
	for (index i = 0; i < size; ++i)
	{
		myArray.insert(i);
	}

	myArray.reverse();

	myArray.swap(3, 8);

	myArray.print();

	myArray.printSize();

	int flag;
	std::cin >> flag;
}