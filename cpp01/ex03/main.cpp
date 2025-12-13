#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon bomba = Weapon("bomba peponica");
		HumanA pepe("Pepe", bomba);
		pepe.attack();
		bomba.setType("un petardo");
		pepe.attack();
	}
	{
		Weapon otraArma = Weapon("pistola");
		HumanB jim("Pablo");
		jim.attack();
		jim.setWeapon(otraArma);
		otraArma.setType("cacahuete envenenado");
		jim.attack();
	}
	return (0);
}