/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:28:19 by zernest           #+#    #+#             */
/*   Updated: 2026/01/07 15:55:37 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: Program requires input file.\n";
		return (1);
	}
	BitcoinExchange btc;
	if (!btc.loadDatabase("data.csv"))
	{
		std::cerr << "data.csv missing.\n";
		return (1);
	}
	btc.processInput(av[1]);
	return (0);
}
