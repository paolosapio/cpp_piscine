#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
	std::cout << _name << " ha nacido" << std::endl;
}




void HumanA::attack()
{
	std::cout << _name;
	std::cout << " attacks with their ";
	std::cout << _weapon.getType();
	std::cout << std::endl;
}




HumanA::~HumanA()
{
	std::cout << _name << " ha muerto" << std::endl;
}