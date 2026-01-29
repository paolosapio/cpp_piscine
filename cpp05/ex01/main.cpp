#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void	caca(void) //throw() // este throw es una promesa que no le pasamos exepciones!
{
	throw std::exception();
	std::cout << "caca\n";

}

int main(void)
{

	Form form("form01", 200, 200);

	try
	{
		Bureaucrat pepe("pepe", 3);
		form.beSigned(pepe);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	
	return 0;


}
