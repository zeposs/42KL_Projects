#include "Zombie.hpp"

void randomChump(std::string name);
Zombie* newZombie( std::string name );

int main(void)
{
	Zombie* heapZombie = newZombie("HeapZombie");
	heapZombie->announce();

	randomChump("StackZombie");
	
	delete (heapZombie);
	return (0);
}