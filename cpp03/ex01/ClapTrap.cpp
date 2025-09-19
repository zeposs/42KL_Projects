#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("unnamed"), hp(10), energy(10), atk(0)
{
	std::cout << "ClapTrap " << GREEN << name << DEFAULT << " has been created." << std::endl;
}

ClapTrap::ClapTrap(std::string name): name(name), hp(10), energy(10), atk(0)
{
	std::cout << "ClapTrap " GREEN << name << DEFAULT << " has been created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other): name(other.name), hp(other.hp), energy(other.energy), atk(other.atk)
{
	std::cout << "ClapTrap copy constructor called!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment operator called!" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->hp = other.hp;
		this->energy = other.energy;
		this->atk = other.atk;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << GREEN << name << DEFAULT << " has been destroyed!" << std::endl;
}

void	ClapTrap::checkStats(void)
{
	if (hp < 0)
		hp = 0;
	std::cout << GREEN << std::endl << "\t\u2193 " << name << "'s stats \u2193" << std::endl;
	std::cout << YELLOW << "  _________________________" << std::endl << std::endl;
	std::cout << RED << "    Health \u2192 " << hp << std::endl;
	std::cout << BLUE << "    Energy \u2192 " << energy << std::endl;
	std::cout << MAGENTA << "    Attack Damage \u2192 " << atk << std::endl;
	std::cout << YELLOW << "  _________________________" << std::endl << std::endl;
	std::cout << DEFAULT;
}

void	ClapTrap::attack(const std::string& target)
{
	if (hp <= 0)
	{
		std::cout << "\u27A1 " << GREEN << name << DEFAULT << " is dead :(" << std::endl;
	}
	else if (energy <= 0)
	{
		std::cout << "\u27A1 " << GREEN << name << DEFAULT << " has no energy points." << std::endl;
	}
	else
	{
		std::cout << "\u27A1 " << GREEN << name << DEFAULT << " attacks " << GREEN << target << DEFAULT << ", causing " << MAGENTA << atk << DEFAULT << " damage!" << std::endl;
		energy--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	hp -= amount;
	std::cout << "\u27A1 " << GREEN << name << DEFAULT << " takes " << MAGENTA << amount << DEFAULT << " points of damage!" << std::endl;
	if (hp <= 0)
	{
		std::cout << "\u27A1 " << GREEN << name << DEFAULT << " is dead D:" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hp <= 0)
	{
		std::cout << "\u27A1 " << "It's too late... " << GREEN << name << DEFAULT << " is already dead :(" << std::endl;
	}
	else if (energy <= 0)
	{
		std::cout << "\u27A1 " << GREEN << name << DEFAULT << " has no energy points." << std::endl;
	}
	else
	{
		hp += amount;
		energy--;
		std::cout << "\u27A1 " << GREEN << name << DEFAULT << " repairs themself by " << RED << amount << DEFAULT << " health point(s)!" << std::endl;
	}
}