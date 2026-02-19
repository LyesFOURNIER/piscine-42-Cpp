/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:33:23 by lfournie          #+#    #+#             */
/*   Updated: 2026/01/21 14:00:14 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include "../includes/lib.hpp"

class	Intern
{
	public:

	Intern( void );
	Intern( Intern &copy );
	Intern &operator=( const Intern &copy);
	~Intern();
	//MEMBER FUNCTIONS
	AForm	*makeForm( const std::string formName, const std::string formTarget );
	AForm	*makeSCF( const std::string target );
	AForm	*makeRRF( const std::string target );
	AForm	*makePPF( const std::string target );
	//
};

#endif

