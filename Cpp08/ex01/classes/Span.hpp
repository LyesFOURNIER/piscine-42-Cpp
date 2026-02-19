/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:59:32 by lfournie          #+#    #+#             */
/*   Updated: 2026/02/16 09:53:53 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include "../includes/lib.hpp"

class Span
{
		public:

		Span( void );
		Span( unsigned int N );
		Span( const Span &copy );
		Span &operator=( const Span &copy );
		~Span();
		//GETTERS
			unsigned int getSize( void ) const;
		//
		//MEMBERS FUNCTIONS
			void	addNumber( int n );
			int		shortestSpan( void );
			int		longestSpan( void );
		//
		//EXCEPTIONS
		class ArrayFullException : public std::exception
		{
			public:
			
			const char *what() const throw();
		};
		class NoSpanPossibleException : public std::exception
		{
			public:

			const char *what() const throw();
		};
		//

		private:
		
		int	*_array;
		int	_size;
		int	_remaining;
};

#endif
