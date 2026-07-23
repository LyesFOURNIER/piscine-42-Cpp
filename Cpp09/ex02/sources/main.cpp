/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:49:45 by lfournie          #+#    #+#             */
/*   Updated: 2026/07/09 14:18:09 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

bool		isInputValid(char **);
std::string	convertInput(char **);


bool		isInputValid(char **input)
{
	std::string tmp;
	size_t k;
	
	for(size_t i = 1; input[i]; i++)
	{
		k = 0;
		for(size_t j = 0; j < std::strlen(input[i]); j += k - j)
		{
			tmp.clear();
			while (input[i][k] && input[i][k] != ' ')
			{
				if (!(input[i][k] >= '0' && input[i][k] <= '9'))
				{
					std::cerr << "Error: only positive interger are allowed in the sequence" << std::endl;
					return false;
				}
				tmp.append(1, input[i][k]);
				k++;
			}
			if (input[i][k] == ' ')
				k++;
			if (!(atol(tmp.c_str()) >= 0 && atol(tmp.c_str()) <= 2147483647))
			{
				std::cerr << "Error: value out of bounds" << std::endl;
				return false;
			}
		}
	}
	return true;
}

std::string	convertInput(char **input)
{
	std::string	ret;
	
	for (int i = 1; input[i]; i++)
	{
		for (int j = 0; input[i][j]; j++)
		{
				ret.append(1, input[i][j]);
		}
		ret.append(1, ' ');
	}
	return ret;
}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: missing argument" << std::endl;
		return 1;
	}
	if (!isInputValid(av))
		return 1;
	PmergeMe seq(convertInput(av));
	seq.vectSort();
	
	return 0;
}


/*
note parsing:

- only positive int
- check for int bounds

*/