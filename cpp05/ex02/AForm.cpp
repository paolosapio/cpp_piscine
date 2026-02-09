#include "AForm.hpp"


AForm::AForm() : _name(""), _isSigned(false), _gradeToSign(1), _gradeToExec(1)
{
}


AForm::AForm(std::string name, const int gradeToSign, const int gradeToExec) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
}


AForm::AForm(AForm &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
}

AForm& AForm::operator=(AForm &other)
{
	// _name = other._name;
	_isSigned = other._isSigned;
	// _gradeToSign = other._gradeToSign;
	// _gradeToExec = other._gradeToExec;
	return (*this);
}


AForm::~AForm()
{
	std::cout << "AForm destruido\n";
}




/* GETTERS */

const std::string& AForm::getName() const
{
	return (this->_name);
}


bool AForm::getIsSigned() const
{
	return (this->_isSigned);
}


int AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}


int AForm::getGradeToExec() const
{
	return (this->_gradeToExec);
}



const char* AForm::YaFirmadoException::what() const throw()
{
	return ("Alguen intento firmar pero no pudo poruqe Ya esta firmado Cono!");
}


const char* AForm::NoFirmadoException::what() const throw()
{
	return ("OJO! el formulario esta sin FIRMA y eso  es malo");
}


const char* AForm::GradeTooLowException::what() const throw()
{
	return ("too low grade");
}


const char* AForm::GradeTooHighException::what() const throw()
{
	return ("too hi grade");
}


std::ostream& operator<<(std::ostream &out, const AForm& right)
{
	out << "NAME: " << right.getName() << "\n"
		<< "SIGNED: " << right.getIsSigned() << "\n"
		<< "GRADE TO SIGN: " << right.getGradeToSign() << "\n"
		<< "GRADE TO EXE: " << right.getGradeToExec() << "\n";

	return (out);
}


void AForm::beSigned(Bureaucrat& bureaucrat)
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




const char* AForm::caca_exetion_test::what() const throw()
{
	return ("hola ayooo");
}


