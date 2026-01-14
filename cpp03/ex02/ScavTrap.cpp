#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("c3po", 100, 50, 20)
{
	std::cout << "SCAV TRAP: CONSTRUCTOR " << _name << "\n";
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap recibe en nombre: " << _name << "\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap() //aqui : ClapTrap() es inecesario pero vamos a tenerlo explicto
{
	*this = other;
}

ScavTrap::~ScavTrap()
{
	std::cout << "SCAV TRAP: DESTRUCTOR " << _name << "\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	_name = other._name;
	_hit_points = other._hit_points;
	_energy_points = other._energy_points;
	_attack_damage = other._attack_damage;
	std::cout << "SCAV TRAP: OPERADOR COPIA UTILIZADO POR: " << _name << "\n";
	return (*this);
}

void ScavTrap::guardGate()
{
	std::cout << "SCAV TRAP: ESCUDO ACTIVADO!🛡️ " << _name << "\n";
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_hit_points <= 0)
		std::cout << "el Scav esta muertisimo\n";
	else if (this->_energy_points <= 0)
		std::cout << "el Scav esta sin energia\n";
	else
	{
		_energy_points--;
		std::cout << "el Scav " << _name << " ATACAaAAAAaAAAAA a " << target << " de " << _attack_damage << "\n";
	}
}