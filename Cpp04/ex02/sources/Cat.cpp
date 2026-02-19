/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:57:26 by lfournie          #+#    #+#             */
/*   Updated: 2025/11/05 08:26:00 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

Cat::Cat( void )
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat class default constructor called" << std::endl;
	return ;
}

Cat::Cat( Cat &copy )
{
	_type = copy._type;
	_brain = new Brain( copy._brain );
	return;
}

Cat &Cat::operator=( const Cat &copy )
{
	this->_type = copy._type;
	return (*this);
}

Cat::~Cat( void )
{
	delete _brain;
	std::cout << "Cat class destructor called" << std::endl;
	return ;
}

Brain	*Cat::getBrain( void ) const
{
	return (this->_brain);
}

void	Cat::setBrain( std::string idea, int id )
{
	this->_brain->setIdea( idea, id );
}

void Cat::makeSound( void ) const
{
	std::cout << "*meow*" << std::endl;
	return ;
}
