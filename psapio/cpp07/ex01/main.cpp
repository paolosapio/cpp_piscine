#include "iter.hpp"
#include <string>





int main(void)
{
	const std::string palabras[] = {"viva", "la", "vida"};
	int numeros[] = {0, 2, -2, 7};
	bool interuptor[] = {false, true};

	iter(palabras, 3, print_array_element<const std::string>);
	iter(numeros, 4, print_array_element<int>);
	iter(interuptor, 2, print_array_element<bool>);

	return (0);
}


