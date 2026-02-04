/*
NO OLVIDAR: Orthodox Canonical AForm
• Default constructor
• Copy constructor
• Copy assignment operator
• Destructor
*/

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	//nada

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string name, const int _gradeToSign, const int _gradeToExec);
	PresidentialPardonForm(AForm &other);
	~PresidentialPardonForm();
	
	void beSigned(Bureaucrat& Bureaucrat);
	void beExecute(Bureaucrat& Bureaucrat);
};


// std::ostream& operator<<(std::ostream &out, const AForm& right);

#endif