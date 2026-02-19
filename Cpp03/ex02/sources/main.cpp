/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 09:18:38 by lfournie          #+#    #+#             */
/*   Updated: 2025/11/10 09:22:59 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

int	main()
{
	ClapTrap Bob( "Bob" );
	ClapTrap Kevin( "Kevin" );
	ScavTrap Marcus( "Marcus" );
	FragTrap Billy( "Billy" );

	Bob.attack( "Kevin" );
	Kevin.takeDamage( Bob.getAD() );
	Kevin.beRepaired( 10 );
	Kevin.attack( "Bob" );
	Bob.takeDamage( Kevin.getAD() );
	Bob.beRepaired( 10 );
	Marcus.attack( "Bob" );
	Bob.takeDamage( Marcus.getAD() );
	Marcus.attack( "Kevin" );
	Kevin.takeDamage( Marcus.getAD() );
	Marcus.guardGate();
	Billy.attack( "Bob" );
	Bob.takeDamage( Billy.getAD() );
	Billy.attack( "Kevin" );
	Kevin.takeDamage( Billy.getAD() );
	Billy.highFivesGuys();

	return (0);
}
