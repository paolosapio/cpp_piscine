#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string> // incluido aquí para evitar dependencias ocultas, aunque AForm también lo incluya
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	~PresidentialPardonForm();
	
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
	
	// esta es la funcion que debe implemmentar el hijo
	void execute(const Bureaucrat &executor) const;
};

#endif
