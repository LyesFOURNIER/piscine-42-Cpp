/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:20:26 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/29 14:58:39 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include "../includes/lib.hpp"

class WrongAnimal
{
	public:
	
	WrongAnimal( void );
	WrongAnimal( WrongAnimal &copy );
	WrongAnimal &operator=( const WrongAnimal &copy );
	virtual ~WrongAnimal( void );
	//GETTER
	std::string	getType( void ) const;
	//
	//SETTER
	void	setType( std::string type );
	//
	void	makeSound( void ) const;
	
	protected:

	std::string	_type;
	
};

#endif
