#include "Zombie.hpp"

void Zombie::announce(void) 
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string inputName)
{
	name = inputName;
}

Zombie::~Zombie()
{
	std::cout << name << ": is destroyed." << std::endl;
}
