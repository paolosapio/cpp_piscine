#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string> // incluido aquí para evitar dependencias ocultas, aunque AForm también lo incluya
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;

public:
	ShrubberyCreationForm(); // constructor por defecto
	ShrubberyCreationForm(const std::string &target); // Constructor con parámetro
	ShrubberyCreationForm(const ShrubberyCreationForm &other); // constructor de copia
	~ShrubberyCreationForm(); // destructor

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other); // operador de asignación
	
	// esta es la funcion qeu debe implementar el hijo
	void execute(const Bureaucrat &executor) const;
};


#endif