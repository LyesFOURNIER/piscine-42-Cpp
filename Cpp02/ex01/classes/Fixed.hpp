/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 09:51:29 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/28 13:28:09 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include "../includes/lib.hpp"

class Fixed
{
	public:
	
	Fixed( void );
	Fixed( const int );
	Fixed( const float );
	Fixed( const Fixed &copy );
	~Fixed( void );
	//ASSIGNMENT
	Fixed &operator= ( const Fixed &copy );
	//
	//GETTER
	int		getRawBits( void ) const;
	//
	//SETTER
	void	setRawBits( int const raw );
	//
	float	toFloat( void ) const;
	int		toInt( void ) const;
	
	private:
	
	int					_nbr;
	const static int	_bit_nbr = 8;
	
};
std::ostream &operator<<( std::ostream &stream, const Fixed &copy );

#endif
