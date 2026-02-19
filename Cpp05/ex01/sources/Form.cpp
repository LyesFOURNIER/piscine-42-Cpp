/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:35:24 by lfournie          #+#    #+#             */
/*   Updated: 2026/01/19 11:22:13 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

Form::Form( void ): _isSigned(false), _gradeToSign(1), _gradeToExecute(1)
{
	std::cout << "Form default constuctor called" << std::endl;
	return;
}

Form::Form( const std::string name, const int gradeToSign, const int gradeToExecute )
:  _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)  
{
	std::cout << this->_name << ": Constructor called" << std::endl;
	return;
}

Form::Form( Form &copy ) : _name(copy.getName()), _isSigned(copy.getIsSigned()),
_gradeToSign(copy.getGradeToExecute()), _gradeToExecute(copy.getGradeToExecute())
{
	std::cout << "Form copExecutenstructor called" << std::endl;
	return;
}

Form &Form::operator=( const Form &copy )
{
	this->_isSigned = copy.getIsSigned();
	std::cout << "Form copy assignement operator called" << std::endl;
	return (*this);
}

const std::string	Form::getName( void ) const
{
	if (this->_name.empty())
		throw MissingNameException();
	return (this->_name);
}

bool				Form::getIsSigned( void ) const
{
	return (this->_isSigned);
}

int					Form::getGradeToSign( void ) const
{
	if (this->_gradeToSign < 1)
		throw GradeTooHighException();
	if (this->_gradeToSign > 150)
		throw GradeTooLowException();
	return (this->_gradeToSign);
}

int					Form::getGradeToExecute( void ) const
{
	if (this->_gradeToExecute < 1)
		throw GradeTooHighException();
	if (this->_gradeToExecute > 150)
		throw GradeTooLowException();
	return (this->_gradeToExecute);
}

void				Form::beSigned( const Bureaucrat &cog )
{
	if (cog.getGrade() <= this->getGradeToSign())
		this->_isSigned = true;
	return;
}

Form::~Form( void )
{
	std::cout << "Form destructor called" << std::endl;
	return;
}

const char *Form::MissingNameException::what( void ) const throw()
{
	return ("Form name is missing");
}

const char *Form::GradeTooHighException::what( void ) const throw()
{
	return ("Grade to sign or execute can't be higher than 1");
}

const char *Form::GradeTooLowException::what( void ) const throw()
{
	return ("Grade to sign or execute can't be lower than 150");	
}

std::ostream &operator<<( std::ostream &stream, const Form &copy )
{
	stream 	<< "----------\n"
			<< copy.getName()
			<< "\nGrade to sign: " << copy.getGradeToSign()
			<< "\nGrade to execute: " << copy.getGradeToExecute()
			<< "\nIs signed: ";
	if (copy.getIsSigned())
		stream << "yes";
	else
		stream << "no";
	stream << "\n----------";
	return (stream);
}
