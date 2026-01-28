#include "Form.hpp"


Form::Form() : _name(""), _isSigned(false), _gradeToSign(1), _gradeToExec(1)
{
}


Form::Form(std::string name, const int gradeToSign, const int gradeToExec) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
}


Form::Form(Form &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
}


Form& Form::operator=(Form &other)
{
	// _name = other._name;
	_isSigned = other._isSigned;
	// _gradeToSign = other._gradeToSign;
	// _gradeToExec = other._gradeToExec;
	return (*this);
}


Form::~Form()
{
	std::cout << "Form destruido\n";
}




/* GETTERS */

const std::string& Form::getName() const
{
	return (this->_name);
}


bool Form::getIsSigned() const
{
	return (this->_isSigned);
}


const int Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}


const int Form::GetGradeToExec() const
{
	return (this->_gradeToExec);
}



/* It changes the form’s status to signed if the bureaucrat’s grade is high enough
(greater than or equal to the required one). Remember, grade 1 is higher than grade 2.
If the grade is too low, throw a Form::GradeTooLowException. */

void Form::beSigned(Bureaucrat& bureaucrat)
{
	if (this->_gradeToSign <= bureaucrat.getGrade())
	{
		this->_isSigned = true;
	}
	else
	{
		throw GradeTooLowException(); //no tenemos grade suficiente para firmar
	}
}


const char* Form::GradeTooLowException::what() const throw()
{
	return ("too low grade");
}


const char* Form::GradeTooHighException::what() const throw()
{
	return ("too hi grade");
}
