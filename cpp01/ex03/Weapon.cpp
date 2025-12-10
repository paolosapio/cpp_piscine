#include "Weapon.hpp"

Weapon::Weapon(std::string	type) : _type(type) {} //alternativa mas util de lo de abajo... porque: poruqe asi puedes inizializar variables constantes y utilizarlas en la funcion

const std::string Weapon::getType()
{
	return (this->_type);
}

void	Weapon::setType(std::string	type)
{
	_type = type;
}
// mirar lista de inizializacion
// {
// 	this->_type = type;
// }