#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap bot1("r2d2");
	ClapTrap bot2(bot1);

	bot1.attack("Mazinger");
	bot1.takeDamage(330);
	bot1.highFivesGuys();
	return (0);
}