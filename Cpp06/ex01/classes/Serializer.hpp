/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:40:41 by lfournie          #+#    #+#             */
/*   Updated: 2026/02/16 09:15:45 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include "../includes/lib.hpp"

class	Serializer
{
	public:
	
	//MEMBER FUNCTIONS
		static uintptr_t serialize( Data *ptr );
		static Data *deserialize( uintptr_t raw );
	//
	private:

		Serializer( void );
		Serializer( Serializer &copy );
		Serializer &operator=( const Serializer &copy );
		~Serializer();
};

#endif
