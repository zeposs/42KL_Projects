/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 21:02:34 by zernest           #+#    #+#             */
/*   Updated: 2025/11/19 22:06:48 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool 				_isSigned;
		const int			_signGrade;
		const int			_execGrade;
	public:
		Form();
		Form(const std::string name, const int signGrade, const int execGrade);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		void	beSigned(Bureaucrat &b);
		
		const std::string	getName() const;
		bool				getisSign() const;
		int			getsignGrade() const;
		int			getexecGrade() const;
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif