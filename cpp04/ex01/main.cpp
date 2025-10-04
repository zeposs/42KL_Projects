#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
    const Animal* animals[10];
    std::cout << BLUE << "\tCreating array" << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        if (i < 5)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    std::cout << RED << "\tDESTROYING ANIMALS" << std::endl;
    for (int i = 0; i < 10; ++i)
        delete animals[i];
    return (0);
}