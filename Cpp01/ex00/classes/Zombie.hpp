/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 08:57:25 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/28 13:14:10 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include "../includes/lib.hpp"

class Zombie
{
	public:
	
	Zombie(void);
	Zombie(Zombie &copy);
	~Zombie(void);
	//GETTER
	std::string getname( void ) const;
	//
	//SETTER
	void		setname( std::string name );
	//
	void		announce( void ) const;
	
	private:

	std::string	name;
	
};

#endif
