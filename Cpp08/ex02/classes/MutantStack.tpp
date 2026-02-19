/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 11:21:32 by lfournie          #+#    #+#             */
/*   Updated: 2026/02/16 13:37:33 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP
# include "MutantStack.hpp"

template <typename T, class container>
MutantStack<T, container>::MutantStack( void )
{
	std::cout	<< "MutantStack template class default constructot called"
				<< std::endl;
	return;
}

template <typename T, class container>
MutantStack<T, container>::MutantStack( const MutantStack &copy )
{
	(void)copy;
	return;
}

template <typename T, class container>
MutantStack<T, container> &MutantStack<T, container>::operator=( const MutantStack &copy)
{
	(void)copy;
	return(*this);
}

template <typename T, class container>
typename container::iterator MutantStack<T, container>::begin( void )
{
	return(this->c.begin());
}

template <typename T, class container>
typename container::iterator MutantStack<T, container>::end( void )
{
	return(this->c.end());
}

template <typename T, class container>
MutantStack<T, container>::~MutantStack( void )
{
	std::cout	<< "MutantStack template class destructor called"
				<< std::endl;
	return;
}

#endif
