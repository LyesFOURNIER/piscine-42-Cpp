/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:36:21 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/16 08:31:13 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>

class Contact
{
	public:

		Contact(void);
		Contact(Contact &copy);
		Contact(	int			contact_id,
					std::string phone_number,
					std::string first_name,
					std::string last_name,
					std::string nickname,
					std::string secret	);
		~Contact(void);
		
		//GETTERS
		int			get_contact_id() const;
		std::string	get_phone_number() const;
		std::string	get_first_name() const;
		std::string	get_last_name() const;
		std::string	get_nickname() const;
		std::string	get_secret() const;
		
		//SETTERS
		void		set_contact_id(int contact_id);
		void		set_phone_number(std::string phone_number);
		void		set_first_name(std::string first_name);
		void		set_last_name(std::string last_name);
		void		set_nickname(std::string nickname);
		void		set_secret(std::string secret);
		
	private:
	
		int			_contact_id;
		std::string	_phone_number;
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_secret;
};

#endif
