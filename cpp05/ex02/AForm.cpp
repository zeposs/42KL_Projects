/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 21:02:32 by zernest           #+#    #+#             */
/*   Updated: 2025/11/19 22:08:36 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _isSigned(0), _signGrade(150), _execGrade(150)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string name, const int signGrade, const int execGrade) : _name(name), _isSigned(0), _signGrade(signGrade), _execGrade(execGrade)
{
	if (execGrade < 1 || signGrade < 1)
		throw AForm::GradeTooHighException();
	else if (execGrade > 150 || signGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	std::cout << "AForm copy assignment constructor called\n";
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm destructor called." << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Formed not signed.");
}

void	AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	_isSigned = 1;
}

const std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getisSign() const
{
	return (this->_isSigned);
}

int AForm::getsignGrade() const
{
	return (this->_signGrade);
}

int AForm::getexecGrade() const
{
	return (this->_execGrade);
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
	os  << "Name: " << f.getName() << std::endl
		<< "Sign status: " << f.getisSign() << std::endl
		<< "Sign Grade: " << f.getsignGrade() << std::endl
		<< "Exec Grade: " << f.getexecGrade() << std::endl;
	return (os);
}
