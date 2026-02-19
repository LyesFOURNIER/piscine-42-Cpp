/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:24:13 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/30 08:01:49 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

WrongCat::WrongCat( void )
{
	_type = "WrongCat";
	std::cout << "WrongCat class default constructor called" << std::endl;
	return ;
}

WrongCat::WrongCat( WrongCat &copy )
{
	_type = copy._type;
	return;
}

WrongCat &WrongCat::operator=( const WrongCat &copy )
{
	this->_type = copy._type;
	return (*this);
}

WrongCat::~WrongCat( void )
{
	std::cout << "WrongCat class destructor called" << std::endl;
	return ;
}

void WrongCat::makeSound( void ) const
{
	std::cout << "*M I A O U*" << std::endl;
	return ;
}

