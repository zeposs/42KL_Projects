/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:11:51 by zernest           #+#    #+#             */
/*   Updated: 2025/12/01 23:45:36 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <climits>
#include <cmath>
#include <iomanip>

enum LiteralType {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
} ;

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();

		static bool isChar(std::string &literal);
		static bool isInt(std::string &literal);
		static bool isFloat(std::string &literal);
		static bool isDouble(std::string &literal);

		static LiteralType detectType (std::string &literal);

		static void printConv(char c, long i, float f, double d);
		// static void fromChar(std::string &literal);
		// static void fromInt(std::string &literal);
		// static void fromFloat(std::string &literal);
	public:
		static void convert(std::string &literal);
};

#endif