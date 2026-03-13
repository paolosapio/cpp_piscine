#include "iter.hpp"

int main(void)
{
	std::string palabras[] = {"viva", "la", "vida"};
	int numeros[] = {0, 2, -2, 7};
	bool interuptor[] = {false, true};

	iter(palabras, 3, print_array_element);
	iter(numeros, 4, print_array_element);
	iter(interuptor, 2, print_array_element);
	return (0);
}