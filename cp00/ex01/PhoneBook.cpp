#include "PhoneBook.hpp"
#include <iomanip>

std::string PhoneBook::FormatField(const std::string& str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

PhoneBook::PhoneBook()
{
	Index = 0;
	Count = 0;
}

void PhoneBook::AddContact()
{
	int i = contacts[Index].FillContact();
	if (i)
		return ;
	Index++;
	if (Index == 8)
		Index = 0;
	if (Count < 8)
		Count++;
	std::cout << "contact added successfully." << std::endl;
}

void PhoneBook::ViewContact(int i)
{
	contacts[i - 1].DisplayContact();
}

void PhoneBook::SearchContact()
{
	std::cout << std::endl;
	std::cout << "|     INDEX|FIRST NAME| LAST NAME| NICK NAME|" << std::endl;

	for (int i = 0; i < Count; i++)
	{
		std::cout << "|" << std::setw(10) << i + 1;
		std::cout << "|" << std::setw(10) << FormatField(contacts[i].getFirstName());
		std::cout << "|" << std::setw(10) << FormatField(contacts[i].getLastName());
		std::cout << "|" << std::setw(10) << FormatField(contacts[i].getNickName());
		std::cout << "|" << std::endl;
	}
}