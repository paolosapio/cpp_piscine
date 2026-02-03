#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

void	caca(void) //throw() // este throw es una promesa que no le pasamos exepciones!
{
	throw AForm::caca_exetion_test();
	std::cout << "caca\n";
}

int main(void)
{
	AForm aForm("aForm01", 1, 1); // _name, _gradeToSign, _gradeToExec

	try
	{ //aForm(std::string name, const int _gradeToSign, const int _gradeToExec);
		// Bureaucrat pepe("pepe", 1);
		Bureaucrat daniel("danielsan", 2);
		// aForm.beSigned(pepe);
		aForm.beSigned(daniel);
		aForm.getGradeToExec();
		aForm.getName();
	}
	// catch (AForm::GradeTooLowException &e)
	// {
	// 	std::cout << e.what() << "\n";
	// }
	// catch (AForm::GradeTooHighException &e)
	// {
	// 	std::cout << e.what() << "\n";
	// }
	catch (std::exception &e)
	{
		std::cout << e.what() << " CACA \n";
	}

	try
	{
		caca();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}

	return (0);
}
