#include "Weapon.hpp"

// mirar lista de inizializacion
Weapon::Weapon(std::string	type) : _type(type)
{ 
	//alternativa mas util de lo de abajo...
	// 	this->_type = type;
	//porque: poruqe asi puedes inizializar
	//variables constantes y utilizarlas en la funcion
	std::cout << _type << " construida" << std::endl;

}






const std::string& Weapon::getType()
{
	return (this->_type);
}






void	Weapon::setType(std::string	type)
{
	_type = type;
}


Weapon::~Weapon()
{
	std::cout << _type << " tirada al rio" << std::endl;


}