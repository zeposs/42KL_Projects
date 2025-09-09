#include <iostream>
#include <fstream>
#include <string>

std::string replace_line(std::string line, const std::string s1, const std::string s2)
{
	size_t pos;

	pos = line.find(s1);
	
	while (pos != std::string::npos)
	{
		std::string before = line.substr(0, pos);
		std::string after = line.substr(pos + s1.length());
		line = before + s2 + after;
		pos = line.find(s1, pos + s2.length());
	}
	return line;
}

int main(int ac, char **av)
{
	std::string line;

	if (ac != 4)
	{
		std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be empty." << std::endl;
		return 1;
	}
	std::ifstream infile(filename.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: Could not open input file: " << filename << std::endl;
		return 1;
	}
	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error: Could not create output file." << std::endl;
		infile.close();
		return 1;
	}
	while(std::getline(infile, line))
	{
		line = replace_line(line, s1, s2);
		outfile << line << std::endl;
	}
	infile.close();
	outfile.close();
	return (0);
}