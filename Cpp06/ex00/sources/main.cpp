/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:15:31 by lfournie          #+#    #+#             */
/*   Updated: 2026/02/16 09:15:17 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Uses: <exe> <toConvert>" << std::endl;
		return (0);
	}
	ScalarConverter::convert( av[1] );
	return (0);
}
