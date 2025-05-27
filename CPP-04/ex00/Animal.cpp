
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 05:41:01 by albillie          #+#    #+#             */
/*   Updated: 2025/02/14 06:57:20 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructor(s)
Animal::Animal() : type("None")
{
	std::cout << "Animal -> Have just been constructed" << std::endl;
}

Animal::Animal(const Animal &Animal)
{
	std::cout << "Animal -> Have just been copied" << std::endl;
	this->type = Animal.type;
}

// Destructor(s)
Animal::~Animal()
{
	std::cout << "Animal -> Have just been destroyed" << std::endl;
}

// Overload Operator(S)
Animal &Animal::operator=(const Animal &Assign)
{
	std::cout << "Animal -> Have just been assigned" << std::endl;
	this->type = Assign.type;
	return (*this);
}

// Getter(s
std::string Animal::getType() const
{
	return (this->type);
}

// Function(s)
void Animal::makeSound() const
{
	std::cout << this->type << " -> No sound in here" << std::endl;
}
