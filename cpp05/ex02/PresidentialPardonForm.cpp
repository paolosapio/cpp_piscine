#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"



PresidentialPardonForm::PresidentialPardonForm() : AForm("form name padre", 25, 5), _target("")
{
}


PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	  std::cout << "[PresidentialPardonForm] Constructor called." << std::endl;
}



PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other._name, 25, 5), _target(other._target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm &other)
{
	// _name = other._name;
	_isSigned = other._isSigned;
	// _gradeToSign = other._gradeToSign;
	// _gradeToExec = other._gradeToExec;
	return (*this);
}


PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destruido\n";
}












void PresidentialPardonForm::beSigned(Bureaucrat& bureaucrat)
{
	try
	{
		bureaucrat.signAForm(*this);
		this->_isSigned = true;
		std::cout << bureaucrat.getName() << " ha firmado\n";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}

}


void PresidentialPardonForm::beExecute(Bureaucrat& Bureaucrat)
{
	(void)Bureaucrat;
}

