#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap()
{
	hp = FragTrap::HP;
	energy = ScavTrap::EP;
	atk = FragTrap::AD;
	std::cout << "DiamondTrap " << GREEN << name << DEFAULT << " has been created." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), name(name)
{
	hp = FragTrap::HP;
	energy = ScavTrap::EP;
	atk = FragTrap::AD;
	std::cout << "DiamondTrap " GREEN << name << DEFAULT << " has been created." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name)
{
	std::cout << "DiamondTrap copy constructor called!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap copy assignment operator called!" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		name = other.name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << GREEN << name << DEFAULT << " has been destroyed!" << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "Diamond Trap name: " << name << "ClapTrap name: " << ClapTrap::name << std::endl;
}