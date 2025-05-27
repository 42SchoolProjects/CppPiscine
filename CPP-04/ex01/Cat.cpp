/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 06:26:42 by albillie          #+#    #+#             */
/*   Updated: 2025/02/16 01:25:23 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animals.h"

// Constructor(s)
Cat::Cat() : Animal()
{
	std::cout << "Cat -> Have just been constructed" << std::endl;
	type = "Cat";
	noise = "Meowwwwwwwwwwwww";
	brain = new Brain();
}

Cat::Cat(const Cat &Cat) : Animal(Cat)
{
	std::cout << "Cat -> Have just been copied" << std::endl;
	type = Cat.type;
	noise = Cat.noise;
}

// Destructor(s)
Cat::~Cat()
{
	delete brain;
	std::cout << "Cat -> Have just been destroyed" << std::endl;
}

// Overload Operator(S)
Cat &Cat::operator=(const Cat &Assign)
{
	std::cout << "Cat -> Have just been assigned" << std::endl;
	brain = new Brain(*Assign.brain);
	return (*this);
}

// Function(s)
void Cat::makeSound() const
{
	std::cout << noise << std::endl;
}
