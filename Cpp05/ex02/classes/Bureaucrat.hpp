/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:25:57 by lfournie          #+#    #+#             */
/*   Updated: 2026/01/20 12:06:31 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include "../includes/lib.hpp"

class Bureaucrat
{
	public:
	
		Bureaucrat( void );
		Bureaucrat( std::string name, int grade );
		Bureaucrat( Bureaucrat &copy );
		Bureaucrat &operator=( const Bureaucrat &copy );
		~Bureaucrat();
	//GETTER
		std::string	getName( void ) const;
		int			getGrade( void ) const;
	//
	//MEMBER FUNCTIONS
		void		promoteBureaucrat( void );
		void		demoteBureaucrat( void );
		void		signForm( AForm &toSign );
		void		executeForm( const AForm &toExecute ) const;
	//
	//EXCEPTIONS
		class		MissingNameException : public std::exception
		{
			public:
			
			const char *what() const throw();
		};
		class		GradeTooHighException : public std::exception
		{
			public:
			
			const char *what() const throw();
		};
		class		GradeTooLowException : public std::exception
		{
			public:
			
			const char *what() const throw();
		};
	//
		
	private:
		
		std::string _name;
		int			_grade;
		
};
std::ostream &operator<<( std::ostream &stream, const Bureaucrat &copy );

#endif
