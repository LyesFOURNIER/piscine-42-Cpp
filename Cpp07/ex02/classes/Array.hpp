/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:06:46 by lfournie          #+#    #+#             */
/*   Updated: 2026/02/11 11:59:18 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include "../includes/lib.hpp"

template <typename Element>
class Array
{
	public:
		Array( void );
		Array( unsigned int n);
		Array( Array &copy );
		Array &operator=( Array &copy );
		Element &operator[](unsigned int i);
		~Array();
	//GETTERS
		unsigned int	getSize( void ) const;
	//
	//EXCEPTIONS
		class InvalidIndexException : public std::exception
		{
			public:
				virtual const char *what( void ) const throw();
		};
	//
	private:
	
		Element *_array;
		unsigned int _size;
	
};

# include "Array.tpp"
#endif

