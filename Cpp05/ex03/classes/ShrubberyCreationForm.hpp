/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 10:11:09 by lfournie          #+#    #+#             */
/*   Updated: 2026/01/21 11:08:49 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "../includes/lib.hpp"

class ShrubberyCreationForm : public AForm
{
	public:

		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( ShrubberyCreationForm &copy );
		ShrubberyCreationForm &operator=( const ShrubberyCreationForm &copy );
		~ShrubberyCreationForm();
	//GETTERS
		std::string getTarget( void ) const;
	//
	//MEMBERS FUNCTIONS
		void	execute( const Bureaucrat &executor ) const;
	//
	//EXCEPTIONS
	class	FailedToCreateFileException : public std::exception
		{
			public:
			
			const char *what() const throw();
		};
	//
		
	private:

		std::string _target;
	
};

#endif
