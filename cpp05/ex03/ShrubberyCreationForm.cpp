/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:08:57 by zernest           #+#    #+#             */
/*   Updated: 2025/11/24 20:49:33 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
	std::cout << "ShrubberyCreationForm default constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm custom constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "ShrubberyCreationForm copy assignment constructor called\n";
	if (this != &other)
	{
		_target = other._target;
		AForm::operator=(other);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called\n";
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getexecGrade())
		throw AForm::GradeTooLowException();
	std::ofstream outfile((_target + "_shrubbery").c_str());
	if (!outfile)
	{
		std::cerr << "Failed to create file" << std::endl;
		return;
	}

	outfile << 
"           ,\n"
"          / \\\n"
"        .'   '.\n"
"       /       \\\n"
"      /.-.   .-.\\\n"
"      `/  '.'   \'\n"
"     .'          '.\n"
"    /.--.     .--.\\\n"
"    `/   '. .'    \\\n"
"   .'      `       '.\n"
"  /.---.       .----.\\\n"
"  `/    `.   .'     \'\n"
" .'       `.'        '.\n"
"/,----,          ,----,\\\n"
"`'-.__.;-,____,-;.__.-'\n"
"         |||||\n"
"         |||||\n"
"         `|||` \n";
}