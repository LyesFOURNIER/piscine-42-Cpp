/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:13:04 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/21 13:53:32 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

HumanB::HumanB( void ) : _weapon(NULL)
{
	return ;
}

HumanB::HumanB( std::string name ) : _weapon(NULL)
{
	this->_name = name;
	return ;
}

HumanB::~HumanB( void )
{
	return ;
}

void	HumanB::setWeapon( Weapon &new_weapon )
{
	_weapon = &new_weapon;
	return ;
}

void	HumanB::attack( void )
{
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	return ;
}
