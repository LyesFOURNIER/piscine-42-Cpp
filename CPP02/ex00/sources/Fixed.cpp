/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 09:24:54 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/27 12:34:32 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

Fixed::Fixed( void ): _nbr(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed( const Fixed &copy )
{
	std::cout << "Copy constructor called" << std::endl;
	this->_nbr = copy._nbr;
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
