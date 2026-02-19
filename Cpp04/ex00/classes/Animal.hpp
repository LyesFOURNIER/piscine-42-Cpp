/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:16:51 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/29 14:52:50 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "../includes/lib.hpp"

class Animal
{
	public:
	
	Animal( void );
	Animal( Animal &copy );
	Animal &operator=( const Animal &copy );
	virtual ~Animal( void );
	//GETTER
	std::string	getType( void ) const;
	//
	//SETTER
	void	setType( std::string type );
	//
	virtual void	makeSound( void ) const;
	
	protected:

	std::string	_type;
	
};

#endif
