#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("Unknown")
{
	std::cout << "A WrongAnimal constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other): type(other.type)
{
	std::cout << "WrongAnimal copy constructor called!" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal copy assignment operator called!" << std::endl;
	if (this != &other)
	{
        this->type = other.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "The WrongAnimal vanishes..." << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal makeSound called." << std::endl; 
}

std::string WrongAnimal::getType() const
{
    return (type);
}