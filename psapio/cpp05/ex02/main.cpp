#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>

int main(void)
{
	std::cout << "============" << std::endl;
	try
	{
		Bureaucrat BurA("other", 2);
		PresidentialPardonForm FormA("Juan");
		std::cout << FormA << std::endl;
		FormA.beSigned(BurA);
		std::cout << FormA << std::endl;
		// BurA.signAForm(FormA);
		FormA.execute(BurA);
		
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "============" << std::endl;

	return (0);
}
