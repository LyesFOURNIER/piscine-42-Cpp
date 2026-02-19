/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:14:56 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/15 14:52:05 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../classes/Contact.hpp"

Contact::Contact(void)
{
	this->_contact_id = 0;
	this->_first_name = "";
	this->_last_name = "";
	this->_nickname = "";
	this->_phone_number = "";
	this->_secret = "";
	return ;
}

Contact::Contact(	int 		contact_id,
					std::string phone_number,
					std::string first_name,
					std::string last_name,
					std::string nickname,
					std::string secret	)
{
	this->_contact_id = contact_id;
	this->_first_name = first_name;
	this->_last_name = last_name;
	this->_nickname = nickname;
	this->_phone_number = phone_number;
	this->_secret = secret;
	return ;
}

Contact::~Contact(void)
{
	return ;
}

int Contact::get_contact_id() const
{
	return this->_contact_id;
}

std::string Contact::get_phone_number() const
{
	return this->_phone_number;
}

std::string Contact::get_first_name() const
{
	return this->_first_name;
}

std::string Contact::get_last_name() const
{
	return this->_last_name;
}

std::string Contact::get_nickname() const
{
	return this->_nickname;
}

std::string Contact::get_secret() const
{
	return this->_secret;
}

void	Contact::set_contact_id(int contact_id)
{
	this->_contact_id = contact_id;
	return ;
}
void	Contact::set_phone_number(std::string phone_number)
{
	this->_phone_number = phone_number;
	return ;
}
void	Contact::set_first_name(std::string first_name)
{
	this->_first_name = first_name;
	return ;
}
void	Contact::set_last_name(std::string last_name)
{
	this->_last_name = last_name;
	return ;
}
void	Contact::set_nickname(std::string nickname)
{
	this->_nickname = nickname;
	return ;
}
void	Contact::set_secret(std::string secret)
{
	this->_secret = secret;
	return ;
}
