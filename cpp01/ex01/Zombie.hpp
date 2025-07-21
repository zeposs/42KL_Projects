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
        void setName(std::string inputName);
		Zombie();
		~Zombie();

};

#endif