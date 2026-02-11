/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psapio <psapio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:53:05 by psapio            #+#    #+#             */
/*   Updated: 2025/12/09 10:53:44 by psapio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::set_first_name()
{
	std::string buffer;
init:
	std::cout << "FIRST NAME: ";
	std::getline(std::cin, buffer);
	if (!std::cin)
	{
		std::cerr << "ERRROR\n";
		std::exit(1);
	}
	if (buffer.empty())
	{
		std::cerr << "Name cant be empty!\n";
		goto init;
	}
	// return (set_first_name());
	this->_first_name = buffer;
}











std::string Contact::get_first_name()
{
	return (this->_first_name);
}











void Contact::set_last_name()
{
	std::string buffer;

init:
	std::cout << "LAST NAME: ";
	std::getline(std::cin, buffer);
	if (!std::cin)
	{
		std::cerr << "ERRROR\n";
		std::exit(1);
	}
	if (buffer.empty())
	{
		std::cerr << "Last name cant be empty!\n";
		goto init;
	}
	this->_last_name = buffer;
}











std::string Contact::get_last_name()
{
	return (this->_last_name);
}











void Contact::set_nickname()
{
	std::string buffer;

init:

	std::cout << "NICKNAME: ";
	std::getline(std::cin, buffer);
	if (!std::cin)
	{
		std::cerr << "ERRROR\n";
		std::exit(1);
	}
	if (buffer.empty())
	{
		std::cerr << "Nickname cant be empty!\n";
		goto init;
	}
	this->_nickname = buffer;
}











std::string Contact::get_nickname()
{
	return (this->_nickname);
}











void Contact::set_phone_number()
{
	std::string buffer;

init:
	std::cout << "PHONE NUMBER: ";
	std::getline(std::cin, buffer);
	if (!std::cin)
	{
		std::cerr << "ERRROR\n";
		std::exit(1);
	}
//si algun caracter o eespacioss no es numero
	int i = 0;
	while (buffer[i])
	{
		if (isdigit(buffer[i]) == false)
		{
			std::cerr << "Only number!\n";
			goto init;
		}
		i++;
	}
	if (buffer.empty())
	{
		std::cerr << "Phone number cant be empty!\n";
		goto init;
	}
	this->_phone_number = buffer;
}











std::string Contact::get_phone_number()
{
	return (this->_phone_number);
}











void Contact::set_darkest_secret()
{
	std::string buffer;

init:
	std::cout << "SECRET: ";
	std::getline(std::cin, buffer);
	if (!std::cin)
	{
		std::cerr << "ERRROR\n";
		std::exit(1);
	}
	if (buffer.empty())
	{
		std::cerr << "Secret cant be empty!\n";
		goto init;
	}
	this->_darkest_secret = buffer;
}











std::string Contact::get_darkest_secret()
{
	return (this->_darkest_secret);
}


void Contact::print()
{
	if (_first_name.empty())
	{
		std::cout << "Empty contact\n";
		return ;
	}
	std::cout << std::endl;

	std::cout << "first name:   " << this->_first_name << std::endl;
	std::cout << "last name:    " << this->_last_name << std::endl;
	std::cout << "nicknake:     " << this->_nickname << std::endl;
	std::cout << "phone number: " << this->_phone_number << std::endl;
	std::cout << "secret:       " << this->_darkest_secret << std::endl;
	std::cout << std::endl;
}

void Contact::create()
{
	set_first_name();
	set_last_name();
	set_nickname();
	set_phone_number();
	set_darkest_secret();
}
