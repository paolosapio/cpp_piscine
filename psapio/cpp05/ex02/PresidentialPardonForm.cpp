#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"



PresidentialPardonForm::PresidentialPardonForm() : AForm("form padre", 25, 5), _target("")
{
}


PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	  std::cout << "[PresidentialPardonForm] Constructor called.\n";
}



PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : _target(other._target)
{
}



PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm &other)
{
	if (this != &other)
	_target = other._target;
	return (*this);
}


PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destruido\n";
}


/* Debes comprobar:
- que el formulario está firmado, y
- que el grado del burócrata que intenta ejecutarlo es suficientemente alto.
- Si no se cumplen estas condiciones, lanza la excepción apropiada.

Puedes decidir si las comprobaciones se hacen en cada clase concreta o en la clase
base (y luego llamar a otra función que realice la acción). Sin embargo, una de
las dos opciones es más elegante.
*/




void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{ // tiene que estar ya fimado y tener el buractara suficiente valor para ejecutar

	// this->beExecute(executor);
	//this->beExecute(executor);
	// <bureaucrat> executed <form>
	std::cout << executor.getName() << " executa " << this->_name;
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox.\n";
}