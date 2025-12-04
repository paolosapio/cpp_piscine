#include "Phonebook.hpp"
#include "Contact.hpp"
#include <cstdlib>

PhoneBook::PhoneBook() //contructor esto inicializa la classe
{
	page = 0;
}

void PhoneBook::add_contact()
{
	contacts[page].create();
	// contacts[page].print();
	page++;
	if (page == SIZE_BOOK)
		page = 0;
}

void PhoneBook::print_table()
{
	int i = 0;

	while (i < SIZE_BOOK)
	{
		contacts[i].print_row(i);
		i++;
	}
}

void PhoneBook::ask_contact_detail()
{
	std::string buffer;
	int number_value;
// reset:
	std::cout << "Choose a contact detail [Nº]\n";
	std::getline(std::cin, buffer);
	if (!std::cin)
	{
		std::cerr << "ERROR\n";
		std::exit(1);
	}
	number_value = std::atoi(buffer.c_str());
	if (number_value < SIZE_BOOK && number_value >= 0)
	{
		contacts[number_value].print();
	}
}

void PhoneBook::search_contact()
{
	print_table();
	ask_contact_detail();
}