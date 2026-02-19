/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:16:18 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/16 08:33:14 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../classes/PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->counter = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void PhoneBook::usr_add(t_param *Contact_parameters)
{
	this->repertory[this->counter % 8].set_contact_id(this->counter % 8);
	this->repertory[this->counter % 8].set_first_name(Contact_parameters->first_name);
	this->repertory[this->counter % 8].set_last_name(Contact_parameters->last_name);
	this->repertory[this->counter % 8].set_nickname(Contact_parameters->nickname);
	this->repertory[this->counter % 8].set_phone_number(Contact_parameters->phone_number);
	this->repertory[this->counter % 8].set_secret(Contact_parameters->secret);
	this->counter++;
	return ;
}

void PhoneBook::usr_search()
{
	int 		i = 0;
	std::string index;
	std::string	tmp_fname;
	std::string tmp_lname;
	std::string tmp_nname;

	std::cout	<<std::endl
				<< "*****************PHONEBOOK******************" << std::endl
				<< "____________________________________________" << std::endl
				<< "|**INDEX**|FIRST*NAME|LAST**NAME|*NICKNAME*|" << std::endl
				<< "--------------------------------------------" << std::endl;
	while (i < 8)
	{
		tmp_fname = this->repertory[i].get_first_name();
		tmp_lname = this->repertory[i].get_last_name();
		tmp_nname = this->repertory[i].get_nickname();
		if (tmp_fname.length() > 10)
		{
			tmp_fname.resize(10);
			tmp_fname[9] = '.';
		}
		if (tmp_lname.length() > 10)
		{
			tmp_lname.resize(10);
			tmp_lname[9] = '.';
		}
		if (tmp_nname.length() > 10)
		{
			tmp_nname.resize(10);
			tmp_nname[9] = '.';
		}
		std::cout 	<< "|" << "*** " << i + 1 << " ***"
					<< "|" << std::setw(10) << tmp_fname
					<< "|" << std::setw(10) << tmp_lname
					<< "|" << std::setw(10) << tmp_nname
					<< "|" << std::endl;
		if (i < 7)
			std::cout << "|---------|----------|----------|----------|" << std::endl;
		else
			std::cout	<< "--------------------------------------------" << std::endl;		
		i++;
	}
	std::cout << std::endl;
	while (1)
	{
		std::cout	<< "Enter contact index to display informations: ";
		if (!getline(std::cin, index) || index == "EXIT")
			break ;
		if (atoi(index.c_str()) < 1 || atoi(index.c_str()) > 8
			|| index.length() > 1 || !isdigit(index[0]))
		{
			std::cout << "Invalid index" << std::endl;
			continue ;
		}
		if (this->repertory[atoi(index.c_str()) - 1].get_first_name().empty() ||
			this->repertory[atoi(index.c_str()) - 1].get_last_name().empty() ||
			this->repertory[atoi(index.c_str()) - 1].get_nickname().empty() ||
			this->repertory[atoi(index.c_str()) - 1].get_phone_number().empty() ||
			this->repertory[atoi(index.c_str()) - 1].get_secret().empty())
		{
			std::cout << "Contact is empty" << std::endl;
			continue ;
		}
		std::cout 	<< "First name: " << this->repertory[atoi(index.c_str()) - 1].get_first_name() << std::endl
					<< "Last name: " << this->repertory[atoi(index.c_str()) - 1].get_last_name() << std::endl
					<< "Nickname: " << this->repertory[atoi(index.c_str()) - 1].get_nickname() << std::endl
					<< "Phone number: " << this->repertory[atoi(index.c_str()) - 1].get_phone_number() << std::endl
					<< "Darkest secret: " << this->repertory[atoi(index.c_str()) - 1].get_secret() << std::endl;
	}
	return ;
}
