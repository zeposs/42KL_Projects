#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	myHarl;

	if (ac != 2)
	{
		std::cout << "Please enter 1 arguement DUMBASS" << std::endl;
		return 1;
	}
	myHarl.complain(av[1]);
	return 0;
}