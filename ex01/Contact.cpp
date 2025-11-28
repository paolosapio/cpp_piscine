#include "Contact.hpp"

void Contact::set_first_name()
{
	std::string buffer;

etiqueta:
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
		goto etiqueta;
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

	std::cout << "LAST NAME: ";
	std::getline(std::cin, buffer);
	if (!std::cin)
	{
		std::cerr << "ERRROR\n";
		std::exit(1);
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

	std::cout << "NICKNAME: ";
	std::getline(std::cin, buffer);
	if (!std::cin)
	{
		std::cerr << "ERRROR\n";
		std::exit(1);
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

	std::cout << "PHONE NUMBER: ";
	std::getline(std::cin, buffer);
	if (!std::cin)
	{
		std::cerr << "ERRROR\n";
		std::exit(1);
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

	std::cout << "SECRET: ";
	std::getline(std::cin, buffer);
	if (!std::cin)
	{
		std::cerr << "ERRROR\n";
		std::exit(1);
	}
	this->_darkest_secret = buffer;
}

std::string Contact::get_darkest_secret()
{
	return (this->_darkest_secret);
}


void Contact::print()
{
	std::cout << std::endl;

	std::cout << "first name:   " << this->_first_name << std::endl;
	std::cout << "last name:    " << this->_last_name << std::endl;
	std::cout << "nicknake:     " << this->_nickname << std::endl;
	std::cout << "phone number: " << this->_phone_number << std::endl;
	std::cout << "secret:       " << this->_darkest_secret << std::endl;
}