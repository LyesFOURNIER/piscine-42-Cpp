/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:48:51 by lfournie          #+#    #+#             */
/*   Updated: 2026/07/07 16:17:49 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_HPP
# define LIB_HPP

# include <iostream>
# include <algorithm>
# include "vector"
# include "deque"
# include <cstdlib>
# include <cstring>
# include "../classes/PmergeMe.hpp"

typedef struct s_info
{
    size_t  order;
    size_t  groupCount;
    size_t  pairCount;
    size_t  remnantStart;
    bool    hasOddGroup;
}   t_info;

typedef struct s_group
{
    size_t  start;
    int     groupRep;
}   t_group;

template <typename groupContainer, typename remnantContainer>
struct s_state
{
    groupContainer      main;
    groupContainer      pending;
    remnantContainer    remnant;
    t_group             oddGroup;
    t_info              info;
    std::vector<size_t> insertionOrder;
};

#endif
