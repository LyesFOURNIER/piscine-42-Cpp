/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:30:52 by lfournie          #+#    #+#             */
/*   Updated: 2026/02/16 09:52:48 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

Span::Span( void ) : _size(0)
{
	std::cout << "Span class default constructor called" << std::endl; 
	_array = new int[_size];
	_remaining = _size;
	return;
}

Span::Span( unsigned int N ) : _size(N)
{
	std::cout	<< "Span class constructor called for array size of "
				<< _size
				<< std::endl;
	_array = new int[_size];
	_remaining = _size;
	return;
}

Span::Span( const Span &copy ) : _size(copy.getSize())
{
	std::cout	<< "Span class copy constructor called for array size of "
				<< _size
				<< std::endl;
	_array = new int[_size];
	_remaining = copy._remaining;
	if (_size > 0)
	{
		for(int i = 0; i < _size; i++)
		{
			_array[i] = copy._array[i];
		}
	}
	return;
}

Span &Span::operator=( const Span &copy )
{
	std::cout	<< "Span class assignement operator called for array size of "
				<< _size
				<< std::endl;
	_size = copy.getSize();
	_array = new int[_size];
	_remaining = copy._remaining;
	if (_size > 0)
	{
		for(int i = 0; i < _size; i++)
		{
			_array[i] = copy._array[i];
		}
	}
	return(*this);
}

unsigned int Span::getSize( void ) const
{
	return (_size);
}

void	Span::addNumber( int n )
{
	if (!_remaining)
		throw ArrayFullException();
	_array[_size - _remaining] = n;
	std::cout	<< "Number successfuly added in array at index "
				<< _size - _remaining
				<< std::endl;
	_remaining--;
	return;
}

int		Span::shortestSpan( void )
{
	std::vector<int> tmp;
	
	if (_size < 2)
		throw NoSpanPossibleException();
	for (int i = 0; i <_size; i++)
	{
		tmp.push_back(_array[i]);
	}
	sort(tmp.begin(), tmp.end());
	int res = tmp[1] - tmp[0];
	for (int i = 1; i < _size - 1; i++)
	{
		if ((tmp[i + 1] - tmp[i]) < res)
			res = tmp[i + 1] - tmp[i];
	}
	return (res);
}

int		Span::longestSpan( void )
{
	std::vector<int> tmp;
	
	if (_size < 2)
		throw NoSpanPossibleException();
	for (int i = 0; i <_size; i++)
	{
		tmp.push_back(_array[i]);
	}
	sort(tmp.begin(), tmp.end());
	int res = tmp[_size - 1] - tmp[0];
	return(res);
}

const char	*Span::ArrayFullException::what( void ) const throw()
{
	return ("No empty space remaining in array\n");
}

const char	*Span::NoSpanPossibleException::what( void ) const throw()
{
	return ("No span can be found\n");
}

Span::~Span( void )
{
	std::cout << "Span class destructor called" << std::endl;
	if (_array != NULL)
		delete[] _array;
	return;
}
