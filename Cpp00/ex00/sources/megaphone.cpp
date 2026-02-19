/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:22:51 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/15 09:54:15 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	int		i = 1;
	int		j;
	char c;
	
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			c = std::toupper(av[i][j]);
			std::cout << c;
			j++;
		}
		i++;
	}
	std::cout << std::endl;
	return (0);
}
