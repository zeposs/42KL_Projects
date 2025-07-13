#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact{
private:
	std::string FirstName;
	std::string LastName;
	std::string NickName;
	std::string PhoneNumber;
	std::string DarkestSecret;
public:
	int FillContact();
	void DisplayContact();
	std::string getFirstName();
	std::string getLastName();
	std::string getNickName();
};

#endif