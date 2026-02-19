/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:57:34 by lfournie          #+#    #+#             */
/*   Updated: 2025/11/11 08:55:26 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

Brain::Brain( void )
{
	std::cout << "Brain default constructor called" << std::endl;
	return ;
}

Brain::Brain( const Brain *copy)
{
	int	i = 0;
	
	while (i < 100)
	{
		_ideas[i] = copy->_ideas[i];
		i++;
	}
	return ;
}

Brain &Brain::operator=( const Brain &copy )
{
	int	i = 0;
	
	while (i < 100)
	{
		_ideas[i] = copy._ideas[i];
		i++;
	}
	return (*this);
}

Brain::~Brain( void )
{
	std::cout << "Brain destructor called" << std::endl;
	return ;
}

std::string Brain::getIdea( int	id ) const
{
	return(this->_ideas[id]);
}

void	Brain::setIdea( std::string idea, int id )
{
	if (id < 0 || id > 100)
	{
		std::cout << "id must be between 0 and 100" << std::endl;
		return ;
	}
	this->_ideas[id] = idea;
	return ;
}
