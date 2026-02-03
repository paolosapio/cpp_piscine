/*
NO OLVIDAR: Orthodox Canonical AForm
• Default constructor
• Copy constructor
• Copy assignment operator
• Destructor
*/

#ifndef PRESIDENTIALPARDONAForm_HPP
# define PRESIDENTIALPARDONAForm_HPP

#include "AForm.hpp"

class PresidentialPardonAForm : public AForm
{
private:
    

public:
	PresidentialPardonAForm();
	PresidentialPardonAForm(std::string name, const int _gradeToSign, const int _gradeToExec);
	PresidentialPardonAForm(AForm &other);
	~PresidentialPardonAForm();



	// exeption class:
	// el primer const es referido al valor devuelto;
	// el conts del final implica que ninguna variable del objeto es monificable!
	class GradeTooLowException : public std::exception // ereda de std::exeption
	{
		private:
		//nada
		
		public:
		const char* what() const throw(); //throw es una promesa que esta funcion no va a lanzar una expecion
	};



	class GradeTooHighException : public std::exception // ereda de std::exeption
	{
		private:
		//nada
		
		public:
		const char* what() const throw(); //throw es una promesa que esta funcion no va a lanzar una expecion
	};


	class YaFirmadoException : public std::exception // ereda de std::exeption
	{
		private:
		//nada
		
		public:
		const char* what() const throw(); //throw es una promesa que esta funcion no va a lanzar una expecion
	};

	

	AForm& operator=(AForm &other);

	const std::string&	getName() const;
	bool 				getIsSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExec() const;
	
	void beSigned(Bureaucrat& Bureaucrat);
};


std::ostream& operator<<(std::ostream &out, const AForm& right);

#endif