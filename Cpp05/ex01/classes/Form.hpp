/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:57:26 by lfournie          #+#    #+#             */
/*   Updated: 2026/01/19 11:12:54 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include "../includes/lib.hpp"
class Bureaucrat;

class Form
{
	public:
	
		Form( void );
		Form( const std::string name, const int gradeToSign, const int gradeToExecute );
		Form( Form &copy );
		Form &operator=( const Form &copy );
		~Form();
		//GETTERS
		const std::string	getName( void ) const;
		bool				getIsSigned( void ) const;
		int					getGradeToSign( void ) const;
		int					getGradeToExecute( void ) const;
		//
		void	beSigned( const Bureaucrat &cog );
		class	MissingNameException : public std::exception
		{
			public:
			
			const char *what() const throw();
		};
		class	GradeTooHighException : public std::exception
		{
			public:
			
			const char *what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
			
			const char *what() const throw();
		};
	
	private:
	
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	
};
std::ostream &operator<<( std::ostream &stream, const Form &copy );

#endif
