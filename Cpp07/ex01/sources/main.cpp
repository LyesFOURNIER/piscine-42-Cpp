/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:49:45 by lfournie          #+#    #+#             */
/*   Updated: 2026/04/20 09:05:01 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

void	incrementVal(int &val)
{
	val++;
	return;
}
void	decrementVal(int &val)
{
	val--;
	return;
}

void	printConstVal(const int &val)
{
	std::cout << val << "\n";
	return;
}

int main( void )
{
	int arr[] = { 1, 2, 3 };
	
	std::cout	<< "array value before modification:\n";
	::iter(arr, 3, printConstVal);
	::iter(arr, 3, incrementVal);
	std::cout	<< "array value after incrementation:\n";
	::iter(arr, 3, printConstVal);
	::iter(arr, 3, decrementVal);
	std::cout	<< "array value after decrementation:\n";
	::iter(arr, 3, printConstVal);
}
