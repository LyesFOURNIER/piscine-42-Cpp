/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:12:43 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/21 13:38:18 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

Weapon::Weapon( void )
{
	std::cout << "Weapon default constructor called" << std::endl;
	return ;
}

Weapon::~Weapon( void )
{
	return ;
}

Weapon::Weapon( const std::string &type )
{
	_type = type;
	return ;
}

const std::string &Weapon::getType( void ) const
{
	return (this->_type);
}

void	Weapon::setType( const std::string &type )
{
	this->_type = type;
	return ;
}
