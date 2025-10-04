#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	type = "WrongCat";
	std::cout << "You encounter a sleeping WrongCat." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	*this = other;
	std::cout << "WrongCat copy constructor called!" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat copy assignment operator called!" << std::endl;
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "The WrongCat ran away." << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "The WrongCat meows at you." << std::endl;
}