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


int Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}


int Form::getGradeToExec() const
{
	return (this->_gradeToExec);
}



void Form::beSigned(Bureaucrat& bureaucrat)
{
	try
	{
		bureaucrat.signForm(*this);
		this->_isSigned = true;
		std::cout << bureaucrat.getName() << " ha firmado\n";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}

}


const char* Form::YaFirmadoException::what() const throw()
{
	return ("Alguen intento firmar pero no pudo poruqe Ya esta firmado Cono!");
}


const char* Form::GradeTooLowException::what() const throw()
{
	return ("too low grade");
}


const char* Form::GradeTooHighException::what() const throw()
{
	return ("too hi grade");
}


const char* Form::caca_exetion_test::what() const throw()
{
	return ("baya miierda dde mensaje");
}



std::ostream& operator<<(std::ostream &out, const Form& right)
{
	out << "NAME: " << right.getName() << "\n"
		<< "SIGNED: " << right.getIsSigned() << "\n"
		<< "GRADE TO SIGN: " << right.getGradeToSign() << "\n"
		<< "GRADE TO EXE: " << right.getGradeToExec();

	return (out);
}