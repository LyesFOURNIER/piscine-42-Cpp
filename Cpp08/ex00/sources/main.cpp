/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:49:45 by lfournie          #+#    #+#             */
/*   Updated: 2026/02/12 09:56:15 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"
#include <vector>

int main()
{
	std::vector<int> v;

	for(int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for (int i = 0; i < 15; i++)
	{
		::easyfind(v, i);
	}
	return (0);
}
