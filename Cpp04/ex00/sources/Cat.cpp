/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:57:26 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/29 14:57:33 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

Cat::Cat( void )
{
	_type = "Cat";
	std::cout << "Cat class default constructor called" << std::endl;
	return ;
}

Cat::Cat( Cat &copy )
{
	_type = copy._type;
	return;
}

Cat &Cat::operator=( const Cat &copy )
{
	this->_type = copy._type;
	return (*this);
}

Cat::~Cat( void )
{
	std::cout << "Cat class destructor called" << std::endl;
	return ;
}

void Cat::makeSound( void ) const
{
	std::cout << "*meow*" << std::endl;
	return ;
}
