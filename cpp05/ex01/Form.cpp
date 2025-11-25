/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 21:02:32 by zernest           #+#    #+#             */
/*   Updated: 2025/11/24 20:24:25 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _isSigned(0), _signGrade(150), _execGrade(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, const int signGrade, const int execGrade) : _name(name), _isSigned(0), _signGrade(signGrade), _execGrade(execGrade)
{
	if (execGrade < 1 || signGrade < 1)
		throw Form::GradeTooHighException();
	else if (execGrade > 150 || signGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	std::cout << "Form copy assignment constructor called\n";
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destructor called." << std::endl;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}

void	Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	_isSigned = 1;
}

const std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getisSign() const
{
	return (this->_isSigned);
}

int Form::getsignGrade() const
{
	return (this->_signGrade);
}

int Form::getexecGrade() const
{
	return (this->_execGrade);
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os  << "Name: " << f.getName() << std::endl
		<< "Sign status: " << f.getisSign() << std::endl
		<< "Sign Grade: " << f.getsignGrade() << std::endl
		<< "Exec Grade: " << f.getexecGrade() << std::endl;
	return (os);
}
