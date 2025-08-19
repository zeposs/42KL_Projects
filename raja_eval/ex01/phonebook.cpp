#include "phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

PhoneBook::PhoneBook() : contactCount(0), oldestIndex(0) {}

void PhoneBook::addContact() {
	if (contactCount < 8)
		contacts[contactCount++].setContact();
	else {
		std::cout << "Phonebook full. Replacing oldest contact.\n";
		contacts[oldestIndex].setContact();
		oldestIndex = (oldestIndex + 1) % 8;
	}
}

void PhoneBook::searchContact() const {
	if (contactCount == 0) {
		std::cout << "No contacts found!\n";
		return;
	}

	std::cout << std::setw(10) << "Index" << "|"
	          << std::setw(10) << "First Name" << "|"
	          << std::setw(10) << "Last Name" << "|"
	          << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < contactCount; ++i)
		contacts[i].displayShort(i);

	std::cout << "Enter index to view full contact: ";
	int index;
	if (!(std::cin >> index) || index < 0 || index >= contactCount) {
		std::cin.clear(); // clear error flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard bad input
		std::cout << "Invalid index." << std::endl;
		return;
	}
	std::cin.ignore(); // clear newline from input buffer
	contacts[index].displayFull();
}