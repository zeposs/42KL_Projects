/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 19:58:11 by zernest           #+#    #+#             */
/*   Updated: 2025/12/02 21:47:44 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

bool	ScalarConverter::isChar(std::string &literal)
{
	return (literal.length() == 1 && !std::isdigit(literal[0]));
}

bool ScalarConverter::isInt(std::string &literal)
{
	int	i = 0;

	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (i == (int)literal.length())
		return (false);
	while (i < (int)literal.length())
	{
		if (!std::isdigit(literal[i]))
			return (false);
		i++;
	}
	return (true);
}

bool ScalarConverter::isDouble(std::string &literal)
{
	int i = 0;
	bool dot = false;
	bool digit = false;

	if (literal.empty())
		return false;
	if (literal[i] == '+' || literal[i] == '-')
		i++;

	for (; i < (int)literal.length(); ++i)
	{
		if (literal[i] == '.')
		{
			if (!dot)
				dot = true;
			else
				return (false);
		}
		else if (std::isdigit((unsigned char)literal[i]))
			digit = true;
		else
			return (false);
	}
	if (dot == false || digit == false)
		return (false);
	return (true);
}

bool ScalarConverter::isFloat(std::string &literal)
{
	if (literal.length() < 2)
		return (false);
	if (literal[literal.length() - 1] != 'f')
		return (false);
	std::string core = literal.substr(0, literal.length() - 1);
	return isDouble(core); // write isDouble function
}

bool isInvalid(std::string &literal)
{
	return  literal == "nan"  || literal == "+inf"  || literal == "-inf"  || literal == "inf" ||
			literal == "nanf" || literal == "+inff" || literal == "-inff" || literal == "inff";
}

LiteralType ScalarConverter::detectType (std::string &literal)
{
	if (isChar(literal))
		return CHAR;
	if (isInt(literal))
		return INT;
	if (isFloat(literal))
		return FLOAT;
	if (isDouble(literal))
		return DOUBLE;
	// if (isInvalid(literal))
	return INVALID;
}

void ScalarConverter::printConv(char c, long l, float f, double d)
{
	std::cout << "char: ";
	if (l <= 0 || l >= 127 )
		std::cout << "impossible\n";
	else if (!std::isprint(c))
		std::cout << "non displayable\n";
	else
		std::cout << "'" << c << "'" << '\n';

	std::cout << "int: ";
	if (l < INT_MIN || l > INT_MAX)
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(l) << std::endl;
	
	std::cout << "float: ";
	if (std::isnan(f))
		std::cout << "nanf\n";
	else if (std::isinf(f))
		std::cout << (f < 0 ? "-inff\n" : "+inff\n");
	else
		std::cout << std::fixed << std::setprecision(1) << f << "f\n";
	
	std::cout << "double: ";
	if (std::isnan(d))
		std::cout << "nan\n";
	else if (std::isinf(d))
		std::cout << (d < 0 ? "-inf\n" : "+inf\n");
	else
		std::cout << std::fixed << std::setprecision(1) << d << '\n';
	}

void ScalarConverter::convert(std::string &literal)
	{
		if (isChar(literal))
	{
		char c = literal[0];
		long i = static_cast<long>(c);
		float f = static_cast<float>(c);
		double d = static_cast<double>(c);
		printConv(c, i, f, d);
	}
	else if (isInt(literal))
	{
		long i = atol(literal.c_str());
		char c = static_cast<char>(i);
		float f = static_cast<float>(i);
		double d = static_cast<double>(i);
		printConv(c, i, f, d);
	}
	else if (isFloat(literal))
	{
		float f = strtof(literal.c_str(), 0);
		char c = static_cast<char>(f);
		long i = static_cast<long>(f);
		double d = static_cast<double>(f);
		printConv(c, i, f, d);
	}
	else if (isDouble(literal))
	{
		double d = strtod(literal.c_str(), 0);
		char c = static_cast<char>(d);
		long i = static_cast<long>(d);
		float f = static_cast<float>(d);
		printConv(c, i, f, d);
	}
	else if (isInvalid(literal))
	{
		if (literal[literal.length() - 1] == 'f')
		{
			float f = (literal == "nanf") ? NAN :
					  (literal == "+inff") ? INFINITY : -INFINITY;
			char c = 0;
			long i = 0;
			double d = static_cast<double>(f);
			printConv(c, i, f, d);
		}
		else  // double special
		{
			double d = (literal == "nan") ? NAN :
			(literal == "+inf") ? INFINITY : -INFINITY;
			char c = 0;
			long i = 0;
			float f = static_cast<float>(d);
			printConv(c, i, f, d);
		}
	}
	else
	{
		std::cout << "Error: invalid literal" << std::endl;
	}
}

// void ScalarConverter::fromChar(std::string &literal)
// {
// 	char c = literal[0];

// 	std::cout << "char: '" << c << "'" << std::endl;
// 	std::cout << "int: " << static_cast<int>(c) << std::endl;
// 	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
// 	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
// }

// void ScalarConverter::fromInt(std::string &literal)
// {
// 	int value = std::stoi(literal);

// 	if (value >= 0 && value <= 127)
// 	{
// 		if (std::isprint(value))
// 			std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
// 		else
// 			std::cout << "char: non displayable" << std::endl;
// 	}
// 	else
// 	std::cout << "char: impossible" << std::endl;
// 	std::cout << "int: " << value << std::endl;
// 	std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
// 	std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
// }

// void ScalarConverter::fromFloat(std::string &literal)
// {
// 	std::string core = literal.substr(0, literal.length() - 1);

// 	float value = std::stol(core.c_str());
// }