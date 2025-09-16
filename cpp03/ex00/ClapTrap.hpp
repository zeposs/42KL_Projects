#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <cstdio>

#define DEFAULT "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"

class ClapTrap
{
	private:
		std::string	name;
		int			hp;
		int			energy;
		int			atk;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		void checkStats(void);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif