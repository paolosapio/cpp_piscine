/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:25:06 by psapio            #+#    #+#             */
/*   Updated: 2025/12/09 10:53:59 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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







void ten_chars_print(std::string content)
{
	int i = 0;

	if (content.length() < 10)
	{
		while(i < 10 - (int)content.length())
		{
			std::cout << " ";
			i++;
		}
		std::cout << content;
	}
	else
	{
		std::cout << content.substr(0, 9) << ".";
	}
}







void PhoneBook::print_row(int page)
{
	// if (!_first_name.empty())
	if (!contacts[page].get_first_name().empty())
	{
		std::cout << "      " << page << "|";
		ten_chars_print(contacts[page].get_first_name());
		std::cout << "|";
		ten_chars_print(contacts[page].get_last_name());
		std::cout << "|";
		ten_chars_print(contacts[page].get_nickname());
		std::cout << "|" << std::endl;
	}
}







void PhoneBook::print_table()
{
	int i = 0;

	while (i < SIZE_BOOK)
	{
		print_row(i);
		i++;
	}
}











void PhoneBook::ask_contact_detail()
{
	std::string buffer;
	int number_value;

 reset:
	std::cout << "Choose a contact detail [Nº]\n";
	std::getline(std::cin, buffer);
	if (!std::cin)
	{
		std::cerr << "ERROR\n";
		std::exit(1);
	}

	if (!std::isdigit(buffer.c_str()[0]))
	{
		std::cout << "ONLY INDEX NUMBER" << std::endl;
		goto reset;
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