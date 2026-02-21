#include <iostream>

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

/* 	Crea un Bureaucrat con rango suficiente
    Crea los tres formularios
    Los firma
    Los ejecuta
    Muestra los mensajes correctos
    Prueba las excepciones si quieres verlas */

int main()
{
    try
    {
        Bureaucrat boss("Paolo", 1);
        std::cout << "\n--- Creando formularios ---\n";
        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robo("Bender");
        PresidentialPardonForm pardon("Marvin");
        std::cout << "\n--- Firmando formularios ---\n";
        boss.signForm(shrub);
        boss.signForm(robo);
        boss.signForm(pardon);
        std::cout << "\n--- Ejecutando formularios ---\n";
        boss.executeForm(shrub); boss.executeForm(robo); 
        boss.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
} 
