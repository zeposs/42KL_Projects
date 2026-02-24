/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 19:05:43 by zernest           #+#    #+#             */
/*   Updated: 2026/02/23 22:28:31 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void) other;
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::validateFormat(const std::string &str)
{
	if (str.empty())
		throw std::runtime_error("Error: Argument cannot be empty.");
	size_t start = 0;
	if (str[0] == '+')
	{
		if (str.size() == 1)
			throw std::runtime_error("Error: Invalid '+' detected.");
		start = 1;
	}
	for (size_t i = start; i < str.size(); i++)
	{
		if (str[i] < '0' || str[i] > '9')
			throw std::runtime_error("Error: Ensure arguments only contain numbers.");
	}
}

std::vector<size_t> PmergeMe::jacobsThalGenerate(size_t n)
{
	std::vector<size_t> indices;

	if (n == 0)
		return indices;
	indices.push_back(1);
	if (n == 1)
		return indices;
	indices.push_back(3);
	size_t i = 2;
	while (true)
	{
		size_t next = indices[i - 1] + 2 *indices [i - 2];
		if (next > n)
			break;
		indices.push_back(next);
		i++;
	}
	return indices;
}

void PmergeMe::checkDuplicate(int value)
{
	for (size_t i = 0; i < _vec.size(); i++)
	{
		if (_vec[i] == value)
			throw std::runtime_error("Error: Duplicate Found.");
	}
}

void PmergeMe::printContainers(void)
{
	std::cout << "Vector: ";
	for (size_t i = 0; i < _vec.size(); i++)
	{
		std::cout << _vec[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Deque: ";
	for (size_t i = 0; i < _deq.size(); i++)
	{
		std::cout << _deq[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::parseInput(char **args)
{
	for (size_t i = 1; args[i] != NULL; i++)
	{
		validateFormat(args[i]);
		long value = std::strtol(args[i], NULL, 10);
		if (value < 0 || value > INT_MAX)
			throw std::runtime_error("Error: Value is invalid.");
		checkDuplicate(value);
		_vec.push_back(static_cast<int>(value));
	}
	for (size_t i = 0; i < _vec.size(); i++)
		_deq.push_back(_vec[i]);
	mergeInsert(_vec);
	mergeInsert(_deq);
	printContainers();
}