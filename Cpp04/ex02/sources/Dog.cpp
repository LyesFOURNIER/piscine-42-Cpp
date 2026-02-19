/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:57:18 by lfournie          #+#    #+#             */
/*   Updated: 2025/11/05 08:22:21 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

Dog::Dog( void )
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Dog class default constructor called" << std::endl;
	return ;
}

Dog::Dog( const Dog &copy )
{
	_type = copy._type;
	_brain = new Brain( copy._brain );
	return;
}

Dog &Dog::operator=( const Dog &copy )
{
	this->_type = copy._type;
	return (*this);
}

Dog::~Dog( void )
{
	delete _brain;
	std::cout << "Dog class destructor called" << std::endl;
	return ;
}

Brain	*Dog::getBrain( void ) const
{
	return (this->_brain);
}

void	Dog::setBrain( std::string idea, int id )
{
	this->_brain->setIdea( idea, id );
}

void Dog::makeSound( void ) const
{
	std::cout << "*bark*" << std::endl;
	return ;
}
