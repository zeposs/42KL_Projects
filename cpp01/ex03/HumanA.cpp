#include "HumanA.hpp"

void HumanA::attack()
{
	std::cout << name << " attacks with their weapon " << weapon.getType() << std::endl;
}

HumanA::HumanA(std::string HumanAName, Weapon &HumanAWeapon)
	: name(HumanAName), weapon(HumanAWeapon){}
