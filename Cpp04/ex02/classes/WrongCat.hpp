/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:23:27 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/29 15:03:33 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "../includes/lib.hpp"

class WrongCat : public WrongAnimal
{
	public:

	WrongCat( void );
	WrongCat( WrongCat &copy );
	WrongCat &operator=( const WrongCat &copy );
	~WrongCat( void );
	
	void	makeSound( void ) const;

};

#endif

