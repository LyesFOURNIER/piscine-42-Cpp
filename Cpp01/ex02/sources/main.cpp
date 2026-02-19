/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:42:57 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/16 13:22:35 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;
	
	std::cout 	<< "The address of \"string\" is: " << &string << std::endl
				<< "The address held by \"stringPTR\" is: " << stringPTR << std::endl
				<< "The address held by \"stringREF\" is: " << &stringREF << std::endl
				<< "The value of \"string\" is: " << string << std::endl
				<< "The value pointed by \"stringPTR\" is: " << *stringPTR << std::endl
				<< "The value pointed by \"stringREF\" is: " << stringREF << std::endl;
	return (0);
}
