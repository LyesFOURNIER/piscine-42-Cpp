/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:19:16 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/16 08:26:53 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

int	main()
{
	std::string tmp;
	PhoneBook 	pb;
	t_param 	Contact_parameters;

	while (1)
	{
		std::cout << "PHONEBOOK : ";
		if (!getline(std::cin, tmp))
			return (1);
		if (tmp == "ADD")
		{
			enter_parameters(&Contact_parameters);
			if (std::cin.eof())
				break ;
			std::cout << "Contact \"" << Contact_parameters.first_name << " "
			<< Contact_parameters.last_name << "\" created successfuly" << std::endl;
			pb.usr_add(&Contact_parameters);
		}
		else if (tmp == "SEARCH")
		{
			pb.usr_search();
			if (std::cin.eof())
				break ;
		}
		else if (tmp == "EXIT")
			break ;
	}
	return (0);
}
