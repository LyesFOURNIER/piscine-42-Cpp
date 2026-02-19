/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 09:55:01 by lfournie          #+#    #+#             */
/*   Updated: 2026/02/16 13:23:30 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include "../includes/lib.hpp"

template <typename T, class container=std::deque<T> >
class MutantStack : public std::stack<T>
{
	public :
	
		MutantStack( void );
		MutantStack( const MutantStack &copy );
		MutantStack &operator=( const MutantStack &copy );
		~MutantStack();
		typedef typename container::iterator iterator;
	//MEMBERS FUNCTIONS
		iterator begin( void );
		iterator end( void );
	//
};

# include "MutantStack.tpp"

#endif
