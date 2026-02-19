/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 08:43:00 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/15 14:34:34 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

bool	parameters_check(const char *param_name, std::string parameter, int interuptor)
{
	if (std::cin.eof())
			return (false);
	if (parameter.empty())
	{
		std::cout << "this field cannot be empty" << std::endl;
		return (false);
	}
	if (interuptor == 0)
	{
		for (int j = 0; parameter[j]; j++)
		{
			if (!std::isalpha(parameter[j]))
			{
				std::cout << param_name << " should only contain letters" << std::endl;
				return (false);
			}
		}
		return (true);
	}
	else if (interuptor == 1)
	{
		for (int j = 0; parameter[j]; j++)
		{
			if (!std::isdigit(parameter[j]) && parameter[0] != '+')
			{
				std::cout << param_name << " should only contain numbers" << std::endl;
				return (false);
			}
		}
		return (true);
	}
	return(true);
}

void	enter_parameters(t_param *Contact_parameters)
{
	int			i = 0;
	std::string	parameter;

	while (i < 5)
	{
		
		switch (i)
		{	
			case (0):
				std::cout << "Enter new contact first name: ";
				getline(std::cin, parameter);
				if (parameters_check("first name", parameter, 0))
				{
					Contact_parameters->first_name = parameter;
					i++;
				}
				break;
			case (1):	
				std::cout << "Enter new contact last name: ";
				getline(std::cin, parameter);
				if (parameters_check("last name", parameter, 0))
				{
					Contact_parameters->last_name = parameter;
					i++;
				}
				break;
			case (2):	
				std::cout << "Enter new contact nickname: ";
				getline(std::cin, parameter);
				if (parameters_check("nickname", parameter, 0))
				{
					Contact_parameters->nickname = parameter;
					i++;
				}
				break;
			case (3):	
				std::cout << "Enter new contact phone number: ";
				getline(std::cin, parameter);
				if (parameters_check("phone number", parameter, 1))
				{
					Contact_parameters->phone_number = parameter;
					i++;
				}
				break;
			case (4):
				std::cout << "Enter new contact darkest secret: ";
				getline(std::cin, parameter);
				if (parameters_check("darkest secret", parameter, 0))
				{
					Contact_parameters->secret = parameter;
					i++;
				}
				break;
		}
		if (std::cin.eof())
			break ;
	}
}
