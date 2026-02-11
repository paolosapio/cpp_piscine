#include "ClapTrap.hpp"

// using std::cout;

ClapTrap::ClapTrap() : _name("botRobo_bot"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "CLAP TRAP: CONTRUIDO CON NOMBRE: " << _name << "\n";
}


ClapTrap::ClapTrap(const std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "CLAP TRAP: SE le assigna el nombre: " << _name << "\n";

}


ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;
	std::cout << "CLAP TRAP: COPYNAME IS: " << _name << "\n";
}


ClapTrap::~ClapTrap()
{
	std::cout << "CLAP TRAP: DESTRUYE: " << _name << "\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	_name = other._name;
	_hit_points = other._hit_points;
	_energy_points = other._energy_points;
	_attack_damage = other._attack_damage;
	std::cout << "CLAP TRAP: operator= CALLED DEL BOT: " << _name << "\n";
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hit_points <= 0)
		std::cout << _name << " NO PUEDE ATACAR PORUQE esta muertisimo\n";
	else if (this->_energy_points <= 0)
		std::cout << _name << " NO PUEDE ATACAR PORUQE NOT ENERGY\n";
	else
	{
		_energy_points--;
		std::cout << _name << " ATACAaAAAAaAAAAA a " << target << " de " << _attack_damage << "\n";
	}

	
}

void ClapTrap::takeDamage(unsigned int amount) //20
{
	if (amount >= _hit_points)
		_hit_points = 0;
	else
		_hit_points = _hit_points - amount;
	
	std::cout << "el bot " << _name << " ha recibido ataque de " << amount << "\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit_points <= 0)
		return ;
	if (_energy_points <= 0)
	{
		std::cout  << _name << " esta sin energia\n";
		return ;
	}
	_hit_points = _hit_points + amount;
	_energy_points--;
	std::cout << _name << " se esta REPARANDO de " << amount << "\n";

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
	