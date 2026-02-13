#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential_Pardon_Form", 25, 5), _target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "Presidential_Pardon_Form\n";
}

//constructor desde other: inizializa el padre con los valores de other para eredar con valore sde other
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
		AForm::operator=(other); // es necesario? que hace? inicialida el operador del padre con el varo  de lo que entra desde other?
		_target = other._target;
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

    // Acción específica del formulario
    std::cout << this->_target
              << " has been pardoned by Zaphod Beeblebrox"
              << std::endl;
}
