/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:26:39 by zernest           #+#    #+#             */
/*   Updated: 2025/12/02 22:29:20 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <iostream>

int main()
{
	srand(time(NULL));
	
	Base* base = generate();
	identify(base);
	identify(*base);
	delete base;
	return (0);
}