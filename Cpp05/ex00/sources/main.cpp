/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:24:55 by lfournie          #+#    #+#             */
/*   Updated: 2026/01/15 10:56:02 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

int	main( void )
{
	Bureaucrat	jack;
	Bureaucrat	tim( "Tim", 0);
	Bureaucrat	tom( "Tom", 151);
	Bureaucrat	bill( "Bill", 1);
	Bureaucrat	jim( "Jim", 150);
	Bureaucrat	bob( "Bob", 10 );
	Bureaucrat	carl( "Carl", 10 );
	try
	{
		/*std::cout	<< jack
					<< std::endl; */
		//////////////////////////////
		/*std::cout	<< tim
					<< std::endl; */
		//////////////////////////////
		/*std::cout	<< tom
					<< std::endl; */
		//////////////////////////////
		/*std::cout	<< bill
					<< std::endl;
		bill.promoteBureaucrat(); */
		//////////////////////////////
		/*std::cout	<< jim
					<< std::endl;
		jim.demoteBureaucrat(); */
		//////////////////////////////
		std::cout 	<< bob << "\n"
					<< carl
					<< std::endl;
		bob.promoteBureaucrat();
		carl.demoteBureaucrat();
		std::cout 	<< bob << "\n"
					<< carl
					<< std::endl;
	}
	catch (const Bureaucrat::NameMissingException &e)
	{
		std::cout << "Caught an exception: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Caught an exception: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Caught an exception: " << e.what() << std::endl;
	}
	return (0);
}
