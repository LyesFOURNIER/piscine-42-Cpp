/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:36:03 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/16 08:31:01 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include "../includes/lib.hpp"

class PhoneBook
{
	public:
	
		PhoneBook(void);
		PhoneBook(PhoneBook &copy);
		~PhoneBook(void);
		
		void	usr_add(struct s_param *Contact_parameters);
		void	usr_search();

	private:

		Contact repertory[8];
		int		counter;
};

#endif
