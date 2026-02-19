/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:18:07 by lfournie          #+#    #+#             */
/*   Updated: 2026/02/10 13:19:06 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.hpp"

template <typename T> void iter(T *array, const unsigned int len, void (*f)(T &))
{
	if (array == NULL || f == NULL)
		return;
	for (unsigned int i = 0; i < len; i++)
	{
		f(array[i]);
	}
}
/* 
template <typename T> void iter(T *array, const unsigned int len, void (*f)(const T &param))
{
	for (int i = 0; i < len, i++)
	{
		std::cout << "element before function call: " << array[i];
		f(array[i]);
		std:cout << "element after function call: " << array[i] < std::endl;
	}
} */
