#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class AForm; // forward declaration

class Bureaucrat
{
	private:
	const std::string	_name;
	int					_grade;
	
	public:
// Orthodox Canonical Form
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();
	
// Getters
	const std::string &getName() const;
	int					getGrade() const;
	
// Métodos de modificación
	void	incrementGrade();
	void	decrementGrade();
	
// Métodos relacionados con AForm
	void signForm(AForm &form) const;
	void executeForm(const AForm &form) const;
	
	//! INFO: Querido programador (Paolo) soy tu cociencia, recuerda:
		//! el primer const es referido al valor devuelto;
		//! el conts del final implica que ninguna variable del objeto es monificable!

// Excepciones
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
};

	std::ostream&	operator<<(std::ostream &out, const Bureaucrat &right);

#endif
