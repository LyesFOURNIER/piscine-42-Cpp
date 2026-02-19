/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:19:35 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/16 11:47:39 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

int	main()
{
	Zombie *ptr;
	int		N;
	int		i = 0;
	
	N = 3;
	ptr = zombieHorde(N, "Bob");
	while (i < N)
	{
		std::cout << "index: " << i << " ";
		ptr[i].announce();
		i++;
	}
	delete[] ptr;
	return (0);
}
