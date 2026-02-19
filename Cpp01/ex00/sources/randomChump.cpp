/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:13:26 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/16 10:13:44 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

void	randomChump( std::string name )
{
	Zombie Chump;
	
	Chump.setname(name);
	Chump.announce();
	return;
}
