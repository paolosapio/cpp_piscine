#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

/* ============================================================
	CONSTRUCTORES Y DESTRUCTOR
	============================================================ */

RobotomyRequestForm::RobotomyRequestForm() :
AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	// contructor por defecto
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	// contructor con parametro
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// destructor
}

/* ============================================================
	OPERADOR DE ASIGNACION
   ============================================================ */
	
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
AForm(other), _target(other._target)
{
	//constructor de copia
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other) 
	{
		AForm::operator=(other); // copia la parte base
		_target = other._target; // copia la parte propia
	}
	return *this;
}

 /* ============================================================ 
	MÉTODO execute 
	============================================================ */

 void RobotomyRequestForm::execute(const Bureaucrat &executor) const
 {
	this->checkExecutable(executor);
	std::cout << "Ruido taladro: Brrrrrrriiiiiiiiiizzzzz...\n" ;
	std::srand(std::time(NULL));
	if (std::rand() % 2 == 0)
	{
		std::cout	<< _target 
					<< " has been robotomized successfully!" 
					<< std::endl;
	}
	else
		std::cout << "Robotomy failed on " << _target << std::endl;
 }