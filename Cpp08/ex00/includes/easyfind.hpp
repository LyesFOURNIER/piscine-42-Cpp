/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:08:06 by lfournie          #+#    #+#             */
/*   Updated: 2026/02/12 10:54:50 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "lib.hpp"

template <typename T> void easyfind( T elem, int interger )
{
	typename T::iterator it = find(elem.begin(), elem.end(), interger);
	typename T::iterator check = elem.end();
	if ( *it == *check )
		std::cout << "interger not found" << std::endl;
	else
		std::cout << *it << std::endl;
	return;
}
