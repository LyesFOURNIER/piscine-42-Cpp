/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:23:38 by lfournie          #+#    #+#             */
/*   Updated: 2025/11/05 08:27:11 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

Animal::Animal( void )
{
	std::cout << "Animal class default constructor called" << std::endl;
	return ;
}

Animal::Animal( Animal &copy )
{
	this->_type = copy._type;
	return ;
}

Animal &Animal::operator=( const Animal &copy )
{
	this->_type = copy._type;
	return (*this);
}

Animal::~Animal( void )
{
	std::cout << "Animal class destructor called" << std::endl;
	return ;
}

std::string	Animal::getType( void ) const
{
	return (this->_type);
}

void	Animal::setType( std::string type )
{
	this->_type = type;
	return ;
}

void Animal::makeSound( void ) const
{
	std::cout << "Wrong sound!" << std::endl;
	return ;
}

