/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:12:27 by lfournie          #+#    #+#             */
/*   Updated: 2026/02/11 11:59:08 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP
# include "Array.hpp"

template <typename Element>
Array<Element>::Array() : _size(0)
{
	_array = new Element[_size];
	std::cout	<< "Array template class default constructor called" 
				<< std::endl;
	return;
}

template <typename Element>
Array<Element>::Array( unsigned int n ) : _size(n)
{
	std::cout	<< "Array template class constructor called for array size of "
				<< _size
				<< std::endl;
	_array = new Element[_size];
	return;
}

template <typename Element>
Array<Element>::Array( Array &copy ) : _size(copy.getSize())
{
	std::cout	<< "Array template class copy constructor called for array size of "
				<< _size
				<< std::endl;
	_array = new Element[_size];
	if (_size > 0)
	{
		for(unsigned int i = 0; i < _size; i++)
		{
			_array[i] = copy._array[i];
		}	
	}
	return;
}

template <typename Element>
Array<Element> &Array<Element>::operator=( Array &copy )
{
	std::cout	<< "Array template class assigmement operator called for array size of "
				<< _size
				<< std::endl;
	_size = copy.getSize();
	_array = new Element[_size];
	if (_size > 0)
	{
		for(unsigned int i = 0; i < _size; i++)
		{
			_array[i] = copy._array[i];
		}	
	}
	return;
}

template <typename Element>
Element &Array<Element>::operator[]( unsigned int i )
{
	if (_array == NULL || i >= _size)
		throw InvalidIndexException();
	return (_array[i]);
}

template <typename Element>
unsigned int Array<Element>::getSize( void ) const
{
	return (_size);
}

template <typename Element>
const char *Array<Element>::InvalidIndexException::what( void ) const throw()
{
	return("Invalid index");
}

template <typename Element>
Array<Element>::~Array( void )
{
	std::cout	<< "Array template class destructor called" 
				<< std::endl;
	if (_array != NULL)
		delete[] _array;
	return;
}

#endif
