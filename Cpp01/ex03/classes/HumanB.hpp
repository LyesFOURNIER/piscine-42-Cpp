/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:40:55 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/21 13:53:23 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "../includes/lib.hpp"

class	HumanB
{
	public:

	HumanB	( void );
	HumanB	( std::string name );
	~HumanB	( void );
	
	//SETTER
	void	setWeapon( Weapon &new_weapon );
	//
	void	attack( void );
	
	private:

	Weapon		*_weapon;
	std::string	_name;
	
};

#endif
