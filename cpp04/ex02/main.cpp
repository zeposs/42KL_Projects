#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
	// Animal a;

	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "Dog type: " << dog->getType() << std::endl;
	std::cout << "Cat type: " << cat->getType() << std::endl;

	std::cout << "\nDog sound: ";
	dog->makeSound();

	std::cout << "Cat sound: ";
	cat->makeSound();

	delete dog;
	delete cat;

	return 0;
}