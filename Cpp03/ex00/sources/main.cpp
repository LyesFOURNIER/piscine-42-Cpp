/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 09:18:38 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/28 10:24:14 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

int	main()
{
	ClapTrap Bob( "Bob" );
	ClapTrap Kevin( "Kevin" );

	Bob.attack( "Kevin" );
	Kevin.takeDamage( Bob.getAD() );
	Kevin.beRepaired( 1 );
	Kevin.attack( "Bob" );
	Bob.takeDamage( Kevin.getAD() );
	Bob.beRepaired( 1 );

	return (0);
}
