/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 21:23:30 by zernest           #+#    #+#             */
/*   Updated: 2025/12/17 17:53:19 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <exception>

class NotFoundException : public std::exception {
	public:
		const char* what() const throw() { return ("Value not found"); }
} ;

template <typename T>
typename T::iterator	easyfind(T &haystack, int needle)
{
	typename T::iterator it = std::find(haystack.begin(), haystack.end(), needle);

	if (it == haystack.end())
		throw NotFoundException();
	return (it);
}

#endif