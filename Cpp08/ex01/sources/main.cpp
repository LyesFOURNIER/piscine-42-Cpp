/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 10:49:45 by lfournie          #+#    #+#             */
/*   Updated: 2026/05/18 11:21:21 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

int main()
{
	Span sp1 = Span(5);
	
	sp1.addNumber(6);
	sp1.addNumber(3);
	sp1.addNumber(17);
	sp1.addNumber(9);
	sp1.addNumber(11);
	
	std::cout << sp1.shortestSpan() << std::endl;
	std::cout << sp1.longestSpan() << std::endl;
	
	Span sp2 = Span(10000);
	std::vector<int> v1;
		
	for(int i = 0; i < 10000; i++)
	{
		v1.push_back(i);
	}
	
	
	sp2.addRange( v1.begin(), v1.end() );

	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
	
	try
	{
		/* sp1.addNumber(123);
		
		Span sp3 = Span(10000);
		std::vector<int> v2;
		
		for(int i = 0; i < 10001; i++)
		{
			v2.push_back(i);
		}
		
		sp3.addRange( v2.begin(), v2.end() );
		
		std::cout << sp3.shortestSpan() << std::endl;
		std::cout << sp3.longestSpan() << std::endl;

		
		Span sp4 = Span(1);

		sp4.addNumber(10);
		sp4.shortestSpan();
		sp4.longestSpan();

		Span sp5 = Span(2);
		
		sp5.addNumber(12);
		sp5.shortestSpan();
		sp5.longestSpan(); */
	}
	catch ( const Span::ArrayFullException &e)
	{
		std::cout << "Caught an exception: " << e.what() << std::endl;
	}
	catch ( const Span::NoSpanPossibleException &e)
	{
		std::cout << "Caught an exception: " << e.what() << std::endl;
	}
	
	return 0;
}
