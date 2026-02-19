/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 08:38:11 by lfournie          #+#    #+#             */
/*   Updated: 2026/02/10 10:40:39 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"
Base *generate(void);
void identify(Base* p);
void identify(Base& p);

Base *generate(void)
{
	srand(time(0));
	int random = rand() % 3;
	if (random == 0)
	{
		Base *a = new A();
		std::cout << "created A instance" << std::endl;
		return (a);
	}
	else if (random == 1)
	{
		Base *b = new B();
		std::cout << "created B instance" << std::endl;
		return (b);
	}
	else if (random == 2)
	{
		Base *c = new C();
		std::cout << "created C instance" << std::endl;
		return (c);
	}
	return (NULL);
}

void identify(Base* p)
{
	A *a = dynamic_cast<A *>(p);
	B *b = dynamic_cast<B *>(p);
	C *c = dynamic_cast<C *>(p);
	if (a != NULL)
	{
		std::cout << "object pointed by p is of type A" << std::endl;
		return;
	}
	else if (b != NULL)
	{
		std::cout << "object pointed by p is of type B" << std::endl;
		return;
	}
	else if (c != NULL)
	{
		std::cout << "object pointed by p is of type C" << std::endl;
		return;
	}
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "object referenced by p is of type A" << std::endl;
		return;
	}
	catch( ... ){}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "object referenced by p is of type B" << std::endl;
		return;
	}
	catch ( ... ){}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "object referenced by p is of type C" << std::endl;
		return;
	}
	catch( ... ){}
}

int	main()
{
	Base *base = generate();
	identify(base);
	identify(*base);
	delete(base);
	return (0);
}
