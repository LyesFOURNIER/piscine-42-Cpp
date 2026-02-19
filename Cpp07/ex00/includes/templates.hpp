/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:50:37 by lfournie          #+#    #+#             */
/*   Updated: 2026/02/10 11:14:37 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.hpp"

template <typename T> void swap(T &x, T &y)
{
	T tmp = x;
	x = y;
	y = tmp;
}

template <typename T> T max(T x, T y)
{
	if (x > y)
		return (x);
	return (y);
}

template <typename T> T min(T x, T y)
{
	if (x < y)
		return (x);
	return (y);
}
