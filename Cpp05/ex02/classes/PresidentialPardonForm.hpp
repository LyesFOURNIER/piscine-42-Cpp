/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 10:10:06 by lfournie          #+#    #+#             */
/*   Updated: 2026/01/21 11:09:50 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "../includes/lib.hpp"

class PresidentialPardonForm : public AForm
{
	public:

		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( PresidentialPardonForm &copy );
		PresidentialPardonForm &operator=( const PresidentialPardonForm &copy );
		~PresidentialPardonForm();
	//GETTERS
		std::string getTarget( void ) const;
	//
	//MEMBER FUNCTIONS
		void	execute( const Bureaucrat &executor ) const;
	//

	private:

		std::string _target;
	
};

#endif
