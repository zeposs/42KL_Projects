/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 19:58:11 by zernest           #+#    #+#             */
/*   Updated: 2025/11/27 22:41:09 by zernest          ###   ########.fr       */
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

static bool	isChar(std::string &literal)
{
	return (literal.length() == 1 && !std::isdigit(literal[0]));
}

static bool isInt(std::string &literal)
{
	int	i = 0;

	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (i == literal.length())
		return (false);
	while (i < literal.length())
	{
		if (!std::isdigit(literal[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool isDouble(std::string &literal)
{
	
}

static bool isFloat(std::string &literal)
{
	if (literal.length() < 2)
		return (false);
	if (literal[literal.length() - 1] != 'f')
		return (false);
	return std::isDouble // write isDouble function
}

void	ScalarConverter::convert(std::string &literal)
{
	
}
