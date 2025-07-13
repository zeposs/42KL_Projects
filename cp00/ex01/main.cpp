#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
	Contact c;
	PhoneBook book;
	std::string input;
	int index;

	while (1)
	{	
		std::cout << "Enter command: ";
		std::getline(std::cin, input);
		if (input == "ADD")
			book.AddContact();
		else if (input == "EXIT")
			break ;
		else if (input == "SEARCH")
		{
			book.SearchContact();
			std::cout <<"Enter contact index: ";
			std::getline(std::cin, input);
			std::istringstream temp(input);
			temp >> index;
			if (index > 8 || index < 1)
				std::cout << "Please input a number between 1 and 8." << std::endl;
			else
				book.ViewContact(index);
		}
		else
			std::cout << "Enter either ADD, SEARCH or EXIT." << std::endl;
	}
}
