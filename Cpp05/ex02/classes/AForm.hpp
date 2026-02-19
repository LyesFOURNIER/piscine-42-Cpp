/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:57:26 by lfournie          #+#    #+#             */
/*   Updated: 2026/01/21 09:30:21 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include "../includes/lib.hpp"
class Bureaucrat;

class AForm
{
	public:
	
		AForm( void );
		AForm( const std::string name, const int gradeToSign, const int gradeToExecute );
		AForm( AForm &copy );
		AForm &operator=( const AForm &copy );
		~AForm();
	//GETTERS
		const std::string	getName( void ) const;
		bool				getIsSigned( void ) const;
		int					getGradeToSign( void ) const;
		int					getGradeToExecute( void ) const;
	//
	//MEMBER FUNCTIONS
		void	beSigned( const Bureaucrat &cog );
		virtual void	execute( const Bureaucrat &executor ) const = 0;
	//
	//EXCEPTIONS
		class	MissingNameException : public std::exception
		{
			public:
			
			const char *what() const throw();
		};
		class	MissingTargetException : public std::exception
		{
			public:
			
			const char *what() const throw();
		};
		class	MissingSignatureException : public std::exception
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
		class	GradeTooLowToExecuteException : public std::exception
		{
			public:
			
			const char *what() const throw();
		};
	//
		
	private:
	
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	
};
std::ostream &operator<<( std::ostream &stream, const AForm &copy );

#endif
