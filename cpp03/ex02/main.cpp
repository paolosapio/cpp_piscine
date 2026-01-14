#include "ScavTrap.hpp"

int main()
{
	ScavTrap bot1("HojaLata_Bot");
	ScavTrap bot2("Yataman");

	bot2 = bot1;

	bot1.guardGate();
	// ScavTrap bot2("cacharro");

	bot1.attack("CACA_BOT");
	// bot1.getName();
	return (0);
}