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

bool	groupCompare(const t_group &a, const t_group &b);
void	vectorMerge(std::vector<int>*, size_t*);
void	vectorAnalyze(t_info&, std::vector<int>&, size_t);
void	vectorBuildChains(s_state<std::vector<t_group>, std::vector<int> >&, std::vector<int>&);
void	vectorGenerateInsertionOrder(s_state<std::vector<t_group>, std::vector<int> >&);
// void	vectorCreateMainAndPending(std::vector<t_group>&, std::vector<t_group>&, std::vector<int>&, std::vector<int>&, size_t);
void	vectorInsertPendingIntoMain(s_state<std::vector<t_group>, std::vector<int> >&);
void	vectorRebuildSequence(s_state<std::vector<t_group>, std::vector<int> >&, std::vector<int>&);
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

bool	groupCompare(const t_group &a, const t_group &b)
{
	return a.groupRep < b.groupRep;
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

void	vectorAnalyze(t_info &info, std::vector<int> &v, size_t order)
{
	info.order = order;
	info.groupCount = v.size() / info.order;
    info.pairCount = info.groupCount / 2;
    info.remnantStart = info.groupCount * info.order;
    info.hasOddGroup = (info.groupCount % 2 != 0);
}

void	vectorBuildChains(s_state<std::vector<t_group>, std::vector<int> > &state, std::vector<int> &v)
{
	for (size_t pair = 0; pair < state.info.pairCount; pair++)
	{
		t_group b;
		t_group a;
		b.start = (pair * 2) * state.info.order;
    	b.groupRep = v[b.start + state.info.order - 1];
    	a.start = (pair * 2 + 1) * state.info.order;
    	a.groupRep = v[a.start + state.info.order - 1];
		if (pair == 0)
		{
			state.main.push_back(b);
			state.main.push_back(a);
		}
		else
		{
			state.pending.push_back(b);
			state.main.push_back(a);
		}
	}
	if (state.info.hasOddGroup)
	{
		state.oddGroup.start = (state.info.pairCount * 2) * state.info.order;
		state.oddGroup.groupRep = v[state.oddGroup.start + state.info.order - 1];
	}
	for (size_t i = state.info.remnantStart; i < v.size(); i++)
		state.remnant.push_back(v[i]);
}

// void	vectorCreateMainAndPending(std::vector<t_group> &main, std::vector<t_group> &pending, std::vector<int> &remnant, std::vector<int> &v, size_t order)
// {
// 	size_t groupCount = v.size() / order, remnantStart = groupCount * order;

// 	bool toPending = true;
// 	for (size_t group = 0; group < groupCount; group++)
// 	{
// 		t_group current;
// 		current.start = group * order;
// 		current.groupRep = v[current.start + order - 1];
// 		if (group < 2)
// 		{
// 			main.push_back(current);
// 			// std::cout << "G" << group + 1 << " -> main [" << "start = " << current.start << ", rep = " << current.groupRep << "]" << std::endl;
// 			continue;
// 		}
// 	    if (toPending)
// 		{
// 			pending.push_back(current);
// 			// std::cout << "G" << group + 1 << " -> pending [" << "start = " << current.start << ", rep = " << current.groupRep << "]";
// 		}
// 	    else
// 		{
// 	        main.push_back(current);
// 			// std::cout << "G" << group + 1 << " -> main [" << "start = " << current.start << ", rep = " << current.groupRep << "]";
// 		}
// 		// std::cout << std::endl;
// 	    toPending = !toPending;
// 	}
// 	for (size_t i = remnantStart; i < v.size(); i++)
// 		remnant.push_back(v[i]);
// }

void	vectorGenerateInsertionOrder(s_state<std::vector<t_group>, std::vector<int> > &state)
{
	
}

void	vectorInsertPendingIntoMain(s_state<std::vector<t_group>, std::vector<int> > &state)
{
	for (size_t i = 0; i < state.pending.size(); i++)
	{
		state.main.insert(std::upper_bound(state.main.begin(), state.main.end(), state.pending[i], groupCompare), state.pending[i]);
	}
}

void	vectorRebuildSequence(s_state<std::vector<t_group>, std::vector<int> > &state, std::vector<int> &v)
{
	std::vector<int> rebuilt;

	for (size_t i = 0; i < state.main.size(); i++)
	{
		for (size_t j = state.main[i].start; j < state.main[i].start + state.info.order; j++)
		{
			rebuilt.push_back(v[j]);
		}
	}
	rebuilt.insert(rebuilt.end(), state.remnant.begin(), state.remnant.end());
	v.swap(rebuilt);
}

void	vectorInsert(std::vector<int> &v, size_t order)
{
	s_state<std::vector<t_group>, std::vector<int> > state;
	// std::vector<t_group> main, pending;
	// std::vector<int> remnant;

	if (order < 1)
		return;
	vectorAnalyze(state.info, v, order);
	vectorBuildChains(state, v);
	std::cout << "main: ";
	for (size_t i = 0; i < state.main.size(); i++)
	{
 		std::cout << state.main[i].groupRep << " ";
 	}
 	std::cout << std::endl;
	std::cout << "pending: ";
	for (size_t i = 0; i < state.pending.size(); i++)
	{
 		std::cout << state.pending[i].groupRep << " ";
 	}
 	std::cout << std::endl;
	if (state.info.hasOddGroup)
		std::cout << "odd: " << state.oddGroup.groupRep << std::endl;
	std::cout << "remnant: ";
	for (std::vector<int>::iterator it = state.remnant.begin(); it != state.remnant.end(); it++)
	{
 		std::cout << *it << " ";
 	}
 	std::cout << std::endl;

	vectorGenerateInsertionOrder(state);

	vectorInsertPendingIntoMain(state);

	std::cout << "main after pending insert: ";
	for (size_t i = 0; i < state.main.size(); i++)
	{
 		std::cout << state.main[i].groupRep << " ";
 	}
 	std::cout << std::endl;

	if (state.info.hasOddGroup)
	{
		state.main.insert(std::upper_bound(state.main.begin(), state.main.end(), state.oddGroup, groupCompare), state.oddGroup);
		std::cout << "main after odd group insert: ";
		for (size_t i = 0; i < state.main.size(); i++)
		{
			 std::cout << state.main[i].groupRep << " ";
		 }
		 std::cout << std::endl;
	}    
		


	vectorRebuildSequence(state, v);

	std::cout <<"vector v after rebuild: ";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	vectorInsert(v, order / 2);
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