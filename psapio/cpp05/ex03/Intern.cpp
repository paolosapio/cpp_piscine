#include <iostream>
#include "Intern.hpp"

/* ============================================================
   CONSTRUCTORES Y DESTRUCTOR
   ============================================================ */

Intern::Intern()
 {
 }

Intern::Intern(const Intern &other)
 {
    (void)other;
 }

Intern &Intern::operator=(const Intern &other)
 {
    (void)other;
    return (*this);
 }

Intern::~Intern()
 {
 }

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm *forms[3] = {
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)
    };

    for (int i = 0; i < 3; i++)
    {
        if (formName == names[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i];
        }
        delete forms[i]; // si no coincide, lo borramos
    }

    std::cout << "Intern: form \"" << formName << "\" does not exist" << std::endl;
    return NULL;
}
