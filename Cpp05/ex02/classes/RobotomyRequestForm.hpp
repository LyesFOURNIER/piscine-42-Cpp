/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 10:11:05 by lfournie          #+#    #+#             */
/*   Updated: 2026/01/21 11:09:45 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "../includes/lib.hpp"

class RobotomyRequestForm : public AForm
{
	public:

		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( RobotomyRequestForm &copy );
		RobotomyRequestForm &operator=( const RobotomyRequestForm &copy );
		~RobotomyRequestForm();
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
