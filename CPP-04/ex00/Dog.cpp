/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 06:02:36 by albillie          #+#    #+#             */
/*   Updated: 2025/02/14 06:55:04 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructor(s)
Dog::Dog() : Animal()
{
	std::cout << "Dog -> Have just been constructed" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog &Dog) : Animal()
{
	std::cout << "Dog -> Have just been copied" << std::endl;
	this->type = Dog.type;
}

// Destructor(s)
Dog::~Dog()
{
	std::cout << "Dog -> Have just been destroyed" << std::endl;
}

// Overload Operator(S)
Dog &Dog::operator=(const Dog &Assign)
{
	std::cout << "Dog -> Have just been assigned" << std::endl;
	this->type = Assign.type;
	return (*this);
}

// Function(s)
void Dog::makeSound() const
{
	std::cout << this->getType() << " -> Woooooooooooof" << std::endl;
}
