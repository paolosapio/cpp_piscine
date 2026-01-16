#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap bot1("r2d2");
	ClapTrap bot2(bot1);

	bot2.attack("Mazinger");
	bot1.takeDamage(3);
	bot1.highFivesGuys();
	return (0);
}