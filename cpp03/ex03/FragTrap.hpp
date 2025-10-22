#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap

{
	protected:
		static const int	HP = 100;
		static const int	EP = 100;
		static const int	AD = 30;
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& other);
		FragTrap& operator=(const FragTrap& other);
		~FragTrap();

		void	attack(const std::string& target);
		void	highFiveGuys(void);
};

#endif