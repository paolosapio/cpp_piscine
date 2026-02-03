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
	//nada

public:
	PresidentialPardonAForm();
	PresidentialPardonAForm(std::string name, const int _gradeToSign, const int _gradeToExec);
	PresidentialPardonAForm(AForm &other);
	~PresidentialPardonAForm();
	
	void beSigned(Bureaucrat& Bureaucrat); //
	void beExecute(Bureaucrat& Bureaucrat); //
};


std::ostream& operator<<(std::ostream &out, const AForm& right);

#endif