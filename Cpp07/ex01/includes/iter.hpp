/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:18:07 by lfournie          #+#    #+#             */
/*   Updated: 2026/04/20 09:05:41 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.hpp"

template <typename T, typename F> void iter(T *array, const unsigned int len, F f)
{
	if (array == NULL || f == NULL)
		return;
	for (unsigned int i = 0; i < len; i++)
	{
		f(array[i]);
	}
}
