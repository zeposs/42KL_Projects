/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:57:36 by zernest           #+#    #+#             */
/*   Updated: 2026/01/07 16:57:05 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <sstream>
#include <cstdlib>

class RPN
{
	private:
		bool isValidOperator(char c);
		int handleOperations(char , int a, int b);
	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);

		int evaluate(const std::string &expression);
};

#endif