# include "Harl.hpp"

// int striteri(void *(*f)(int));

void Harl::complain(std::string level) //DEBUG : llma la funcion debug
{

/* 	void (Harl::*funk_array[4])(void) =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
 */

	std::string string_array[4] = 
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	int cases = 0;
	while (cases < 4)
	{
		if (string_array[cases] == level)
		{
			break ;
		}
		cases++;
	}

	switch (cases)
	{
		case 0:
			this->debug();

		case 1:
			this->info();

		case 2:
			this->warning();

		case 3:
			this->error();
			break ;
		default:
			std::cerr << "PON: <DEBUG> <INFO> <WARNING> <ERROR> para probar!\n";
	}
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
