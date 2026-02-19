/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:47:23 by lfournie          #+#    #+#             */
/*   Updated: 2026/02/10 08:27:59 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

Serializer::Serializer( void )
{
	std::cout << "Serializer default constuctor called" << std::endl;
	return;
}

Serializer::Serializer( Serializer &copy )
{
	(void)copy;
	std::cout << "Serializer copy constuctor called" << std::endl;
	return;
}

Serializer &Serializer::operator=( const Serializer &copy )
{
	(void)copy;
	std::cout << "Serializer assignement operator called" << std::endl;
	return ( *this );
}

uintptr_t Serializer::serialize( Data *ptr )
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize( uintptr_t raw )
{
	return (reinterpret_cast<Data *>(raw));
}

Serializer::~Serializer( void )
{
	std::cout << "Serializer destructor called" << std::endl;
	return;
}
