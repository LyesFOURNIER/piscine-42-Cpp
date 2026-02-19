/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:15:31 by lfournie          #+#    #+#             */
/*   Updated: 2026/02/10 08:31:04 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

int	main( void )
{
	Data data;
	Data *data_ptr = &data;
	
	data.data1 = 1;
	data.data2 = 'c';
	data.data3 = "bonjour";
	std::cout << "before serialization: "<< data_ptr << "\n";
	uintptr_t ptr = Serializer::serialize( &data );
	data_ptr = Serializer::deserialize(ptr);
	std::cout << "after deserialization: "<< data_ptr << std::endl;
	return (0);
}
