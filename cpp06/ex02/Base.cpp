/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:17:40 by zernest           #+#    #+#             */
/*   Updated: 2025/12/02 22:27:40 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <iostream>

Base::~Base() {}

Base * generate()
{
	switch (rand() % 3)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		default:
			return new C;
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Pointer: A\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "Pointer: B\n";
	else if (dynamic_cast<C *>(p))
		std::cout << "Pointer: C\n";
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "Reference: A\n";
		return ;
	}
	catch (std::exception &e) {}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "Reference: B\n";
		return ;
	}
	catch (std::exception &e) {}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "Reference: C\n";
		return ;
	}
	catch (std::exception &e) {}
}