#include "Bureaucrat.hpp"
#include <iostream>

void	caca(void) //throw() // este throw es una promesa que no le pasamos exepciones!
{
	throw std::exception();
	std::cout << "caca\n";

}

int main(void)
{
/*  */
	try
	{
		Bureaucrat pepe("pepe", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	return 0;

/*
	try
	{
		caca();
		std::cout << "El código sigue\n";
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
*/


}
