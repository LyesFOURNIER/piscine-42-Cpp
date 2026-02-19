/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 10:35:29 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/29 10:19:51 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "../includes/lib.hpp"

class ScavTrap : public ClapTrap
{
	public:

	ScavTrap( void );
	ScavTrap( std::string name );
	ScavTrap( ScavTrap &copy );
	ScavTrap &operator=( const ScavTrap &copy );
	~ScavTrap( void );
	
	void	guardGate( void );
	void	attack( const std::string &target );

	private:
	
};

#endif

