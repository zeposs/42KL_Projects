/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:09:32 by zernest           #+#    #+#             */
/*   Updated: 2026/01/07 17:23:00 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: Please enter a single RPN expression\n";
		return (1);
	}
	RPN RPN;
	try
	{
		std::cout << RPN.evaluate(av[1]) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr<< e.what() << std::endl;
		return (1);
	}
	return (0);
}