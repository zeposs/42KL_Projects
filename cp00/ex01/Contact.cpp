#include "Contact.hpp"

int Contact::FillContact()
{
	std::cout << "Enter First Name: ";
	std::getline(std::cin, FirstName);
	std::cout << "Enter Last Name: ";
	std::getline(std::cin, LastName);
	std::cout << "Enter Nick Name: ";
	std::getline(std::cin, NickName);
	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, PhoneNumber);
	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin, DarkestSecret);
	if (FirstName == "" || LastName == "" || NickName == ""|| PhoneNumber == "" || DarkestSecret == "")
	{
		std::cout << "None of the fields can be empty!" << std::endl;
		return (1);
	}
	else
		return (0);
}

void Contact::DisplayContact()
{
	std::cout << "First Name: " << FirstName << std::endl;
	std::cout << "Last Name: " << LastName << std::endl;
	std::cout << "Nick Name: " << NickName << std::endl;
	std::cout << "Phone Number: " << PhoneNumber << std::endl;
	std::cout << "Darkest Secret: " << DarkestSecret << std::endl;

}

std::string Contact::getFirstName()
{
	return (FirstName);
}

std::string Contact::getLastName()
{
	return (LastName);
}

std::string Contact::getNickName()
{
	return (NickName);
}