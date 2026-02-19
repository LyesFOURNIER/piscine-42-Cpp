/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 10:57:49 by lfournie          #+#    #+#             */
/*   Updated: 2026/01/21 11:45:36 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm( "robotomy request", 72, 45 )
{
	std::cout << "Robotomy Request Form default constructor called" << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm( "robotomy request", 72, 45 )
{
	this->_target = target;
	std::cout << "Robotomy Request Form constructor called" << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm &copy ) : AForm( "robotomy request", 72, 45 )
{
	this->_target = copy.getTarget();
	return;
}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &copy )
{
	this->_target = copy.getTarget();
	return ( *this );
}

std::string RobotomyRequestForm::getTarget( void ) const
{
	return (this->_target);
}

void RobotomyRequestForm::execute( const Bureaucrat &executor) const
{
	if (this->_target.empty())
		throw MissingTargetException();
	if (!this->getIsSigned())
		throw MissingSignatureException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowToExecuteException();
	srand(time(0));
	std::cout << "brrrr brrrr brrrrrrrrrrrrrrrrrrr" << std::endl;
	if (rand() % 2)
	{
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
		return;
	}
	std::cout << "Robotomy of " << this->_target << " has failed" << std::endl;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout << "Robotomy Request Form destructor called" << std::endl;
	return;
}
