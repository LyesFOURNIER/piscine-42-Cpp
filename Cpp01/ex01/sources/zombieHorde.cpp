/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:22:32 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/16 10:57:06 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	int		i = 0;
	Zombie	*ptr;

	ptr = new Zombie[N];
	while (i < N)
	{
		ptr[i].setname(name);
		i++;
	}
	return (ptr);
}
