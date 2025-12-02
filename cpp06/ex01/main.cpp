/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:03:12 by zernest           #+#    #+#             */
/*   Updated: 2025/12/02 22:08:35 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data d;

	d.data = "Helloooo!!";

	uintptr_t serial = Serializer::serialize(&d);

	std::cout << "real data: " << d.data << "\nreal data address: " << &d << std::endl;
	
	Data* deserialized = Serializer::deserialize(serial);
	
	std::cout << "restored data: " << deserialized->data << "\nrestored data address: " << deserialized << std::endl;
}