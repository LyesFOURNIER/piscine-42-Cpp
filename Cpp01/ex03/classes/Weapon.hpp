/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:40:34 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/21 13:38:12 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include "../includes/lib.hpp"

class Weapon
{
	public:

	Weapon	( void );
	Weapon	( const std::string &type );
	~Weapon	( void );
	
	//GETTER
	const std::string	&getType( void ) const;
	//
	//SETTER
	void		setType( const std::string &type );
	//
	private:
	
	std::string	_type;
	
};


#endif
