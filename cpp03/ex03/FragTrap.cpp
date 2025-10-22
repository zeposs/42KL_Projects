#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	hp = HP;
	energy = EP;
	atk = AD;
	std::cout << "FragTrap " << RED << name << DEFAULT << " has been created." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hp = HP;
	energy = EP;
	atk = AD;
	std::cout << "FragTrap " << RED << name << DEFAULT << " has been created." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	*this = other;
	std::cout << "FragTrap copy constructor called!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap copy assignment operator called!" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << RED << name << DEFAULT << " has been destroyed!" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (hp <= 0)
	{
		std::cout << "\u27A1 " << "FragTrap " << RED << name << DEFAULT << " is dead :(" << std::endl;
	}
	else if (energy <= 0)
	{
		std::cout << "\u27A1 " << "FragTrap " << RED << name << DEFAULT << " has no energy points." << std::endl;
	}
	else
	{
		std::cout << "\u27A1 " << "FragTrap " << RED << name << DEFAULT << " attacks " << RED << target << DEFAULT << ", causing " << MAGENTA << atk << DEFAULT << " damage!" << std::endl;
		energy--;
	}
}

void FragTrap::highFiveGuys()
{
	std::cout << "Don't leave FragTrap " << RED << name << DEFAULT << " hanging!" << std::endl;
}