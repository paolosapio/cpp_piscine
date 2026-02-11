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
	std::string _target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	~PresidentialPardonForm();
	PresidentialPardonForm& operator=(PresidentialPardonForm &other);
	void		execute(Bureaucrat const & executor)  const; // esta es la funcion que debe implemmentar el hijo

};
#endif