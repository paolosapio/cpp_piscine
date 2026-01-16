#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
protected:

public:
	ScavTrap();
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap& other);

	~ScavTrap();

	ScavTrap& operator=(const ScavTrap& other);

	void guardGate();
	void attack(const std::string& target);
};

#endif