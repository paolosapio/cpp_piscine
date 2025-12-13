#include "HumanB.hpp"

// HumanB::HumanB();

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
	std::cout << _name << " ha nacido" << std::endl;

}
HumanB::~HumanB()
{
	std::cout << _name << " ha muerto" << std::endl;
}


void HumanB::attack()
{
	if (_weapon == NULL)
	{
		std::cout << _name << " No tiene arma y no puede atacar" << std::endl;
		return ;
	}
	std::cout << _name;
	std::cout << " attacks with their ";
	std::cout << _weapon->getType();
	std::cout << std::endl;
}



void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

