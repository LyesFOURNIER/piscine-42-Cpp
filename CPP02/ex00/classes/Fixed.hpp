/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:47:03 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/28 13:25:03 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include "../includes/lib.hpp"

class Fixed
{
	public:
	
	Fixed( void );
	Fixed( const Fixed &copy );
	~Fixed( void );
	//ASSIGNMENT
	Fixed &operator = ( const Fixed &copy );
	//
	//GETTER
	int		getRawBits( void ) const;
	//
	//SETTER
	void	setRawBits( int const raw );
	//
	
	private:

	int					_nbr;
	const static int	_bit_nbr = 8;
	
};

#endif
