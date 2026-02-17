#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

/* ============================================================
	CONSTRUCTORES Y DESTRUCTOR
	============================================================ */

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
    // contructor por defecto
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    // contructor con parametro
}

/* ============================================================
	OPERADOR DE ASIGNACION
	============================================================ */
    
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
AForm(other), _target(other._target)
  {
    //constructor de copia
}

RobotomyRequestForm::~RobotomyRequestForm()
{}


RobotomyRequestForm::RobotomyRequestForm &operator=(const RobotomyRequestForm &other)
{

}


// esta es la funcion que debe implementar el hijo

void RobotomyRequestForm::execute(const Bureaucrat &executor) const;