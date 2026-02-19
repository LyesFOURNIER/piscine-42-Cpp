/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 09:52:10 by lfournie          #+#    #+#             */
/*   Updated: 2025/11/06 08:41:41 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

Fixed::Fixed( void )
{
	this->_nbr = 0;
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed( const Fixed &copy )
{
	std::cout << "Copy constructor called" << std::endl;
	this->_nbr = copy._nbr;
	return ;
}

Fixed::Fixed( const float nbr )
{
	std::cout << "Float constructor called" << std::endl;
	this->_nbr = ( roundf( nbr * ( 1 << this->_bit_nbr ) ) );
	return ;
}

Fixed::Fixed( const int nbr )
{
	std::cout << "Int constructor called" << std::endl;
	this->_nbr = ( nbr << this->_bit_nbr );
	return ;
}

Fixed	&Fixed::operator=( const Fixed &copy )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_nbr = copy.getRawBits();
	return (*this);
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
	return ;
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
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_nbr);
}

void	Fixed::setRawBits( int const raw )
{
	this->_nbr = raw;
	return ;
}
