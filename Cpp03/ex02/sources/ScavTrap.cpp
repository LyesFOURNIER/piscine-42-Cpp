/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 10:35:39 by lfournie          #+#    #+#             */
/*   Updated: 2025/11/10 08:30:37 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

ScavTrap::ScavTrap( void )
{
	std::cout	<< SCAVTRAP
				<< " default constructor called"
				<< std::endl;
	return ;
}

ScavTrap::ScavTrap( std::string name )
{
	this->_name = name;
	std::cout 	<< SCAVTRAP << " " << this->_name 
				<< ": Constructor called" 
				<< std::endl;
	return ;
}

ScavTrap::ScavTrap( ScavTrap &copy )
{
	this->setName( copy.getName() );
	this->setHP( copy.getHP() );
	this->setEP( copy.getEP() );
	this->setAD( copy.getAD() );
	return ;
}

ScavTrap &ScavTrap::operator=( const ScavTrap &copy )
{
	this->setName( copy.getName() );
	this->setHP( copy.getHP() );
	this->setEP( copy.getEP() );
	this->setAD( copy.getAD() );
	return (*this);
}

ScavTrap::~ScavTrap( void )
{
	if (this->_name == "")
	{	
		std:: cout	<< SCAVTRAP
					<< " default destructor called" 
					<< std::endl;
		return ;
	}
	std::cout 	<< SCAVTRAP 
				<< " "
				<< this->_name 
				<< ": Destructor called"
				<< std::endl;
	return ;
}

void	ScavTrap::guardGate( void )
{
	std::cout 	<< SCAVTRAP
				<< " " 
				<< this->_name
				<< " has entered Gatekeeper mode!"
				<< std::endl;
	return ;
}

void	ScavTrap::attack( const std::string &target )
{
	if (this->_hp == 0)
	{
		std::cout 	<< SCAVTRAP
					<< " " 
					<< this->_name
					<< " is knocked out and cannot attack!"
					<< std::endl;
		return ;
	}
	if (this->_ep > 0)
	{
		std::cout	<< SCAVTRAP << " " << this->_name 
					<< " attacks " << target
					<< ", causing " << this->_ad
					<< " points of damage!"
					<< std::endl;
		this->_ep--;
		std:: cout	<< SCAVTRAP << " " << this->_name
					<< " energy remaining: " << this->_ep 
					<< std::endl;
		return ;
	}
	std::cout	<< SCAVTRAP << " " << this->_name 
				<< " is out of energy!"
				<<  std::endl;
	return ;
}
