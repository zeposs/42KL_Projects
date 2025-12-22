/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:58:12 by zernest           #+#    #+#             */
/*   Updated: 2025/12/23 03:59:36 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	try
	{
		std::cout << "=====Subject.PDF Test=====\n";
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "=====10,000 Numbers Test=====\n";
		srand(time(NULL));
		Span largeTest(10000);
		for (int i = 0; i < 10000; ++i)
			largeTest.addNumber(rand());
		std::cout << "Shortest Span: " << largeTest.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << largeTest.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "=====Negative Test=====\n";
		Span Negative(4);
		
		Negative.addNumber(-10);
		Negative.addNumber(20);
		Negative.addNumber(5);
		Negative.addNumber(-3);
		std::cout << "Shortest Span: " << Negative.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << Negative.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "=====addMultiple Test=====\n";
		std::vector<int> v;
		Span aM(6);
		v.push_back(5);
		v.push_back(10);
		v.push_back(11);
		v.push_back(15);
		v.push_back(19);
		v.push_back(25);

		aM.addMultiple(v.begin(), v.end());
		std::cout << "Shortest Span: " << aM.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << aM.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "=====Exception Test=====\n";
		std::cout << "Span Full -> ";
		Span SpanFull(2);
		SpanFull.addNumber(10);
		SpanFull.addNumber(20);
		SpanFull.addNumber(30);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "Span too little integers -> ";
		Span SpanLittle(2);
		SpanLittle.addNumber(10);

		std::cout << SpanLittle.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "addMultiple overflow Test -> ";
		std::vector<int> nums;
		Span aMException(3);
		nums.push_back(5);
		nums.push_back(2);
		nums.push_back(8);
		nums.push_back(-5);

		aMException.addMultiple(nums.begin(), nums.end());
		std::cout << "Shortest Span: " << aMException.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << aMException.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}