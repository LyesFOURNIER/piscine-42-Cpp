/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:49:45 by lfournie          #+#    #+#             */
/*   Updated: 2026/06/25 11:22:06 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

//container to use: map
int main(int ac, char **av)
{
	BitCoinExchange test;

	if (ac != 2)
	{
		std::cout << "Error: path to file is missing" << std::endl;
		return 1;
	}
	test.parseInput(av[1]);
	return 0;
}
