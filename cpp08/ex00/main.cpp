/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 21:23:36 by zernest           #+#    #+#             */
/*   Updated: 2026/01/20 16:53:37 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	try
	{
		std::cout << "=====Working test=====\n";
		std::vector<int>::iterator it = easyfind(v, 30);
		std::cout << "Found: " << *it << std::endl;
		it = easyfind(v, 20);
		std::cout << "Found: " << *it << std::endl;
		it = easyfind(v, 10);
		std::cout << "Found: " << *it << std::endl;
		it = easyfind(v, 40);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "=====Fail test=====\n";
		std::vector<int>::iterator it = easyfind(v, 50);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}