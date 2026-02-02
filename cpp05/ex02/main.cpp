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
	Form form("form01", 2, 2); // _name, _gradeToSign, _gradeToExec

	try
	{ //Form(std::string name, const int _gradeToSign, const int _gradeToExec);
		Bureaucrat pepe("pepe", 1);
		Bureaucrat gabo("gabo", 2);
		pepe.signForm(form);
		gabo.signForm(form);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << "Hemos capturado un TooLow" << "\n";
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << "Hemos capturado un TooHigh" << "\n";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << " CACA \n";
	}
	return (0);
}
