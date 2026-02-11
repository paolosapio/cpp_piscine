#ifndef CPLAP_TRAP_HPP
# define CPLAP_TRAP_HPP

# include <iostream>

class ClapTrap
{
private:
	std::string _name;

	unsigned int _hit_points; // (10) vidas de ClapTrap
	unsigned int _energy_points; // (10) energia de ClapTrapp (para cargarse o atacar)
	unsigned int _attack_damage; // (0) daño que infiere al adversario
	
public:
	ClapTrap();
	ClapTrap(const std::string name);
	ClapTrap(const ClapTrap& other);

	~ClapTrap();

	ClapTrap& operator=(const ClapTrap& other);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string getName();

	int getEnergy();
	int getHitPoint();
	int getAttackDamage();
};

#endif