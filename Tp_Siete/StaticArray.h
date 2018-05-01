#ifndef STATIC_ARRAY
#define STATIC_ARRAY

#include <iostream>

typedef unsigned int index;

template<typename T>
class StaticArray
{
private:
	const index size;
	T* arr;
public:
	//Constructor function
	StaticArray(index arraySize)
		: size(arraySize)
	{
		arr = new T[size]();
	}

	//Copy constructor
	StaticArray(T& array)
		: size(array.size)
	{
		arr = new T[size];
		for (index i = 0; i <= size; ++i)
		{
			if (&array[i] != nullptr)
				arr[i] = array[i];
		}
	}

	//Destructor function
	~StaticArray()
	{
		delete arr;
	}

	//Insertion function
	void insert(const T element)
	{
		//Find the last element
		index lastEleIndex = this->totalSize();

		//Insertion
		if (arr == nullptr)
		{
			arr[0] = element;
			std::cout << "Primera insercion" << std::endl;
		}
		else if (lastEleIndex + 1 <= size)
		{
			arr[lastEleIndex + 1] = element;
			std::cout << "Insercion correcta. Indice: " << lastEleIndex + 1 << std::endl;
		}
		else
		{
			std::cout << "Insercion no realizada. Array completo." << std::endl;
		}
	}

	//Deletion function
	void deleteLast()
	{
		//Find the last element
		index lastEleIndex = this->totalSize();

		//Deletion
		if (lastEleIndex >= 0 && lastEleIndex <= size)
		{
			arr[lastEleIndex] = (T)nullptr;
			std::cout << "Borrado correcto." << std::endl;
		}
		else
		{
			std::cout << "Operacion no realizada. Array vacio" << std::endl;
		}
	}

	//Get an element at designated index
	T getElement(index pos)
	{
		if (arr[pos] != (T)nullptr)
		{
			return arr[pos];
		}
		else
		{
			std::cout << "Elemento invalido." << std::endl;
			return (T)nullptr;
		}
	}

	//Reverse elements order in the array
	void reverse()
	{
		index elements = this->totalSize();

		if (elements > 0)
		{
			for (index i = 0; i < elements - i; ++i)
			{
				T aux = arr[i];
				arr[i] = arr[elements - i];
				arr[elements - i] = aux;
			}
		}
	}

	//Print array content
	void print()
	{
		index elements = this->totalSize();

		for (index i = 0; i <= elements; ++i)
			std::cout << arr[i] << std::endl;
	}

	//Elements count. Returns 0 if the array is empty.
	index totalSize()
	{
		if (arr == nullptr)
			return 0;
		else
		{
			for (index i = 0; i <= size; ++i)
			{
				if (arr[i] == (T)nullptr)
					return i -1 ;
			}
		}
		return size;
	}

	//Space available to be fill
	index availableSize()
	{
		index elements = this->totalSize();
		
		if (elements <= 0)
			return 0;
		else
			return size - elements;
	}

	//Swap two elements in the array
	void swap(const index firstIndex, const index secondIndex)
	{
		index elements = this->totalSize();

		if ((firstIndex >= 0 && firstIndex <= elements) && (secondIndex >= 0 && secondIndex <= elements))
		{
			T aux = arr[firstIndex];
			arr[firstIndex] = arr[secondIndex];
			arr[secondIndex] = aux;
		}
	}




	void printSize()
	{
		index x = this->totalSize();
		std::cout << x << std::endl;
	}
};

#endif // !STATIC_ARRAY