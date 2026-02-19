/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 09:18:18 by lfournie          #+#    #+#             */
/*   Updated: 2025/11/06 10:22:58 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include "../includes/lib.hpp"

class ClapTrap
{
	public:
	
	ClapTrap( void );
	ClapTrap( std::string name );
	ClapTrap( ClapTrap &copy );
	ClapTrap &operator=( const ClapTrap &copy );
	~ClapTrap( void );
	
	//GETTER
	std::string		getName( void ) const;
	unsigned int	getHP( void ) const;
	unsigned int	getEP( void ) const;
	unsigned int	getAD( void ) const;
	//
	//SETTER
	void	setName( std::string name );
	void	setHP( unsigned int hp );
	void	setEP( unsigned int ep );
	void	setAD( unsigned int ad );
	//
	void	attack( const std::string &target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );
	
	protected:
	
	std::string		_name;
	unsigned int	_hp;
	unsigned int	_ep;
	unsigned int	_ad;
	
};

#endif
