/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:21:58 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/16 12:12:48 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

Zombie::Zombie( void )
{
	return ;
}

Zombie::~Zombie( void )
{
	std::cout << this->name << ": this zombie died of lack of brain" << std::endl;
	return ;
}

void Zombie::announce( void ) const
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

std::string	Zombie::getname( void ) const
{
	return this->name;
}

void	Zombie::setname( std::string name )
{
	this->name = name;
	return ;
}
