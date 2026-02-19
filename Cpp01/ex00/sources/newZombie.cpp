/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:13:01 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/16 10:13:23 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

Zombie	*newZombie( std::string name )
{
	Zombie *new_zombie;
	
	new_zombie = new Zombie();
	new_zombie->setname(name);
	return (new_zombie);
}
