/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:40:47 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/21 11:47:31 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "../includes/lib.hpp"

class	HumanA
{
	public:

	HumanA	( const std::string &name, Weapon &new_weapon );
	~HumanA	( void );
	
	void	attack( void );
	
	Weapon	*getWeaponaddress_debug( void );
	
	private:

	Weapon		&_weapon;
	std::string	_name;
	
};

#endif
