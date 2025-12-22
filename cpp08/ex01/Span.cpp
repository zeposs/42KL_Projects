/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:58:41 by zernest           #+#    #+#             */
/*   Updated: 2025/12/22 18:55:23 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _size(0) {}

Span::Span(unsigned int n) : _size(n) {}

Span::Span(const Span &other)
{
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_size = other._size;
		_data = other._data;
	}
	return (*this);
}

Span::~Span() {}

void	Span::addNumber(int n)
{
	if (_data.size() >= _size)
		throw Span::SpanFullException();
	if (n < 0 || n > INT_MAX)
		throw Span::NotIntException();
	_data.push_back(n);
}

int	Span::shortestSpan() const
{
	if (_data.size() < 2)
		throw Span::NotEnoughIntegersException();

	std::vector<int> sort = _data;
	std::sort(sort.begin(), sort.end());
	int	sP = sort[1] - sort[0];
	for (size_t i = 1; i < sort.size(); i++)
	{
		int span = sort[i] - sort[i - 1];
		if (span < sP)
			sP = span;
	}
	return (sP);
}

int	Span::longestSpan() const
{
	if (_data.size() < 2)
		throw Span::NotEnoughIntegersException();
	
	int	max = *std::max_element(_data.begin(), _data.end());
	int	min = *std::min_element(_data.begin(), _data.end());

	return (max - min);
}