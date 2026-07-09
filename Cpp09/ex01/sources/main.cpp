/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:49:45 by lfournie          #+#    #+#             */
/*   Updated: 2026/07/01 14:19:58 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

//container to use: list
int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: input missing" << std::endl;
		return 1;
	}
	else if (ac > 2)
	{
		std::cerr << "Error: too many arguments" << std::endl;
		return 1;
	}
	RPN	polish(av[1]);
	polish.execInput();
	return 0;
}
