#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FRAG_BOT", 100, 100, 30) //este metodo esta ya desarollado en claptrap.cpp
{
	std::cout << "CONSTRUIDO FragTrap\n";
}


FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "CONSTRUIDO FragTrap con nombre "<< _name << "y nuevos valores\n";
}


FragTrap::FragTrap(FragTrap &other) : ClapTrap()
{
	*this = other;
}


FragTrap& FragTrap::operator=(FragTrap &other)
{
	_name = other._name;
	_hit_points = other._hit_points;
	_energy_points = other._energy_points;
	_attack_damage = other._attack_damage;
	return (*this);
}


void FragTrap::highFivesGuys(void)
{
	if (_hit_points <= 0)
		std::cout << _name << "Esta MUERTO\n";
	else
		std::cout << "DAME 5 por arriba colega\n";
}


FragTrap::~FragTrap()
{
	std::cout << "DESTRUIDO FragTrap\n";
}