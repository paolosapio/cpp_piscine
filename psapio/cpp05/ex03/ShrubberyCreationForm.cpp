#include "ShrubberyCreationForm.hpp"
#include <fstream>

/* ============================================================
	CONSTRUCTORES Y DESTRUCTOR
	============================================================ */
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
	// Constructor por defecto
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	// Constructor con parámetro
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target)
{
	// Constructor de copia
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// Destructor
}

/* ============================================================
	OPERADOR DE ASIGNACIÓN
	============================================================ */

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other); //Copia la parte de la base ya que el hijo no puede acceder a ella
		this->_target = other._target; //copia la variable que si tenemos disponible directamente en el hijo
	}
	return (*this);
}

/* ============================================================
	MÉTODO execute
	============================================================ */

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	// Comprueba permisos y firma
	this->checkExecutable(executor);

	// Crea archivo <target>_shrubbery
	std::ofstream outfile((_target + "_shrubbery").c_str());
    if (!outfile)
        throw std::runtime_error("No se pudo crear el archivo shrubbery");

    // ASCII art
    outfile <<
"          &&& &&  & &&\n"
"      && &\\/&\\|& ()|/ @, &&\n"
"      &\\/(/&/&||/& /_/)_&/_&\n"
"   &() &\\/&|()|/&\\/ '%\" &()\n"
"  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
"&&   && & &| &| /& & % ()& /&&\n"
" ()&_---()&\\&\\|&&-&&--%---()~\n"
"     &&     \\|||\n"
"             |||\n"
"             |||\n"
"             |||\n"
"       , -=-~  .-^- _\n";

    outfile.close();
}
