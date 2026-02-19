/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:21:37 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/29 14:54:28 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

WrongAnimal::WrongAnimal( void )
{
	std::cout << "WrongAnimal class default constructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal( WrongAnimal &copy )
{
	this->_type = copy._type;
	return ;
}

WrongAnimal &WrongAnimal::operator=( const WrongAnimal &copy )
{
	this->_type = copy._type;
	return (*this);
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "WrongAnimal class destructor called" << std::endl;
	return ;
}

std::string	WrongAnimal::getType( void ) const
{
	return (this->_type);
}

void	WrongAnimal::setType( std::string type )
{
	this->_type = type;
	return ;
}

void WrongAnimal::makeSound( void ) const
{
	std::cout << "Something's wrong with this cat" << std::endl;
	return ;
}
