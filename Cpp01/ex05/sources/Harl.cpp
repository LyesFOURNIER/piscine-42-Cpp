/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 08:11:47 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/28 13:20:41 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

Harl::Harl( void )
{

	_level_tab[0] = "DEBUG";
	_level_tab[1] = "INFO";
	_level_tab[2] = "WARNING";
	_level_tab[3] = "ERROR";
	
	_exec_tab[0] = &Harl::debug;
	_exec_tab[1] = &Harl::info;
	_exec_tab[2] = &Harl::warning;
	_exec_tab[3] = &Harl::error;
	
	return ;
}

Harl::~Harl( void )
{
	return ;
}

void	Harl::complain( std::string level )
{
	int	i = 0;
	while(i < 4)
	{
		if ( level == this->_level_tab[i] )
		{
			(this->*_exec_tab[i])();
			return ;
		}
		i++;
	}
	std::cout << "level not recognized" << std::endl;
	return ;
}

void	Harl::debug( void )
{
	std::cout << "Debug message" << std::endl;
	return ;
}

void	Harl::info( void )
{
	std::cout << "Info message" << std::endl;
	return ;
}

void	Harl::warning( void )
{
	std::cout << "Warning message" << std::endl;
	return ;
}

void	Harl::error( void )
{
	std::cout << "Error message" << std::endl;
	return ;
}
