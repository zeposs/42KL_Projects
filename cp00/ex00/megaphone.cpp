#include <iostream>
#include <cstdio>

std::string toUpper(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}
	return str;
}

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	int i = 1;
	std::string line;
	while(av[i])
	{
		line = toUpper(av[i]);
		std::cout << line;
		i++;
	}
	std::cout << std::endl;
	return (0);
}