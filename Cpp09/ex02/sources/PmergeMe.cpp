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

void	vectorMerge(std::vector<int>&, size_t&);
void	vectorAnalyze(t_info&, std::vector<int>&, size_t);
void	vectorBuildChains(s_state<std::vector<t_group>, std::vector<int> >&, std::vector<int>&);
void	vectorGenerateInsertionOrder(s_state<std::vector<t_group>, std::vector<int> >&);
void	vectorInsertPendingIntoMain(s_state<std::vector<t_group>, std::vector<int> >&);
void	vectorRebuildSequence(s_state<std::vector<t_group>, std::vector<int> >&, std::vector<int>&);
void	vectorInsert(std::vector<int>&, size_t);

void	dequeMerge(std::deque<int>&, size_t&);
void	dequeAnalyze(t_info&, std::deque<int>&, size_t);
void	dequeBuildChains(s_state<std::deque<t_group>, std::deque<int> >&, std::deque<int>&);
void	dequeGenerateInsertionOrder(s_state<std::deque<t_group>, std::deque<int> >&);
void	dequeInsertPendingIntoMain(s_state<std::deque<t_group>, std::deque<int> >&);
void	dequeRebuildSequence(s_state<std::deque<t_group>, std::deque<int> >&, std::deque<int>&);
void	dequeInsert(std::deque<int>&, size_t);

long	getTimeMicroseconds(void);
template <typename Container>
bool	isSorted(Container);

PmergeMe::PmergeMe( void )
{
	return;
}

PmergeMe::PmergeMe(std::string input)
{
	std::string tmp;

	if (input.empty())
		return;

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
		
	for(std::vector<int>::iterator it = _seq.begin(); it != _seq.end() ; it++)
	{
		std::vector<int>::iterator next = it;
		next++;
		if (std::find(next, _seq.end(), *it) != _seq.end())
		{
			std::cout << "Error: duplicates arent allowed" << std::endl;
			_seq.clear();
			break;
		}
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

void	vectorMerge(std::vector<int> &v, size_t &order)
{
	int	tmp;

	if (order > v.size() / 2)
	{
		order /= 2;
		return;
	}	

	for (size_t groups = 1; groups <  v.size() / order; groups += 2)
	{
		if (v[order * groups - 1] > v[order * (groups + 1) - 1])
		{
			for (size_t i = order * groups - order; i < order * groups; i++)
			{
				tmp = v[i];
				v[i] = v[i + order];
				v[i + order] = tmp;
			}
		}
	}
	order *= 2;
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

void	vectorGenerateInsertionOrder(s_state<std::vector<t_group>, std::vector<int> > &state)
{
	std::vector<size_t> Jacobsthal;

	if (state.pending.empty())
		return;

	Jacobsthal.push_back(0);
	Jacobsthal.push_back(1);
	Jacobsthal.push_back(1);
	for (size_t i = 2; Jacobsthal[i] < state.pending.size(); i++)
	{
		Jacobsthal.push_back(Jacobsthal[i] + (2 * Jacobsthal[i - 1]));
	}

	state.insertionOrder.push_back(0);
	for (size_t i = 2; i + 1 < Jacobsthal.size(); i++)
	{
		size_t upper = std::min(Jacobsthal[i + 1], state.pending.size());
		size_t lower = Jacobsthal[i];
		for (size_t j = upper; j > lower; )
		{
			j--;
			state.insertionOrder.push_back(j);
		}
	}
}

void	vectorInsertPendingIntoMain(s_state<std::vector<t_group>, std::vector<int> > &state)
{
	if (state.insertionOrder.empty())
	{
		for (size_t i = 0; i < state.pending.size(); i++)
			state.main.insert(std::upper_bound(state.main.begin(), state.main.end(), state.pending[i], groupCompare), state.pending[i]);
	}
	else
	{
		for (size_t i = 0; i < state.insertionOrder.size(); i++)
		{
			size_t index = state.insertionOrder[i];
			state.main.insert(std::upper_bound(state.main.begin(), state.main.end(), state.pending[index], groupCompare), state.pending[index]);
		}
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

	if (order < 1)
		return;
	vectorAnalyze(state.info, v, order);
	vectorBuildChains(state, v);
	vectorGenerateInsertionOrder(state);
	vectorInsertPendingIntoMain(state);
	if (state.info.hasOddGroup)
		state.main.insert(std::upper_bound(state.main.begin(), state.main.end(), state.oddGroup, groupCompare), state.oddGroup);  
	vectorRebuildSequence(state, v);
	vectorInsert(v, order / 2);
}

void	PmergeMe::vectSort()
{
	size_t				order = 1;
	
	_v = _seq;
	vectorMerge(_v, order);
	vectorInsert(_v, order);
}

void	dequeMerge(std::deque<int> &d, size_t &order)
{
	int	tmp;

	if (order > d.size() / 2)
	{
		order /= 2;
		return;
	}	

	for (size_t groups = 1; groups <  d.size() / order; groups += 2)
	{
		if (d[order * groups - 1] > d[order * (groups + 1) - 1])
		{
			for (size_t i = order * groups - order; i < order * groups; i++)
			{
				tmp = d[i];
				d[i] = d[i + order];
				d[i + order] = tmp;
			}
		}
	}
	order *= 2;
	dequeMerge(d, order);
}

void	dequeAnalyze(t_info &info, std::deque<int> &d, size_t order)
{
	info.order = order;
	info.groupCount = d.size() / info.order;
    info.pairCount = info.groupCount / 2;
    info.remnantStart = info.groupCount * info.order;
    info.hasOddGroup = (info.groupCount % 2 != 0);
}

void	dequeBuildChains(s_state<std::deque<t_group>, std::deque<int> > &state, std::deque<int> &d)
{
	for (size_t pair = 0; pair < state.info.pairCount; pair++)
	{
		t_group b;
		t_group a;
		b.start = (pair * 2) * state.info.order;
    	b.groupRep = d[b.start + state.info.order - 1];
    	a.start = (pair * 2 + 1) * state.info.order;
    	a.groupRep = d[a.start + state.info.order - 1];
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
		state.oddGroup.groupRep = d[state.oddGroup.start + state.info.order - 1];
	}
	for (size_t i = state.info.remnantStart; i < d.size(); i++)
		state.remnant.push_back(d[i]);
}

void	dequeGenerateInsertionOrder(s_state<std::deque<t_group>, std::deque<int> > &state)
{
	std::deque<size_t> Jacobsthal;

	if (state.pending.empty())
		return;

	Jacobsthal.push_back(0);
	Jacobsthal.push_back(1);
	Jacobsthal.push_back(1);
	for (size_t i = 2; Jacobsthal[i] < state.pending.size(); i++)
	{
		Jacobsthal.push_back(Jacobsthal[i] + (2 * Jacobsthal[i - 1]));
	}
	
	state.insertionOrder.push_back(0);
	for (size_t i = 2; i + 1 < Jacobsthal.size(); i++)
	{
		size_t upper = std::min(Jacobsthal[i + 1], state.pending.size());
		size_t lower = Jacobsthal[i];
		for (size_t j = upper; j > lower; )
		{
			j--;
			state.insertionOrder.push_back(j);
		}
	}
}

void	dequeInsertPendingIntoMain(s_state<std::deque<t_group>, std::deque<int> > &state)
{
	if (state.insertionOrder.empty())
	{
		for (size_t i = 0; i < state.pending.size(); i++)
			state.main.insert(std::upper_bound(state.main.begin(), state.main.end(), state.pending[i], groupCompare), state.pending[i]);
	}
	else
	{
		for (size_t i = 0; i < state.insertionOrder.size(); i++)
		{
			size_t index = state.insertionOrder[i];
			state.main.insert(std::upper_bound(state.main.begin(), state.main.end(), state.pending[index], groupCompare), state.pending[index]);
		}
	}
}

void	dequeRebuildSequence(s_state<std::deque<t_group>, std::deque<int> > &state, std::deque<int> &v)
{
	std::deque<int> rebuilt;

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

void	dequeInsert(std::deque<int> &d, size_t order)
{
	s_state<std::deque<t_group>, std::deque<int> > state;

	if (order < 1)
		return;
	dequeAnalyze(state.info, d, order);
	dequeBuildChains(state, d);
	dequeGenerateInsertionOrder(state);
	dequeInsertPendingIntoMain(state);
	if (state.info.hasOddGroup)
		state.main.insert(std::upper_bound(state.main.begin(), state.main.end(), state.oddGroup, groupCompare), state.oddGroup);  
	dequeRebuildSequence(state, d);
	dequeInsert(d, order / 2);
}

void	PmergeMe::dequeSort()
{
	std::deque<int>	d(_seq.begin(), _seq.end());
	size_t				order = 1;

	_d = d;
	dequeMerge(_d, order);
	dequeInsert(_d, order);
}

long getTimeMicroseconds()
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000L + tv.tv_usec);
}

template <typename Container>
bool	isSorted(Container c)
{
	for (size_t i = 0; i < c.size() - 1; i++)
	{
		for (size_t j = i + 1; j < c.size(); j++)
		{
			if (c[i] >= c[j])
				return false;
		}	
	}
	return true;
}

void	PmergeMe::FordJohnson()
{
	long vStart, vEnd, dStart, dEnd;

	if (_seq.empty())
		return;

	vStart = getTimeMicroseconds();
	vectSort();
	vEnd = getTimeMicroseconds();
	dStart = getTimeMicroseconds();
	dequeSort();
	dEnd = getTimeMicroseconds();
	
	std::cout << "Before: ";
	for(std::vector<int>::iterator it = _seq.begin(); it != _seq.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << "\nSorted with std::vector: ";
	for(std::vector<int>::iterator it = _v.begin(); it != _v.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << "\nis sorted: ";
	if (isSorted(_v))
		std::cout << "yes";
	else
		std::cout << "no";
	std::cout << "\nSorted with std::deque: ";
	for(std::deque<int>::iterator it = _d.begin(); it != _d.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << "\nis sorted: ";
	if (isSorted(_d))
		std::cout << "yes";
	else
		std::cout << "no";
	std::cout << "\nTime to process a range of " << _seq.size() << " elements with std::vector: " << vEnd - vStart << " us";
	std::cout << "\nTime to process a range of " << _seq.size() << " elements with std::deque: " << dEnd - dStart << " us";
}

PmergeMe::~PmergeMe( void )
{
	return;
}
