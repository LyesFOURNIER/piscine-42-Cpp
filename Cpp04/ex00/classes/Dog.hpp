/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:34:40 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/29 14:55:23 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "../includes/lib.hpp"

class Dog : public Animal
{
	public:

	Dog( void );
	Dog( Dog &copy );
	Dog &operator=( const Dog &copy );
	~Dog( void );

	void	makeSound( void ) const;
	
};

#endif
