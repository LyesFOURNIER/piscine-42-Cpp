/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:12:00 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/16 11:51:11 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_HPP
# define LIB_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include "../classes/Contact.hpp"
# include "../classes/PhoneBook.hpp"

typedef struct s_param
{
	std::string	phone_number;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	secret;
} t_param;

bool	parameters_check(const char *param_name, std::string parameter, int interuptor);
void	enter_parameters(t_param *Contact_parameters);

#endif
