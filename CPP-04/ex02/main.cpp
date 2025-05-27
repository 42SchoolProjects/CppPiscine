/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 05:39:26 by albillie          #+#    #+#             */
/*   Updated: 2025/02/19 19:54:09 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animals.h"

int main()
{
	Animal *animals[4];

	// Animal test;

	std::cout << " -> ********************* ! <-" << std::endl;
	std::cout << " -> CONSTRUCTORS OUT HERE ! <-" << std::endl;
	std::cout << " -> ********************* ! <-" << std::endl << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
		{
			animals[i] = new Cat();
		}
		else
		{
			animals[i] = new Dog();
		}
		std::cout << std::endl;
	}
	std::cout << " -> ************** ! <-" << std::endl;
	std::cout << " -> TESTS OUT HERE ! <-" << std::endl;
	std::cout << " -> ************** ! <-" << std::endl << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		animals[i]->makeSound();
		delete animals[i];
	}
	std::cout << std::endl;
	std::cout << " -> ******************** ! <-" << std::endl;
	std::cout << " -> ASSIGNATION OUT HERE ! <-" << std::endl;
	std::cout << " -> ******************** ! <-" << std::endl << std::endl;

	Dog basic;
	Dog tmp = basic;
}
