#include "iter.hpp"

template <typename T>
void print_array_element(T &array)
{
	std::cout << array << "\n";
}



template <typename T, typename F>
void iter(T *array, int length, F func)
{
    for (int i = 0; i < length; i++)
    {
        func(array[i]);
    }
}



int main(void)
{
	std::string palabras[] = {"viva", "la", "vida"};
	int numeros[] = {0, 2, -2, 7};
	bool interuptor[] = {false, true};

	iter('a', 1, toupper);
	// iter(numeros, 4, toupper);
	// iter(interuptor, 2, toupper);
	
	return (0);
}