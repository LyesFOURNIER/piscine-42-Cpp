/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 08:11:12 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/23 11:30:42 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

int	main(int ac, char **av)
{
	Harl	harl;
	int		i = 1;
	
	if (ac < 2)
		return (0);
	while (av[i])
	{
		harl.complain( av[i] );
		i++;
	}
	return (0);
}
