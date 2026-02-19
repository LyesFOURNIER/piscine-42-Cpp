/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:24:55 by lfournie          #+#    #+#             */
/*   Updated: 2026/01/19 12:04:31 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

int	main( void )
{
	Bureaucrat tom( "Tom", 50 );
	Form form1;
	Form form2( "Form 2", 0, 20 );
	Form form2bis( "Form 2bis", 20, 0 );
	Form form3( "Form 3", 151, 20 );
	Form form3bis( "Form 3bis", 20, 151 );
	Form form4( "Form 4", 50, 20 );
	Form form4bis( "Form 4bis", 51, 20);
	Form form4ter( "Form 4ter", 49, 20);
	try
	{
		/* std::cout	<< form1
					<< std::endl; */
		//////////////////////////////
		/* std::cout	<< form2
					<< std::endl; */
		//////////////////////////////
		/* std::cout	<< form2bis
					<< std::endl; */
		//////////////////////////////
		/* std::cout	<< form3
					<< std::endl; */
		//////////////////////////////
		/* std::cout	<< form3bis
					<< std::endl; */
		//////////////////////////////
		std::cout	<< form4
					<< std::endl;
		//////////////////////////////
		std::cout	<< form4bis
					<< std::endl;
		//////////////////////////////
		std::cout	<< form4ter
					<< std::endl;
		//////////////////////////////
		std::cout	<< tom
					<< std::endl;
		tom.signForm( form4 );
		tom.signForm( form4bis );
		tom.signForm( form4ter );
		std::cout	<< form4 << "\n"
					<< form4bis << "\n"
					<< form4ter
					<< std::endl;
		tom.promoteBureaucrat();
		tom.signForm( form4ter );
		std::cout	<< tom << "\n"
					<< form4ter
					<< std::endl;
	}
	catch (const Form::MissingNameException &e)
	{
		std::cout << "Caught an exception: " << e.what() << std::endl;
	}
	catch (const Form::GradeTooHighException &e)
	{
		std::cout << "Caught an exception: " << e.what() << std::endl;
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cout << "Caught an exception: " << e.what() << std::endl;
	}
	return (0);
}
