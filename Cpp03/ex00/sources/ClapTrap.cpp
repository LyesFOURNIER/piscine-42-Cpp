/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 09:18:31 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/29 10:16:13 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

ClapTrap::ClapTrap( void ): _hp(0), _ep(0), _ad(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap( std::string name ): _hp(10), _ep(10) , _ad(0)
{
	this->_name = name;
	std::cout << this->_name << ": Constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap( ClapTrap &copy )
{
	this->setName( copy.getName() );
	this->setHP( copy.getHP() );
	this->setEP( copy.getEP() );
	this->setAD( copy.getAD() );
	return ;
}

ClapTrap &ClapTrap::operator=( const ClapTrap &copy )
{
	this->setName( copy.getName() );
	this->setHP( copy.getHP() );
	this->setEP( copy.getEP() );
	this->setAD( copy.getAD() );
	return (*this);
}

ClapTrap::~ClapTrap( void )
{
	if (this->_name == "")
	{	
		std:: cout << "Default destructor called" << std::endl;
		return ;
	}
	std::cout << this->_name << ": Destructor called" << std::endl;
	return ;
}

std::string ClapTrap::getName( void ) const
{
	return (this->_name);
}

unsigned int ClapTrap::getHP( void ) const
{
	return (this->_hp);
}

unsigned int ClapTrap::getEP( void ) const
{
	return (this->_ep);
}

unsigned int ClapTrap::getAD( void ) const
{
	return (this->_ad);
}

void	ClapTrap::setName( std::string name )
{
	this->_name = name;
	return ;
}

void	ClapTrap::setHP( unsigned int hp )
{
	this->_hp = hp;
	return ;
}

void	ClapTrap::setEP( unsigned int ep )
{
	this->_ep = ep;
	return ;
}

void	ClapTrap::setAD( unsigned int ad )
{
	this->_ad = ad;
	return ;
}

void	ClapTrap::attack( const std::string &target )
{
	if (this->_hp == 0)
	{
		std::cout 	<< "ClapTrap " << this->_name
					<< " is knocked out and cannot attack!"
					<< std::endl;
		return ; 
	}
	if (this->_ep > 0)
	{
		std::cout	<< "ClapTrap " << this->_name
					<< " attacks " << target
					<< ", causing " << this->_ad << " points of damage!"
					<< std::endl;
		this->_ep--;
		std:: cout	<< "ClapTrap " << this->_name
					<< " energy remaining: " << this->_ep << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " is out of energy!" <<  std::endl;
	return ;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (this->_hp == 0)
	{
		std::cout 	<< "ClapTrap " << this->_name
					<< " is already knocked out!"
					<< std::endl;
		return ;
	}
	std::cout	<< "ClapTrap " << this->_name
				<< " took " << amount << " points of damage!"
				<< std::endl;
	if (amount > this->_hp)
		this->_hp = 0;
	else
		this->_hp -= amount;
	std:: cout	<< "ClapTrap " << this->_name
				<< " health remaining: " << this->_hp << std::endl;
	return ;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (this->_hp == 0)
	{
		std::cout 	<< "ClapTrap " << this->_name
					<< " is knocked out and cannot repair itself!"
					<< std::endl;
		return ;
	}
	if (this->_ep > 0)
	{
		std::cout	<< "ClapTrap " << this->_name
					<< " repair itself for " << amount << " health point!"
					<< std::endl;
		this->_ep--;
		this->_hp += amount;
		std:: cout	<< "ClapTrap " << this->_name
					<< " health remaining: " << this->_hp << std::endl
					<< "ClapTrap " << this->_name
					<< " energy remaining: " << this->_ep << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " is out of energy!" <<  std::endl;
	return ;
}
