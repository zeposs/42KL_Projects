#include "FragTrap.hpp"

// int main(void)
// {
// 	ClapTrap a("Mako");
// 	ClapTrap b("Saori");

// 	a.attack("Saori");
// 	b.takeDamage(0);
// 	a.checkStats();
// 	b.checkStats();
// 	b.beRepaired(1);
// 	b.checkStats();
// }

int main()
{
	FragTrap b("Mako");
	ClapTrap a("Saori");

	a.checkStats();
	b.checkStats();
	a.attack("target");
	b.attack("target");
	b.highFiveGuys();
}