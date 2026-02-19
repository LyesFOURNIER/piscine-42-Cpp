/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:40:39 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/28 08:43:58 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

Fixed::Fixed( void )
{
	this->_nbr = 0;
	// std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed( const Fixed &copy )
{
	// std::cout << "Copy constructor called" << std::endl;
	this->_nbr = copy._nbr;
	return ;
}

Fixed::Fixed( const float nbr )
{
	// std::cout << "Float constructor called" << std::endl;
	this->_nbr = ( roundf( nbr * ( 1 << this->_bit_nbr ) ) );
	return ;
}

Fixed::Fixed( const int nbr )
{
	// std::cout << "Int constructor called" << std::endl;
	this->_nbr = ( nbr << this->_bit_nbr );
	return ;
}


Fixed::~Fixed( void )
{
	// std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed	&Fixed::operator=( const Fixed &copy )
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_nbr = copy.getRawBits();
	return (*this);
}

int	Fixed::operator>( const Fixed &copy )
{
	if (this->_nbr > copy._nbr)
		return (1);
	return (0);
}

int	Fixed::operator<( const Fixed &copy )
{
	if (this->_nbr < copy._nbr)
		return (1);
	return (0);
}
int	Fixed::operator>=( const Fixed &copy )
{
	if (this->_nbr >= copy._nbr)
		return (1);
	return (0);
}

int	Fixed::operator<=( const Fixed &copy )
{
	if (this->_nbr >= copy._nbr)
		return (1);
	return (0);
}

int	Fixed::operator==( const Fixed &copy )
{
	if (this->_nbr == copy._nbr)
		return (1);
	return (0);	
}

int	Fixed::operator!=( const Fixed &copy )
{
	if (this->_nbr != copy._nbr)
		return (1);
	return (0);
}

Fixed	Fixed::operator+( const Fixed &copy )
{
	return (this->toFloat() + copy.toFloat());
}

Fixed	Fixed::operator-( const Fixed &copy )
{
	return (this->toFloat() - copy.toFloat());
}

Fixed	Fixed::operator*( const Fixed &copy )
{
	return (this->toFloat() * copy.toFloat());
}

Fixed	Fixed::operator/( const Fixed &copy )
{
	return (this->toFloat() / copy.toFloat());
}

Fixed	&Fixed::operator++( void )
{
	this->_nbr += 1;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed tmp = *this;
	this->_nbr += 1;
	return (tmp);
}

Fixed	&Fixed::operator--( void )
{
	this->_nbr -= 1;
	return (*this);
}

Fixed	Fixed::operator--( int )
{
	Fixed tmp = *this;
	this->_nbr -= 1;
	return (tmp);
}

std::ostream &operator<<( std::ostream &stream, const Fixed &Fixed )
{
	stream << Fixed.toFloat();
	return (stream);
}

float	Fixed::toFloat( void ) const
{
	return ( ( float ) this->_nbr / ( float ) ( 1 << this->_bit_nbr ) );
}

int		Fixed::toInt( void ) const
{
	return ( this->_nbr >> this->_bit_nbr );
}

int	Fixed::getRawBits( void ) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_nbr);
}

void	Fixed::setRawBits( int const raw )
{
	this->_nbr = raw;
	return ;
}

Fixed	&Fixed::max( Fixed &f1, Fixed &f2 )
{
	if (f1._nbr > f2._nbr)
		return (f1);
	return (f2);
}

const Fixed &Fixed::max( const Fixed &f1, const Fixed &f2 )
{
	if (f1._nbr > f2._nbr)
		return (f1);
	return (f2);
}

Fixed	&Fixed::min( Fixed &f1, Fixed &f2 )
{
	if (f1._nbr > f2._nbr)
		return (f2);
	return (f1);
}

const Fixed &Fixed::min( const Fixed &f1, const Fixed &f2 )
{
	if (f1._nbr > f2._nbr)
		return (f2);
	return (f1);
}
