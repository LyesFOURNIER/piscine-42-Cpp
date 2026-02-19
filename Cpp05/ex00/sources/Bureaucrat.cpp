/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:14:56 by lfournie          #+#    #+#             */
/*   Updated: 2026/01/19 10:11:08 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

Bureaucrat::Bureaucrat( void )
{
	std::cout << "Default constuctor called" << std::endl;
	return;
}

Bureaucrat::Bureaucrat( std::string name, int grade )
{
	this->_name = name;
	this->_grade = grade;
	std::cout << this->_name << ": Constructor called" << std::endl;
	return;
}

Bureaucrat::Bureaucrat( Bureaucrat &copy )
{
	std::cout << "Copy constructor called" << std::endl;
	this->_name = copy._name;
	this->_grade = copy._grade;
	return;
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &copy )
{
	std::cout << "Copy assignement operator called" << std::endl;
	this->_name = copy._name;
	this->_grade = copy._grade;
	return (*this);
}

std::string Bureaucrat::getName( void ) const
{
	if (this->_name.empty())
			throw NameMissingException();
	return (this->_name);
}

int	Bureaucrat::getGrade( void ) const
{
	if (this->_grade< 1)
		throw GradeTooHighException();
	if (this->_grade > 150)
		throw GradeTooLowException();
	return (this->_grade);
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Destructor called" << std::endl;
	return;
}

void Bureaucrat::promoteBureaucrat( void )
{
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	std::cout << this->_name << " is promoted" << std::endl;
	this->_grade--;
}

void Bureaucrat::demoteBureaucrat( void )
{
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	std::cout << this->_name << " is demoted" << std::endl;
	this->_grade++;
}

const char *Bureaucrat::NameMissingException::what( void ) const throw ()
{
	return ("Bureaucrat name is missing");
}

const char *Bureaucrat::GradeTooHighException::what( void ) const throw ()
{
	return ("Bureaucrat grade can't be higher than 1");
}

const char *Bureaucrat::GradeTooLowException::what( void ) const throw ()
{
	return ("Bureaucrat grade can't be lower than 150");
}

std::ostream &operator<<( std::ostream &stream, const Bureaucrat &copy )
{
	stream << copy.getName() << ", bureaucrat grade " << copy.getGrade();
	return (stream);
}
