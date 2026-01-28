#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("mr.X"), _grade(150)
{
}


Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade  < 1)
		throw GradeTooHighException();
	std::cout << "Se ha creado " << this->_name << " con grado: " << _grade << "\n";
}


Bureaucrat::Bureaucrat(Bureaucrat &other) : _name(other._name)
{
	*this = other;
}


Bureaucrat& Bureaucrat::operator=(Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;
	return (*this);
}


std::ostream& operator<<(std::ostream& out, Bureaucrat& other)
{
	out << other.getName() << ", bureaucrat grade " << other.getGrade() << ".";
	return (out);
}


Bureaucrat::~Bureaucrat()
{
	std::cout << "Destruido el " << _name <<" Bureaucrat\n";
}


const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("too low grade");
}


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("too hi grade");
}


const std::string& Bureaucrat::getName() const
{
	return (this->_name);
}


int& Bureaucrat::getGrade()
{
	return (this->_grade);
}


void Bureaucrat::increment()
{
	if (this->_grade <= 1)
		throw GradeTooHighException();
	this->_grade--;
}


void Bureaucrat::decrement()
{
	if (this->_grade >= 150)
		throw GradeTooLowException();
	this->_grade++;
}
