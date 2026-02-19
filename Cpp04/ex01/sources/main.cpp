/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfournie <lfournie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 08:16:12 by lfournie          #+#    #+#             */
/*   Updated: 2025/11/11 09:02:02 by lfournie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.hpp"

int main()
{	
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;
	
	std::cout << "\n" << std::endl;
	
	const Animal *arr[4];

	arr[0] = new Dog();
	arr[1] = new Dog();
	arr[2] = new Cat();
	arr[3] = new Cat();
	
	std::cout	<< arr[0]->getType() << "\n"
				<< arr[1]->getType() << "\n"
				<< arr[2]->getType() << "\n"
				<< arr[3]->getType()
				<< std::endl;
				
	arr[0]->makeSound();
	arr[1]->makeSound();
	arr[2]->makeSound();
	arr[3]->makeSound();
	
	for (int i = 0; i < 4; i++)
		delete(arr[i]);
		
	std::cout << "\n" << std::endl;
	
	Dog dog1;
	dog1.setBrain( "I want to run!", 0 );//we set the first idea of dog1 in his brain at index 0.
	Dog dog2( dog1 );//we do the deep copy of dog1, the first set idea should be copied.
	//we check the adress of dog1 and dog2, they should't be the same if the copy made of dog1 was deep.
	std::cout	<< "dog1 address: " << &dog1
				<< "\ndog2 address: " << &dog2
				<< std::endl;
	//we check the first idea in the brain of both dogs, they should be the same.
	std::cout 	<< "Before new set:\n"
				<< "dog1: " << dog1.getBrain()->getIdea(0) << " ||\n"
				<< "dog2: " << dog2.getBrain()->getIdea(0) << " ||"
				<< std::endl;
	//we set a new idea in the brain of dog2 at index 0,
	//it should change his idea without changing the idea of dog1 at the same index.
	dog2.setBrain( "I want a bone!" , 0 );
	std::cout 	<< "After new set A:\n"
				<< "dog1: " << dog1.getBrain()->getIdea(0) << " ||\n"
				<< "dog2: " << dog2.getBrain()->getIdea(0) << " ||"
				<< std::endl;
	//we do the same for dog1, as before it should't change the idea of dog2			
	dog1.setBrain( "I want to eat!" , 0);
	std::cout 	<< "After new set B:\n"
				<< "dog1: " << dog1.getBrain()->getIdea(0) << " ||\n"
				<< "dog2: " << dog2.getBrain()->getIdea(0) << " ||"
				<< std::endl;
	
	return 0;
}
