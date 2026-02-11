#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

#include "ClapTrap.hpp" 

class FragTrap : public ClapTrap
{
	protected:

	public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap &other);
	
	FragTrap& operator=(FragTrap &other);
	
	void highFivesGuys(void);
	
	~FragTrap();
};

#endif