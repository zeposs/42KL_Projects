/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:48:10 by zernest           #+#    #+#             */
/*   Updated: 2025/12/10 16:45:58 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename T, typename F>
void	iter(T *add, const int len, F function)
{
	for (int i = 0; i < len; i++)
		function(add[i]);
}

template<typename T>
void	print(T &add)
{
	std::cout << add << std::endl;
}


#endif