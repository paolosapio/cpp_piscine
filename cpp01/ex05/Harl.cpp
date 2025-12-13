# include "Harl.hpp"

// int striteri(void *(*f)(int));

void Harl::complain(std::string level) //DEBUG : llma la funcion debug
{
	void (Harl::*funk_array[4])(void) = {
		Harl::debug,
		Harl::info,
		Harl::warning,
		Harl::error
	};

	(this->*funk_array[0])();
}










void Harl::debug()
{
	std::cout << "DEBUG"<< std::endl;
}


void Harl::info()
{
	std::cout << "INFO"<< std::endl;
}


void Harl::warning()
{
	std::cout << "WARNING"<< std::endl;
}


void Harl::error()
{
	std::cout << "ERROR"<< std::endl;
}