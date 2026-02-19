/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:34:50 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/29 14:55:19 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "../includes/lib.hpp"

class Cat : public Animal
{
	public:

	Cat( void );
	Cat( Cat &copy );
	Cat &operator=( const Cat &copy );
	~Cat( void );

	void	makeSound( void ) const;
	
};

#endif
