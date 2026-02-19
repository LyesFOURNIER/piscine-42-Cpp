/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:43:10 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/29 10:20:00 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "../includes/lib.hpp"

class FragTrap : public ClapTrap
{
	public:

	FragTrap( void );
	FragTrap( std::string name );
	FragTrap( FragTrap &copy );
	FragTrap &operator=( const FragTrap &copy );
	~FragTrap( void );
	
	void	highFivesGuys( void );
	void	attack( const std::string &target );

	private:
	
};

#endif
