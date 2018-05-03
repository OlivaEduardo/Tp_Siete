#ifndef STATIC_ARRAY
#define STATIC_ARRAY

#include <iostream>

typedef unsigned int index;

template<typename T>
class StaticArray
{
private:
	const index size;
	index elements;
	T* arr;
public:
	//Constructor function
	StaticArray(index arraySize)
		: size(arraySize)
	{
		arr = new T[size]();
		elements = 0;
	}

	//Copy constructor
	StaticArray(T& array)
		: size(array.size), 
		elements(array.elements)
	{
		arr = new T[size];
		for (index i = 0; i <= size; ++i)
		{
			if (i < elements)
				arr[i] = array[i];
		}
	}

	//Destructor function
	~StaticArray()
	{
		delete arr;
	}

	//Insertion function
	void insert(const T& value)
	{
		if (elements < size)
		{
			arr[elements] = value;
			++elements;
			std::cout << "Insercion correcta." << std::endl;
		}
		else
		{
			std::cout << "Insercion fallida. Array completo." << std::endl;
		}
	}

	//Deletion function
	void deleteLast()
	{
		if (elements > 0 && elements <= size)
		{
			delete arr[elements - 1];
			--elements;
		}
		else
		{
			std::cout << "Borrado fallido. Array vacio." << std::endl;
		}
	}

	//Get an element at designated index
	bool getElement(index pos, T& valueStorage)
	{
		if (pos < elements)
		{
			valueStorage = arr[pos];
			return true;
		}
		else
		{
			std::cout << "Elemento invalido." << std::endl;
			return false;
		}
	}

	//Reverse elements order in the array
	void reverse()
	{
		if (elements > 0 && elements <= size)
		{
			for (index i = 0; i < elements - i; ++i)
			{
				T aux = arr[i];
				arr[i] = arr[elements - 1 - i];
				arr[elements -1 - i] = aux;
			}
		}
	}

	//Print array content
	void print()
	{
		if (elements > 0 && elements <= size)
		{
			for (index i = 0; i < elements; ++i)
				std::cout << arr[i] << std::endl;
		}
		else
		{
			std::cout << "Array vacio o invalido" << std::endl;
		}
	}

	//Elements count. Returns 0 if the array is empty.
	index totalSize()
	{
		return elements;
	}

	//Space available to be fill
	index availableSize()
	{
		return size - elements;
	}

	//Swap two elements in the array
	void swap(const index firstIndex, const index secondIndex)
	{

		if (elements > 0 && elements <= size)
		{
			if ((firstIndex >= 0 && firstIndex <= elements) && (secondIndex >= 0 && secondIndex <= elements))
			{
				T aux = arr[firstIndex];
				arr[firstIndex] = arr[secondIndex];
				arr[secondIndex] = aux;
			}
		}
	}
};

#endif // !STATIC_ARRAY