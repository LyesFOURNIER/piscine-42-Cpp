/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 10:43:29 by lfournie          #+#    #+#             */
/*   Updated: 2026/07/09 14:57:27 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

void	vectorMerge(std::vector<int>*, size_t*);
void	dequeMerge(std::deque<int>*, size_t*);

PmergeMe::PmergeMe( void )
{
	return;
}

PmergeMe::PmergeMe(std::string input)
{
	std::string tmp;

	for(size_t i = 0; i < input.size(); i++)
	{
		tmp.clear();
		while ( i < input.size() && (input[i] >= '0' && input[i] <= '9'))
		{
			tmp.append(1, input[i]);
			i++;
		}
		if (!tmp.empty())
			_seq.push_back(atoi(tmp.c_str()));
	}
	
	return;
}

PmergeMe::PmergeMe(const PmergeMe &copy) : _seq(copy._seq)
{
	return;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	if (_seq != copy._seq)
		_seq = copy._seq;
		
	return *this;
}

void	vectorMerge(std::vector<int> *v, size_t *order)
{
	int	tmp;

	std::cout 	<< "\norder = " << *order
				<< std::endl;
	if (*order > v->size() / 2)
		return;

	for (size_t groups = 1; groups <  v->size() / *order; groups += 2)
	{
		if ((*v)[*order * groups - 1] > (*v)[*order * (groups + 1) - 1])
		{
			for (size_t i = *order * groups - *order; i < *order * groups; i++)
			{
				tmp = (*v)[i];
				(*v)[i] = (*v)[i + *order];
				(*v)[i + *order] = tmp;
			}
		}
	}
	*order *= 2;
	for (std::vector<int>::iterator it = v->begin(); it != v->end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	vectorMerge(v, order);
}
	
void	PmergeMe::vectSort()
{
	std::vector<int>	v = _seq;
	size_t				order = 1;
	
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	vectorMerge(&v, &order);

	std::cout << "\norder after vectorMerge: " << order << "\ninitial sequence: ";
	for (std::vector<int>::iterator it = _seq.begin(); it != _seq.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout <<"\nvector v after vectorMerge: ";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	dequeMerge(std::vector<int> *d, size_t *order)
{
	(void)d;
	(void)order;
}

void	PmergeMe::dequeSort(std::vector<int> &d)
{
	(void)d;
}

PmergeMe::~PmergeMe( void )
{
	return;
}


// for (std::vector<int>::iterator it = _seq.begin(); it != _seq.end(); it++)
// 	{
// 		std::cout << *it << " ";
// 	}
// 	std::cout << std::endl;