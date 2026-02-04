#include "PresidentialPardonForm.hpp"



PresidentialPardonForm::PresidentialPardonForm() : _name(""), _isSigned(false), _gradeToSign(1), _gradeToExec(1)
{
}


PresidentialPardonForm::PresidentialPardonForm(std::string name, const int gradeToSign, const int gradeToExec) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
}


PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
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

