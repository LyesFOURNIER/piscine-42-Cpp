/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:32:51 by lfournie          #+#    #+#             */
/*   Updated: 2026/01/21 14:00:42 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

Intern::Intern( void )
{
	std::cout << "Intern default constructor called" << std::endl;
	return;
}

Intern::Intern( Intern &copy )
{
	(void)copy;
	std::cout << "Intern copy constructor called" << std::endl;
	return;
}

Intern	&Intern::operator=( const Intern &copy )
{
	(void)copy;
	std::cout << "Intern copy assignement operator called" << std::endl;
	return (*this);
}

AForm	*Intern::makeForm( const std::string formName, const std::string formTarget )
{
	std::string	formNameTab[3];
	AForm	*(Intern::*formExecTab[3])( const std::string );

	formNameTab[0] = "shrubbery creation";
	formNameTab[1] = "robotomy request";
	formNameTab[2] = "presidential pardon";
	formExecTab[0] = &Intern::makeSCF;
	formExecTab[1] = &Intern::makeRRF;
	formExecTab[2] = &Intern::makePPF;
	for (int i = 0; i < 3; i++)
	{
		if (formName == formNameTab[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return((this->*formExecTab[i])( formTarget ));
		}
	}
	std::cout << "Form type not recognized" << std::endl;
	return (NULL);
}

AForm	*Intern::makeSCF( const std::string target )
{
	return( new ShrubberyCreationForm( target ) );
}

AForm	*Intern::makeRRF( const std::string target )
{
	return( new RobotomyRequestForm( target ) );
}

AForm	*Intern::makePPF( const std::string target )
{
	return( new PresidentialPardonForm( target ) );
}

Intern::~Intern( void )
{
	std::cout << "Intern destructor called" << std::endl;
	return;
}
