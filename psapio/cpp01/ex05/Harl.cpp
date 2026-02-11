# include "Harl.hpp"

// int striteri(void *(*f)(int));

void Harl::complain(std::string level) //DEBUG : llma la funcion debug
{
	void (Harl::*funk_array[4])(void) =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};



	std::string string_array[4] = 
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	//	asi se llama la funcion del array:
	//		(this->*funk_array[0])()
	int cases = 0;
	while (cases < 4)
	{
		if (string_array[cases] == level)
		{
			(this->*funk_array[cases])();
			break ;
		}
		cases++;
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
