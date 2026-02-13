#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat; // forward declaration por si hace falta

class AForm
{
private:
	const std::string	_name;
	const int			_gradeToSign;
	const int			_gradeToExec;
	bool				_isSigned;

public:
// Orthodox Canonical Form
	AForm(); //! OK
	AForm(const std::string &name, int gradeToSign, int gradeToExec); //! OK
	AForm(const AForm &other); //! OK
	virtual ~AForm(); //! OK
	AForm &operator=(const AForm &other);// Operador de asignacion

// Getters
	const std::string	&getName() const; //! OK
	bool				getIsSigned() const; //! OK
	int					getGradeToSign() const; //! OK
	int					getGradeToExec() const; //! OK

// Métodos principales
	void			beSigned(Bureaucrat const &bureaucrat);
	virtual void	execute(Bureaucrat const &executor) const = 0;
// Metodo opcional pero elegante y esencial para no repetir codigo
	void			checkExecutable(Bureaucrat const &executor) const;

// Excepciones
	//! const char* (al inicio)_Devuelve un puntero a texto constante
	//! throw()_________________La función no lanzará excepciones
	//! const (al final)________La función no modifica el objeto
	
	class GradeTooHighException : public std::exception //! OK
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception //! OK
	{
	public:
		virtual const char *what() const throw();
	};

	class AlreadySignedException : public std::exception //! OK
	{
	public:
		virtual const char *what() const throw();
	};

	class NotSignedException : public std::exception //! OK
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &right);


#endif
