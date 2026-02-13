#include "AForm.hpp"
#include "Bureaucrat.hpp"

/* ============================================================
   CONSTRUCTORES Y DESTRUCTOR
   ============================================================ */

AForm::AForm() : _name("DefaultForm"), _isSigned(false), _gradeToSign(150), _gradeToExec(150)
{
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExec) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
}

AForm::~AForm()
{
}

/* ============================================================
   OPERADOR DE ASIGNACIÓN
   ============================================================ */

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
		// Los atributos const NO se pueden reasignar
	}
	return *this;
}

/* ============================================================
   GETTERS
   ============================================================ */

const std::string &AForm::getName() const
{
	return this->_name;
}

bool AForm::getIsSigned() const
{
	return this->_isSigned;
}

int AForm::getGradeToSign() const
{
	return this->_gradeToSign;
}

int AForm::getGradeToExec() const
{
	return this->_gradeToExec;
}

/* ============================================================
   MÉTODOS principales
   ============================================================ */

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (this->_isSigned)
		throw AlreadySignedException();

	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();

	this->_isSigned = true;
}

//! execute NO SE DESAROLLA EN AFORM poruqe es VIRTUAL
/* virtual execute(Bureaucrat const &executor)
{
} */

void			AForm::checkExecutable(Bureaucrat const &executor) const
{
	if (this->_isSigned == false)
		throw NotSignedException();
	if (executor.getGrade() > this->_gradeToExec)
		throw GradeTooLowException();
}

/* ============================================================
   EXCEPCIONES
   ============================================================ */
//! const char* (al inicio)_Devuelve un puntero a texto constante
//! throw()_________________La función no lanzará excepciones
//! const (al final)________La función no modifica el objeto

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *AForm::AlreadySignedException::what() const throw()
{
	return "Form is already signed";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "Form is not signed";
}

/* ============================================================
   OPERRADOR <<
   ============================================================ */
   std::ostream &operator<<(std::ostream &out, const AForm &right)
{
    out << "Form: " << right.getName()
        << " | Signed: " << (right.getIsSigned() ? "yes" : "no")
        << " | Grade to sign: " << right.getGradeToSign()
        << " | Grade to execute: " << right.getGradeToExec();
    return out;
}
