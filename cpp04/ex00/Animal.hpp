#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <cstdio>

#define DEFAULT "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"

class Animal
{
	protected:
		std::string type;
	public:
		void makeSound();

};

#endif