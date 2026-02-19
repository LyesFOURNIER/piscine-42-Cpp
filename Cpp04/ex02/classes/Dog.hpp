/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:34:40 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/30 13:19:21 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "../includes/lib.hpp"

class Dog : public Animal
{
	public:

	Dog( void );
	Dog( const Dog &copy );
	Dog &operator=( const Dog &copy );
	~Dog( void );
	//GETTER
	Brain	*getBrain( void ) const;
	//
	//SETTER
	void	setBrain( std::string idea, int id);
	//
	void	makeSound( void ) const;
	
	private:

	Brain *_brain;
};

#endif
