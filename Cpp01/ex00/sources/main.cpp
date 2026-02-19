/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:55:12 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/16 11:59:58 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

int	main()
{
	Zombie *new_zombie;
	
	new_zombie = newZombie("Carl");
	new_zombie->announce();
	
	delete new_zombie;
	randomChump("Bob");
	return (0);
}
