#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>
#include <iostream>
#include <sstream>

class PhoneBook{
private:
	Contact contacts[8];
	int Count;
	int Index;
public:
	PhoneBook();
	void AddContact();
	void SearchContact();
	void ViewContact(int i);
	std::string FormatField(const std::string& str);
};

#endif