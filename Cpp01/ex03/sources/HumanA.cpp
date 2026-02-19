/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:12:56 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/21 10:44:19 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

HumanA::HumanA( const std::string &name, Weapon &new_weapon ) : _weapon(new_weapon)
{
	_name = name;
	return ;
}

HumanA::~HumanA( void )
{
	return ;
}

void	HumanA::attack( void )
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
	return ;
}

Weapon *HumanA::getWeaponaddress_debug( void )
{
	return (&this->_weapon);
}
