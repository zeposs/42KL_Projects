/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:31:36 by zernest           #+#    #+#             */
/*   Updated: 2026/01/07 15:51:51 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		this->_database = other._database;
	return (*this);
}

bool BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	std::string line;

	if (!file.is_open())
	{
		std::cerr << "Error: database file failed to open." << std::endl;
		return false;
	}
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::string date;
		std::string rateStr;
		double rate;
		std::stringstream ss(line);
		
		if (!std::getline(ss, date, ',') || !std::getline(ss, rateStr))
			continue;
		rate = std::strtod(rateStr.c_str(), NULL);
		_database[date] = rate;
	}
	
	file.close();
	return true;
}

bool BitcoinExchange::processInput(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	std::string line;

	if (!file.is_open())
	{
		std::cerr << "Error: input file failed to open." << std::endl;
		return false;
	}

	std::getline(file, line);
	
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		size_t pipePos = line.find('|');
		if (pipePos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = line.substr(0, pipePos - 1);
		std::string valueStr = line.substr(pipePos + 2);		
		double value;
		if (!isValidDate(date))
		{
			std::cerr << "Error: invalid date => " << date << std::endl;
			continue;
		}
		if (!isValidValue(valueStr, value))
			continue;
		std::map<std::string, double>::const_iterator it = _database.lower_bound(date);
		if (it == _database.end() || it->first != date)
		{
			if (it == _database.begin())
			{
				std::cerr << "Error: no available rate for " << date << std::endl;
				continue;
			}
			--it;
		}
		double rate = it->second;
		std::cout << date << " => " << value << " = " << value * rate << std::endl;
	}
	file.close();
	return true;
}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
	if (date.size() != 10)
	{
		std::cerr << "Error: Ensure format is YYYY-MM-DD\n";	
		return false;
	}
	if (date[4] != '-' || date[7] != '-')
	{
		std::cerr << "Error: Ensure format is YYYY-MM-DD\n";
		return false;
	}
	int year = std::atoi(date.substr(0,4).c_str());
	int month = std::atoi(date.substr(5,2).c_str());
	int day = std::atoi(date.substr(8,2).c_str());

	if (year < 2009 || month > 12 || month < 1)
	{
		std::cerr << "Error: Invalid date\n";
		return false;
	}
	bool is31Days = false;
	if (month == 1 || month == 3 || month == 5||
		month == 7 || month == 8 || month == 10 || month == 12)
		is31Days = true;
	if (day > 1)
	{
		if (is31Days == true && day > 30)
			return false;
		return true;
	}
	return false;
}

bool BitcoinExchange::isValidValue(const std::string &valueStr, double &value) const
{
	value = std::strtod(valueStr.c_str(), NULL);
	if (value < 0)
	{
		std::cerr << "Error: not a positive number.\n";
		return false;
	}
	if (value > 1000)
	{
		std::cerr << "Error: too large a number.\n";
		return false;
	}
	return true;
}