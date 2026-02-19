/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:39:59 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/28 08:39:37 by lfournie         ###   ########.fr       */
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
	//ASSIGNATION
	Fixed 	&operator=	( const Fixed &copy );
	//COMPARISON
	int		operator>	( const Fixed &copy );
	int		operator<	( const Fixed &copy );
	int 	operator>=	( const Fixed &copy );
	int 	operator<=	( const Fixed &copy );
	int 	operator==	( const Fixed &copy );
	int 	operator!=	( const Fixed &copy );
	//ARITHMETIC
	Fixed 	operator+	( const Fixed &copy );
	Fixed 	operator-	( const Fixed &copy );
	Fixed 	operator*	( const Fixed &copy );
	Fixed 	operator/	( const Fixed &copy );
	//INCREMENTATION
	//PRE-INCREMENT
	Fixed 	&operator++	( void );
	//POST-INCREMENT
	Fixed 	operator++	( int );
	//DECREMENTATION
	//PRE-DECREMENT
	Fixed 	&operator--	( void );
	//POST-DECREMENT
	Fixed 	operator--	( int );
	//
	//GETTER
	int		getRawBits	( void ) const;
	//
	//SETTER
	void	setRawBits	( int const raw );
	//
	//MEMBER FUNCTIONS
	float	toFloat		( void ) const;
	int		toInt		( void ) const;
	
	static			Fixed	&max( Fixed &f1, Fixed &f2 );
	static	const	Fixed	&max( const Fixed &f1, const Fixed &f2 );
	static			Fixed	&min( Fixed &f1, Fixed &f2 );
	static	const	Fixed	&min( const Fixed &f1, const Fixed &f2 );

	private:
	
	int					_nbr;
	const static int	_bit_nbr = 8;
	
};
std::ostream &operator<<( std::ostream &stream, const Fixed &copy );

#endif
