/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:16:12 by lfournie          #+#    #+#             */
/*   Updated: 2025/10/29 14:52:34 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

int main()
{
	const Animal* meta = new Animal();
	
	
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* metal = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	metal->makeSound();
	k->makeSound();
	
	delete j;
	delete i;
	delete meta;
	delete k;
	delete metal;
	return 0;
}
