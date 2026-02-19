/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:24:55 by lfournie          #+#    #+#             */
/*   Updated: 2026/01/21 11:44:29 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

int	main( void )
{
	try
	{
		//PRESIDENTIAL PARDON TESTS
		//////////
		Bureaucrat jack( "Jack", 26);
		Bureaucrat john( "John", 6);
		PresidentialPardonForm Pform( "Bill" );
		//unsigned form
			/* std::cout 	<< jack << "\n"
						<< john << "\n"
						<< Pform
						<< std::endl;
			jack.signForm( Pform );
			john.executeForm( Pform ); */
		//
		//grade too low to execute form
			/* std::cout 	<< jack << "\n"
						<< john << "\n"
						<< Pform
						<< std::endl;
			jack.promoteBureaucrat();
			jack.signForm( Pform );
			john.executeForm( Pform ); */
		//
		//should work
			std::cout 	<< jack << "\n"
						<< john << "\n"
						<< Pform
						<< std::endl;
			jack.promoteBureaucrat();
			jack.signForm( Pform );
			john.promoteBureaucrat();
			john.executeForm( Pform );
		//
		//////////
		//ROBOTOMY REQUEST TESTS
		//////////
		Bureaucrat tom( "Tom", 73);
		Bureaucrat bob( "Bob", 46);
		RobotomyRequestForm Rform( "Jerry" );
		//unsigned form
		/* 	std::cout 	<< tom << "\n"
						<< bob << "\n"
						<< Rform
						<< std::endl;
			tom.signForm( Rform );
			bob.executeForm( Rform ); */
		//
		//grade too low to execute form
		/* 	std::cout 	<< tom << "\n"
						<< bob << "\n"
						<< Rform
						<< std::endl;
			tom.promoteBureaucrat();
			tom.signForm( Rform );
			bob.executeForm( Rform ); */
		//
		//should work
			std::cout 	<< tom << "\n"
						<< bob << "\n"
						<< Rform
						<< std::endl;
			tom.promoteBureaucrat();
			tom.signForm( Rform );
			bob.promoteBureaucrat();
			bob.executeForm( Rform );
		//
		//////////
		//SHRUBBERY CREATION TESTS
		//////////
		Bureaucrat tim( "Tim", 146);
		Bureaucrat carl( "Carl", 138);
		ShrubberyCreationForm Sform( "home" );
		//unsigned form
		/* std::cout 	<< tim << "\n"
						<< carl << "\n"
						<< Sform
						<< std::endl;
			tim.signForm( Sform );
		 	carl.executeForm( Sform ); */
		//
		//grade too low to execute form
		/* 	std::cout 	<< tim << "\n"
						<< carl << "\n"
						<< Sform
						<< std::endl;
			tim.promoteBureaucrat();
			tim.signForm( Sform );
			carl.executeForm( Sform ); */
		//
		//should work
			std::cout 	<< tim << "\n"
						<< carl << "\n"
						<< Sform
						<< std::endl;
			tim.promoteBureaucrat();
			tim.signForm( Sform );
			carl.promoteBureaucrat();
		 	carl.executeForm( Sform );
		//
		//////////
	}
	catch (const AForm::MissingTargetException &e)
	{
		std::cout << "Caught an exception: " << e.what() << std::endl;
	}
	catch (const AForm::MissingSignatureException &e)
	{
		std::cout << "Caught an exception: " << e.what() << std::endl;
	}
	catch (const AForm::GradeTooLowToExecuteException &e)
	{
		std::cout << "Caught an exception: " << e.what() << std::endl;
	}
	catch (const ShrubberyCreationForm::FailedToCreateFileException &e)
	{
		std::cout << "Caught an exception: " << e.what() << std::endl;
	}
	return (0);
}
