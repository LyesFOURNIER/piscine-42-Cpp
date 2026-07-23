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
void	vectorCreateMainAndPending(std::vector<int>&, std::vector<int>&, std::vector<int>&, std::vector<int>&, size_t);
void	vectorInsert(std::vector<int>&, size_t);
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

	if (*order > v->size() / 2)
	{
		*order /= 2;
		return;
	}	

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
	// for (std::vector<int>::iterator it = v->begin(); it != v->end(); it++)
	// {
	// 	std::cout << *it << " ";
	// }
	// std::cout << std::endl;
	vectorMerge(v, order);
}

void	vectorCreateMainAndPending(std::vector<int> &main, std::vector<int> &pending, std::vector<int> &remnant, std::vector<int> &v, size_t order)
{
	size_t groupCount = v.size() / order, remnantStart = groupCount * order;

	// first group
	main.push_back(v[order - 1]);
	// second group
	main.push_back(v[order + order - 1]);
	// remaining groups
	std::cout << "G1 -> main (" << v[order - 1] << ")\nG2 -> main (" << v[order + order - 1] << ")" << std::endl;
	bool toPending = true;
	for (size_t group = 2; group < groupCount; group++)
	{
	    if (toPending)
		{
			pending.push_back(v[group * order + order - 1]);
			std::cout << "G" << group + 1 << " -> pending (" << v[group * order + order - 1] << ")";
		}
	    else
		{
	        main.push_back(v[group * order + order - 1]);
			std::cout << "G" << group + 1 << " -> main (" << v[group * order + order - 1] << ")";
		}
		std::cout << std::endl;
	    toPending = !toPending;
	}
	for (size_t i = remnantStart; i < v.size(); i++)
		remnant.push_back(v[i]);
}

void	vectorInsert(std::vector<int> &v, size_t order)
{
	std::vector<int> main, pending, remnant;

	vectorCreateMainAndPending(main, pending, remnant, v, order);
	std::cout << "main: ";
	for (std::vector<int>::iterator it = main.begin(); it != main.end(); it++)
	{
 		std::cout << *it << " ";
 	}
 	std::cout << std::endl;
	std::cout << "pending: ";
	for (std::vector<int>::iterator it = pending.begin(); it != pending.end(); it++)
	{
 		std::cout << *it << " ";
 	}
 	std::cout << std::endl;
	std::cout << "remnant: ";
	for (std::vector<int>::iterator it = remnant.begin(); it != remnant.end(); it++)
	{
 		std::cout << *it << " ";
 	}
 	std::cout << std::endl;

}

void	PmergeMe::vectSort()
{
	std::vector<int>	v = _seq;
	size_t				order = 1;
	
	vectorMerge(&v, &order);

	std::cout << "order after vectorMerge: " << order << "\ninitial sequence: ";
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

	std::cout << "entering insert:" << std::endl;
	vectorInsert(v, order);
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