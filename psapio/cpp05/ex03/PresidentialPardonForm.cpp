#include "PresidentialPardonForm.hpp"

/* ============================================================
	CONSTRUCTORES Y DESTRUCTOR
	============================================================ */

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	// std::cout << "PresidentialPardonForm\n";
}

// Constructor de copia: inicializa la parte base (AForm) y copia el target
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other._target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

/* ============================================================
	OPERADOR DE ASIGNACIÓN
	============================================================ */

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other); // copia la parte base (AForm), ya que el hijo no puede acceder a sus atributos
		_target = other._target; // copia la parte específica del hijo
	}
	return (*this);
}

/* ============================================================
	MÉTODO execute
	============================================================ */

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	// Comprueba si está firmado y si el executor tiene rango suficiente
	this->checkExecutable(executor);

	// Acción de execucion específica del formulario
	std::cout << this->_target
					<< " has been pardoned by Zaphod Beeblebrox"
					<< std::endl;
}
