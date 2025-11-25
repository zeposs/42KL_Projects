/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:47:36 by zernest           #+#    #+#             */
/*   Updated: 2025/11/25 19:28:40 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;

	AForm* form;

	try
	{
		form = someRandomIntern.makeForm("robotomy request", "Bender");
		if (form)
			delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try 
	{
		form = someRandomIntern.makeForm("shrubbery creation", "Garden");
		if (form)
			delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		form = someRandomIntern.makeForm("not real form", "Home");
		if (form)
		delete form;
		return 0;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
