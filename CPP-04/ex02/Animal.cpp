/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 05:41:01 by albillie          #+#    #+#             */
/*   Updated: 2025/02/19 19:48:40 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructor(s)
Animal::Animal() : type("None"), noise("Default Meowwwww")
{
	std::cout << "Animal -> Have just been constructed" << std::endl;
}

Animal::Animal(const Animal &Animal)
{
	std::cout << "Animal -> Have just been copied" << std::endl;
	type = Animal.type;
	noise = Animal.noise;
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
	noise = Assign.noise;
	type = Assign.type;
	return (*this);
}

// Getter(s)
std::string Animal::getType() const
{
	return (this->type);
}

// Function(s)
void Animal::makeSound() const
{
	std::cout << noise << std::endl;
}
