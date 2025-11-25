/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:21:28 by zernest           #+#    #+#             */
/*   Updated: 2025/11/25 17:17:36 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called\n";
}

Intern::Intern(const Intern &other)
{
	(void)other;
	std::cout << "Intern copy constructor called\n";
}

Intern &Intern::operator=(const Intern& other)
{
	std::cout << "Intern copy assignment operator called\n";
	(void)other;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called\n";
}

AForm* createShrub(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm* createRobo(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm* createPres(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	AForm* (*constructors[3])(std::string) = 
	{
		createShrub,
		createRobo,
		createPres
	};
	std::string names[3] =
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	for (int i = 0; i < 3; i++)
	{
		if (formName == names[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return constructors[i](target);
		}
	}
	throw Intern::UnknownFormException();
}

const char* Intern::UnknownFormException::what() const throw()
{
	return ("Form does not exist.");
}