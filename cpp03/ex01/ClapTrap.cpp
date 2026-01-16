#include "ClapTrap.hpp"

// using std::cout;

ClapTrap::ClapTrap(const std::string name, int hit_points, int energy_points, int attack_damage)
{
	_name = name;
	_hit_points = hit_points;
	_energy_points = energy_points;
	_attack_damage = attack_damage;
	std::cout << "ClapTrap se crea y se llama: " << _name << "\n";

}


ClapTrap::ClapTrap() : _name("mazinga"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "CLAP TRAP: CONSTRUCTOR " << _name << "\n";
}


ClapTrap::ClapTrap(const std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "CLAP TRAP: NAME ASSIGNER: " << _name << "\n";

}


ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;
	std::cout << "CLAP TRAP: COPY" << _name << "\n";
}


ClapTrap::~ClapTrap()
{
	std::cout << "CLAP TRAP: DESTRUCTOR CALLED" << _name << "\n";
}


ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	_name = other._name;
	_hit_points = other._hit_points;
	_energy_points = other._energy_points;
	_attack_damage = other._attack_damage;
	std::cout << "CLAP TRAP: operator= CALLED" << _name << "\n";
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hit_points <= 0)
		std::cout << "el bicho esta muertisimo\n";
	else if (this->_energy_points <= 0)
		std::cout << "el bicho esta sin energia\n";
	else
	{
		_energy_points--;
		std::cout << "el bicho " << _name << " ATACAaAAAAaAAAAA a " << target << " de " << _attack_damage << "\n";
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "el bot " << _name << " ha recibido ataque de " << amount << "\n";
	_hit_points = _hit_points - amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit_points <= 0)
		return ;
	if (_energy_points <= 0)
	{
		std::cout << "el bicho esta sin energia\n";
		return ;
	}
	_hit_points = _hit_points + amount;
	_energy_points--;
	std::cout << "el bicho se esta REPARANDO de " << amount << "\n";

}

	std::string ClapTrap::getName()
	{
		return (_name);
	}

	int ClapTrap::getEnergy()
	{
		return (_energy_points);
	}
	
	int ClapTrap::getHitPoint()
	{
		return (_hit_points);
	}
	
	int ClapTrap::getAttackDamage()
	{
		return (_attack_damage);
	}
	
	