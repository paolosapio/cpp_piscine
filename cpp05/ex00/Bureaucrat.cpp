#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("mr.X"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
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

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destruido el " << _name <<" Bureaucrat\n";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("too low grade");
}