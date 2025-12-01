#include <iostream>
#include "Phonebook.hpp"

int main()
{
	std::string buffer;
	PhoneBook phonebook;

	while (1)
	{
		std::cout << "Introduce ADD | SEARCH | EXIT\n";
		std::getline(std::cin, buffer);
		if (!std::cin)
		{
			std::cerr << "ERROR\n";
			std::exit(1);
		}
		if (buffer.empty())
		{
			continue ;
		}
		if (buffer == "ADD" || buffer == "a")
		{
			phonebook.add_contact();
		}
		if (buffer == "SEARCH" || buffer == "s")
		{
			phonebook.search_contact();
		}
		if (buffer == "EXIT" || buffer == "e")
		{
			return (0);
		}
	}

	Contact contacto;

	contacto.create();

	contacto.print();
	return (0);
}