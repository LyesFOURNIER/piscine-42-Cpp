/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:44:24 by lfournie          #+#    #+#             */
/*   Updated: 2025/11/10 09:17:17 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

FragTrap::FragTrap( void )
{
	std::cout << FRAGTRAP << " default constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap( std::string name )
{
	this->_name = name;
	std::cout	<< FRAGTRAP << " " << this->_name 
				<< ": Constructor called"
				<< std::endl;
	return ;
}

FragTrap::FragTrap( FragTrap &copy )
{
	this->setName( copy.getName() );
	this->setHP( copy.getHP() );
	this->setEP( copy.getEP() );
	this->setAD( copy.getAD() );
	return ;
}

FragTrap &FragTrap::operator=( const FragTrap &copy )
{
	this->setName( copy.getName() );
	this->setHP( copy.getHP() );
	this->setEP( copy.getEP() );
	this->setAD( copy.getAD() );
	return (*this);
}

FragTrap::~FragTrap( void )
{
	if (this->_name == "")
	{	
		std:: cout << FRAGTRAP << " default destructor called" << std::endl;
		return ;
	}
	std::cout	<< FRAGTRAP << " " << this->_name
				<< ": Destructor called" << std::endl;
	return ;
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << FRAGTRAP << " " << this->_name << " has demanded a high five!" << std::endl;
	return ;
}

void	FragTrap::attack( const std::string &target )
{
	if (this->_hp == 0)
	{
		std::cout 	<< FRAGTRAP << " " << this->_name
					<< " is knocked out and cannot attack!"
					<< std::endl;
		return ;
	}
	if (this->_ep > 0)
	{
		std::cout	<< FRAGTRAP << " " << this->_name
					<< " attacks " << target
					<< ", causing " << this->_ad << " points of damage!"
					<< std::endl;
		this->_ep--;
		std:: cout	<< FRAGTRAP << " " << this->_name
					<< " energy remaining: " << this->_ep << std::endl;
		return ;
	}
	std::cout << FRAGTRAP << " " << this->_name << " is out of energy!" <<  std::endl;
	return ;
}
