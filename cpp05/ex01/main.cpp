#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void	caca(void) //throw() // este throw es una promesa que no le pasamos exepciones!
{
	throw Form::caca_exetion_test();
	std::cout << "caca\n";
}

int main(void)
{
	Form form("form01", 1, 1); // _name, _gradeToSign, _gradeToExec

	try
	{ //Form(std::string name, const int _gradeToSign, const int _gradeToExec);
		// Bureaucrat pepe("pepe", 1);
		Bureaucrat daniel("danielsan", 2);
		// form.beSigned(pepe);
		form.beSigned(daniel);
		form.getGradeToExec();
		form.getName();
	}
	// catch (Form::GradeTooLowException &e)
	// {
	// 	std::cout << e.what() << "\n";
	// }
	// catch (Form::GradeTooHighException &e)
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
