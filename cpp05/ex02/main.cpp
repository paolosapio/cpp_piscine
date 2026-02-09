#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>

int main(void)
{
	Bureaucrat funcionario1("PEPE", 2);
	PresidentialPardonForm formPresident;
	

	formPresident.beSigned(funcionario1);



	try
	{
		funcionario1.signAForm(formPresident);
	}

	catch (std::exception &e)
	{
		std::cout << e.what() << "⭐\n";
	}
	
	std::cout << funcionario1.getName();
	return (0);
}
