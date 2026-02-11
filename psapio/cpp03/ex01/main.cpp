#include "ScavTrap.hpp"

int main()
{
	ScavTrap bot1("HojaLata_Bot");
	ScavTrap bot2("Yataman");

	bot2 = bot1;

	bot2.guardGate();
	//ScavTrap bot2("cacharro");

	bot1.attack("CACA_BOT");
	std::cout << bot1.getName() << "\n";
	return (0);
}