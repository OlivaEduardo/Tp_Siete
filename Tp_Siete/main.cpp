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

	std::cout << "Cantidad de elementos: " << myArray.totalSize() << std::endl;

	int value;
	if (myArray.getElement(4, value))
	{
		std::cout << "Elemento en posicion 4: " << value << std::endl;
	}
	
	int newValue;
	if (myArray.getElement(21, newValue))
	{
		std::cout << "Elemento en posicion 21: " << newValue << std::endl;
	}

	int flag;
	std::cin >> flag;
}