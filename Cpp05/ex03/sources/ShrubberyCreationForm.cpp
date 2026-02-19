/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 10:58:04 by lfournie          #+#    #+#             */
/*   Updated: 2026/01/21 11:46:09 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm( "shrubbery creation", 145, 137 )
{
	std::cout << "Shrubbery Creation Form default constructor called" << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm( "shrubbery creation", 145, 137 )
{
	this->_target = target;
	std::cout << "Shrubbery Creation Form constructor called" << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm &copy ) : AForm( "shrubbery creation", 145, 137 )
{
	this->_target = copy.getTarget();
	return;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm &copy )
{
	this->_target = copy.getTarget();
	return ( *this );
}

std::string ShrubberyCreationForm::getTarget( void ) const
{
	return (this->_target);
}

void ShrubberyCreationForm::execute( const Bureaucrat &executor) const
{
	if (this->_target.empty())
		throw MissingTargetException();
	if (!this->getIsSigned())
		throw MissingSignatureException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowToExecuteException();
	std::fstream		fs1;
	std::stringstream	ss;
	std::string 		fileName;
	fileName = this->getTarget();
	fileName.append( "_shrubbery" );
	fs1.open( fileName.c_str(), std::fstream::out );
	if (ss.fail())
		throw FailedToCreateFileException();
	fs1	<< "        _-_"  << "\n"
		<< "    //~~   ~~\\\\" << "\n"
		<< " //~~         ~~\\\\" << "\n"
		<< "{                 }" << "\n"
		<< " \\\\  _-     -_  //" << "\n"
		<< "   ~  \\\\   //  ~" << "\n"
		<< "_- -   |   | _- _" << "\n"
		<< "  _ -  |   |   -_" << "\n"
		<< "      //   \\\\" << "\n"
		<<	std::endl;
	fs1.close();
	return;
}

const char *ShrubberyCreationForm::FailedToCreateFileException::what( void ) const throw ()
{
	return ("File creation has failed");
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << "Shrubbery Creation Form destructor called" << std::endl;
	return;
}
