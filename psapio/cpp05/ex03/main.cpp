#include <iostream>

#include "AForm.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

/* 	en este main hacemos que cree un Intern
	Le pida varios formularios (uno correcto y uno incorrecto)
	Cree un Bureaucrat con suficiente rango
	Firme y ejecute los formularios
	Muestre todo el flujo del módulo 05 */

int main()
{
    try
    {
        Intern someRandomIntern;
        Bureaucrat boss("Paolo", 1);

        std::cout << "\n--- Creando formularios con el Intern ---\n";

        AForm *f1 = someRandomIntern.makeForm("shrubbery creation", "Home");
        AForm *f2 = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm *f3 = someRandomIntern.makeForm("presidential pardon", "Marvin");
        AForm *f4 = someRandomIntern.makeForm("formulario inventado", "Nobody"); // debe fallar

        std::cout << "\n--- Firmando y ejecutando formularios ---\n";

        if (f1)
        {
            boss.signForm(*f1);
            boss.executeForm(*f1);
        }

        if (f2)
        {
            boss.signForm(*f2);
            boss.executeForm(*f2);
        }

        if (f3)
        {
            boss.signForm(*f3);
            boss.executeForm(*f3);
        }

        // Liberar memoria
        delete f1;
        delete f2;
        delete f3;
        delete f4;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
