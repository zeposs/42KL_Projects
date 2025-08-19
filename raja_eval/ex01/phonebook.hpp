#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook {
private:
	Contact contacts[8]; // Fixed size!
	int		contactCount;
	int		oldestIndex;

public:
	PhoneBook(); // Constructor
	void addContact(); // Handle ADD
	void searchContact() const; // Handle SEARCH
};

#endif