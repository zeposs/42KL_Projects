/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:39:54 by zernest           #+#    #+#             */
/*   Updated: 2025/12/22 18:55:26 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <exception>
#include <climits>

class Span
{
	private:
		unsigned int	_size;
		std::vector<int>	_data;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void	addNumber(int n);
		int		shortestSpan() const;
		int		longestSpan() const;

		class SpanFullException : public std::exception {
			public:
				const char* what() const throw() { return ("Span is already full!"); }
		};

		class NotEnoughIntegersException : public std::exception {
			public:
				const char* what() const throw() { return ("Ensure there is more than 2 integers!"); }
		};

		class NotIntException : public std::exception {
			public:
				const char* what() const throw() { return ("Span only excepts integers!"); }
		};
};

#endif