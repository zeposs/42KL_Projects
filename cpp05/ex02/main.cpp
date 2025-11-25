/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zernest <zernest@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:47:36 by zernest           #+#    #+#             */
/*   Updated: 2025/11/25 19:22:45 by zernest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	AForm *form = new ShrubberyCreationForm("home");
	Bureaucrat alice("Alice", 1);

	alice.signForm(*form);
	form->execute(alice);

	AForm *form1 = new RobotomyRequestForm("home");
	Bureaucrat mako("Mako", 1);

	mako.signForm(*form1);
	form1->execute(mako);

	AForm *form2 = new PresidentialPardonForm("home");
	Bureaucrat saori("Saori", 1);

	saori.signForm(*form2);
	form2->execute(saori);
	delete form;
	delete form1;
	delete form2;
}	