#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <cstdio>

class Zombie
{
	private:
		std::string name;
	public:
		void announce( void );
		Zombie(std::string inputName);
		~Zombie();

};

#endif