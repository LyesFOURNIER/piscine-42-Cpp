/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 10:59:32 by lfournie          #+#    #+#             */
/*   Updated: 2026/04/28 11:15:23 by lfournie         ###   ########.fr       */
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
			int		shortestSpan( void ) const;
			int		longestSpan( void ) const;
			template <typename Iterator>
        	void addRange(Iterator start, Iterator end)
        	{
				int i = 0;
            	for (Iterator it = start; it != end; ++it)
            	{
                	if (!_remaining)
                	    throw ArrayFullException();
                	_array[i++] = *it;
					_remaining--;
            	}
        	}
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
		unsigned int	_size;
		unsigned int	_remaining;
};

#endif
