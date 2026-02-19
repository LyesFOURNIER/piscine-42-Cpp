/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:49:45 by lfournie          #+#    #+#             */
/*   Updated: 2026/02/10 13:19:56 by lfournie         ###   ########.fr       */
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

int main( void )
{
	int arr[] = { 1, 2, 3 };
	
	std::cout	<< "array value before modification: "
				<< arr[0] << ", "
				<< arr[1] << ", "
				<< arr[2] 
				<< std::endl;
	::iter(arr, 3, incrementVal);
	std::cout	<< "array value after incrementation: "
				<< arr[0] << ", "
				<< arr[1] << ", "
				<< arr[2] 
				<< std::endl;
	::iter(arr, 3, decrementVal);
	std::cout	<< "array value after decrementation: "
				<< arr[0] << ", "
				<< arr[1] << ", "
				<< arr[2] 
				<< std::endl;
}
