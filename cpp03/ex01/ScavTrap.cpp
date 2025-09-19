#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	hp = 100;
	energy = 50;
	atk = 20;
	std::cout << "ScavTrap " << GREEN << name << DEFAULT << " has been created." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hp = 100;
	energy = 50;
	atk = 20;
	std::cout << "ScavTrap " << GREEN << name << DEFAULT << " has been created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	*this = other;
	std::cout << "ScavTrap copy constructor called!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap copy assignment operator called!" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << GREEN << name << DEFAULT << " has been destroyed!" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (hp <= 0)
	{
		std::cout << "\u27A1 " << GREEN << "ScavTrap " << name << DEFAULT << " is dead :(" << std::endl;
	}
	else if (energy <= 0)
	{
		std::cout << "\u27A1 " << GREEN << "ScavTrap " << name << DEFAULT << " has no energy points." << std::endl;
	}
	else
	{
		std::cout << "\u27A1 " << GREEN << "ScavTrap " << name << DEFAULT << " attacks " << GREEN << target << DEFAULT << ", causing " << MAGENTA << atk << DEFAULT << " damage!" << std::endl;
		energy--;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}