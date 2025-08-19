#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	void printField(const std::string& str) const;

public:
	void setContact(); // fill all fields
	void displayShort(int index) const; // for SEARCH table
	void displayFull() const; // for full contact view
};

#endif