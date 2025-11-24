/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 21:02:34 by zernest           #+#    #+#             */
/*   Updated: 2025/11/19 22:08:37 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool 				_isSigned;
		const int			_signGrade;
		const int			_execGrade;
	public:
		AForm();
		AForm(const std::string name, const int signGrade, const int execGrade);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

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
		class FormNotSignedException : public std::exception {
		public:
			const char* what() const throw();
		};

		void	beSigned(Bureaucrat &b);
		
		const std::string	getName() const;
		bool				getisSign() const;
		int			getsignGrade() const;
		int			getexecGrade() const;
		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif