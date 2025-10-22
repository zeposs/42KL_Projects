#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

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
	ClapTrap	clap("ClapTrap");
	ScavTrap 	scav("ScavTrap");
	FragTrap	frag("FragTrap");
	DiamondTrap diamond("DiamondTrap");

	diamond.attack("Claptrap");
	clap.takeDamage(30);
	clap.attack("diamond");
}