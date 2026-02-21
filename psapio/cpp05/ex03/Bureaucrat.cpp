#include "Bureaucrat.hpp"
#include "AForm.hpp"

/* ============================================================
   CONSTRUCTORES Y DESTRUCTOR
   ============================================================ */

Bureaucrat::Bureaucrat() : _name("becario"), _grade(150)
 {

 }

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
 {
	if (this->_grade < 1)
		throw GradeTooHighException();
	if (this->_grade > 150)
		throw GradeTooLowException();
 }

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade)
 {
 }

Bureaucrat::~Bureaucrat()
 {
 }

/* ============================================================
   OPERADOR DE ASIGNACIÓN
   ============================================================ */

 Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &other)
 {
	if (&other != this)
		this->_grade = other._grade;
	return (*this);
 }

/* ============================================================
   GETTERS
   ============================================================ */

const std::string&	Bureaucrat::getName() const
 {
	return (this->_name);
 }

int	Bureaucrat::getGrade() const
 {
	return (this->_grade);
 }

/* ============================================================
   MODIFICADORES DE GRADE
   ============================================================ */

void	Bureaucrat::incrementGrade()
 {
	if (this->_grade > 1)
		this->_grade--;
	else
		throw GradeTooHighException();
 }

void	Bureaucrat::decrementGrade()
 {
	if (this->_grade < 150)
		this->_grade++;
	else
		throw GradeTooLowException();
 }

/* ============================================================
   MÉTODO signForm
   ============================================================ */

void Bureaucrat::signForm(AForm &form) const
 {
	try
	{
		form.beSigned(*this);
	//mensaje positivo
		std::cout	<< this->_name
					<< " FIRMADO "
					<< form.getName()
					<< "\n";
	}
	catch (std::exception &e)
	{
	//mensaje negativo
		std::cout	<< this->_name
					<< " NO SE HA PODIDO FIRMAR "
					<< form.getName() << " PORQUE "
					<< e.what() << "\n";
	}
 }

 /* ============================================================
   MÉTODO executeForm
   ============================================================ */

void Bureaucrat::executeForm(const AForm &form) const
 {
	try
	{
		form.execute(*this);
	//mensaje positivo
		std::cout	<< this->_name
					<< " EXECUTADO "
					<< form.getName()
					<< "\n";
	}
	catch (std::exception &e)
	{
		//mensaje negativo
	std::cout	<< this->_name
				<< " NO SE HA PODIDO EXECUTAR "
				<< form.getName() << " PORQUE "
				<< e.what() << "\n";
	}
 }

/* ============================================================
   EXCEPCIONES
   ============================================================ */
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too HIGH");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too LOW");
}

/* ============================================================
   OPERADOR <<
   ============================================================ */

std::ostream &operator<<(std::ostream &out, const Bureaucrat &right)
 {
	out	<< right.getName()
		<< ", Bureaucrat grade "
		<< right.getGrade();
	return (out);
 }
