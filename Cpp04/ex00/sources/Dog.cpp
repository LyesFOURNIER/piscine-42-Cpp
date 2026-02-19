/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:57:18 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/29 14:57:35 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

Dog::Dog( void )
{
	_type = "Dog";
	std::cout << "Dog class default constructor called" << std::endl;
	return ;
}

Dog::Dog( Dog &copy )
{
	_type = copy._type;
	return;
}

Dog &Dog::operator=( const Dog &copy )
{
	this->_type = copy._type;
	return (*this);
}

Dog::~Dog( void )
{
	std::cout << "Dog class destructor called" << std::endl;
	return ;
}

void Dog::makeSound( void ) const
{
	std::cout << "*bark*" << std::endl;
	return ;
}
