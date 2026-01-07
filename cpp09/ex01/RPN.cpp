/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:09:36 by zernest           #+#    #+#             */
/*   Updated: 2026/01/07 17:23:23 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
	(void)other;
}

RPN &RPN::operator=(const RPN &other)
{
	(void)other;
	return (*this);
}

bool RPN::isValidOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}

int RPN::handleOperations(char c, int a, int b)
{
	if (c == '+')
		return (a + b);
	else if (c == '-')
		return (a - b);
	else if (c == '*')
		return (a * b);
	else if (c == '/')
		return (a / b);
	else
		throw std::runtime_error("Error: Invalid operator");
}

int RPN::evaluate(const std::string &expression)
{
	std::stack<int> stack;
	
	size_t i = -1;
	while (++i < expression.size())
	{
		if (expression[i] == ' ')
			continue;
		else if (expression[i] >= '0' && expression[i] <= '9')
			stack.push(expression[i] - '0');
		else if (isValidOperator(expression[i]))
		{
			if (stack.size() < 2)
			{
				throw std::runtime_error("Error: Bad RPN expression");
			}
			int b = stack.top(); stack.pop();
			int a = stack.top(); stack.pop();
			stack.push(handleOperations(expression[i], a, b));
		}
		else
			throw std::runtime_error("Error");
	}
	return (stack.top());
}