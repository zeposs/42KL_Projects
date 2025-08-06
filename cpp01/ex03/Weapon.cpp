#include "Weapon.hpp"

const std::string& Weapon::getType() const
{
	return type;
}

Weapon::Weapon(std::string weaponType)
{
	type = weaponType;
}

void Weapon::setType(std::string newType)
{
    type = newType;
}
