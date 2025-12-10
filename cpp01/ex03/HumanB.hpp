#ifndef HUMANB_HPP
# define HMANB_HPP

# include <Weapon.hpp>

class HumanB
{
private:
	Weapon		_weapon;
	std::string	_name;
	
	public:
	HumanB(std::string name);
	~HumanB();

	void attack(); //<name> attacks with their <weapon type>
	void setWeapon(Weapon weapon);
};

#endif