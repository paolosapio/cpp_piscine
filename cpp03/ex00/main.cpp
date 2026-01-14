#include "ClapTrap.hpp"

int main()
{
	ClapTrap bot_a("pepe_bot");


	bot_a.takeDamage(-10);

	std::cout << bot_a.getName() << " TIENE: " << bot_a.getHitPoint() << " \n";

	bot_a.attack("CACA_BOT");

	for (int i = 0; i < 20; i++)
		bot_a.beRepaired(1);
	

	bot_a.takeDamage(5);
	bot_a.attack("CACA_BOT");

	// ClapTrap bot_b("bebe_bot");
	// ClapTrap bot_c(bot_b);

	// std::cout << bot_a.getName() << "\n";
	// std::cout << bot_b.getName() << "\n";
	// std::cout << bot_c.getName() << "\n";

	// bot_c = bot_c;

	// std::cout << bot_a.getName() << "\n";
	// std::cout << bot_b.getName() << "\n";
	// std::cout << bot_c.getName() << "\n";

	return (0);
}