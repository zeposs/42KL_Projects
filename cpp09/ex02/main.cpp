/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 18:43:51 by zernest           #+#    #+#             */
/*   Updated: 2026/02/23 20:17:38 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: No arguements\n";
		return (1);
	}
	
	try {
		PmergeMe PmergeMe;
		PmergeMe.parseInput(av);
	}
	catch(const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}