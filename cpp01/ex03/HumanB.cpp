#include "HumanB.hpp"

void HumanB::attack()
{
	if (weapon)
		std::cout << name << " attacks with their weapon " << weapon->getType() << std::endl;
	else
		std::cout << name << " has no weapon ._. " << std::endl;
}

void HumanB::setWeapon(Weapon &setWeapon)
{
	weapon = &setWeapon;
}

HumanB::HumanB(std::string name) : name(name), weapon(NULL){}