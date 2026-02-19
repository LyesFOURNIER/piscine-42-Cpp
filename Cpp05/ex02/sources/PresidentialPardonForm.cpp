/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 10:57:28 by lfournie          #+#    #+#             */
/*   Updated: 2026/01/21 11:42:48 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm( "presidential pardon", 25, 5 )
{
	std::cout << "Presidential Pardon Form default constructor called" << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm( "presidential pardon", 25, 5 )
{
	this->_target = target;
	std::cout << "Presidential Pardon Form constructor called" << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm &copy ) : AForm( "presidential pardon", 25, 5 )
{
	this->_target = copy.getTarget();
	return;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm &copy )
{
	this->_target = copy.getTarget();
	return ( *this );
}

std::string PresidentialPardonForm::getTarget( void ) const
{
	return (this->_target);
}

void PresidentialPardonForm::execute( const Bureaucrat &executor) const
{
	if (this->_target.empty())
		throw MissingTargetException();
	if (!this->getIsSigned())
		throw MissingSignatureException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowToExecuteException();
	std::cout << this->_target << " has been pardoned by Zhaphod Beeblebrox" << std::endl;
	return;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout << "Presidential Pardon Form destructor called" << std::endl;
	return;
}
