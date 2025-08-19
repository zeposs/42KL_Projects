#include "contact.hpp"
#include <iostream>
#include <iomanip>

void Contact::setContact()
{
	std::cout << "First name: ";
	std::getline(std::cin, firstName);

	std::cout << "Last name: ";
	std::getline(std::cin, lastName);


	std::cout << "Nickname: ";
	std::getline(std::cin, nickname);


	std::cout << "Phone number: ";
	std::getline(std::cin, phoneNumber);

	std::cout << "Darkest secret: ";
	std::getline(std::cin, darkestSecret);
}


void Contact::printField(const std::string& str)
const {
	if (str.length() > 10)
		std::cout << str.substr(0, 9) + ".";
	else
		std::cout << std::setw(10) << str;
}

void Contact::displayShort(int index)
const {
	std::cout << std::setw(10) << index << "|";
	printField(firstName);std::cout << "|";
	printField(lastName); std::cout << "|";
	printField(nickname); std::cout << std::endl;
}

void Contact::displayFull() const {
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phoneNumber << std::endl;
	std::cout << "Darkest secret: " << darkestSecret << std::endl;
}
