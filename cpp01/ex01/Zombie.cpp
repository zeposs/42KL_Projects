#include "Zombie.hpp"

void Zombie::announce(void) 
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string inputName)
{
    name = inputName;
}

Zombie::Zombie() {}

Zombie::~Zombie()
{
	std::cout << name << ": is destroyed." << std::endl;
}
