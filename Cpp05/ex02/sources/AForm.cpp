/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:35:24 by lfournie          #+#    #+#             */
/*   Updated: 2026/01/21 09:31:31 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

AForm::AForm( void ): _isSigned(false), _gradeToSign(1), _gradeToExecute(1)
{
	std::cout << "AForm default constuctor called" << std::endl;
	return;
}

AForm::AForm( const std::string name, const int gradeToSign, const int gradeToExecute )
:  _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)  
{
	std::cout << this->_name << ": Parent class constructor called" << std::endl;
	return;
}

AForm::AForm( AForm &copy ) : _name(copy.getName()), _isSigned(copy.getIsSigned()),
_gradeToSign(copy.getGradeToExecute()), _gradeToExecute(copy.getGradeToExecute())
{
	std::cout << "AForm copExecutenstructor called" << std::endl;
	return;
}

AForm &AForm::operator=( const AForm &copy )
{
	this->_isSigned = copy.getIsSigned();
	std::cout << "AForm copy assignement operator called" << std::endl;
	return (*this);
}

const std::string	AForm::getName( void ) const
{
	if (this->_name.empty())
		throw MissingNameException();
	return (this->_name);
}

bool				AForm::getIsSigned( void ) const
{
	return (this->_isSigned);
}

int					AForm::getGradeToSign( void ) const
{
	if (this->_gradeToSign < 1)
		throw GradeTooHighException();
	if (this->_gradeToSign > 150)
		throw GradeTooLowException();
	return (this->_gradeToSign);
}

int					AForm::getGradeToExecute( void ) const
{
	if (this->_gradeToExecute < 1)
		throw GradeTooHighException();
	if (this->_gradeToExecute > 150)
		throw GradeTooLowException();
	return (this->_gradeToExecute);
}

void				AForm::beSigned( const Bureaucrat &cog )
{
	if (cog.getGrade() <= this->getGradeToSign())
		this->_isSigned = true;
	return;
}

void				AForm::execute( const Bureaucrat &executor ) const
{
	(void)executor;
	return;
}

AForm::~AForm( void )
{
	std::cout << "AForm destructor called" << std::endl;
	return;
}

const char *AForm::MissingNameException::what( void ) const throw()
{
	return ("AForm name is missing");
}

const char *AForm::GradeTooHighException::what( void ) const throw()
{
	return ("Grade to sign or execute can't be higher than 1");
}

const char *AForm::GradeTooLowException::what( void ) const throw()
{
	return ("Grade to sign or execute can't be lower than 150");	
}

const char *AForm::MissingTargetException::what( void ) const throw ()
{
	return ("Target missing for current form");
}

const char *AForm::MissingSignatureException::what( void ) const throw ()
{
	return ("Signature missing on current form");
}

const char *AForm::GradeTooLowToExecuteException::what( void ) const throw ()
{
	return ("Bureaucrat grade too low to execute current form");
}

std::ostream &operator<<( std::ostream &stream, const AForm &copy )
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
