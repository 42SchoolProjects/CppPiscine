/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 07:02:43 by albillie          #+#    #+#             */
/*   Updated: 2025/02/14 07:02:54 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Constructor(s)
WrongAnimal::WrongAnimal() : type("None")
{
	std::cout << "WrongAnimal -> Have just been constructed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &WrongAnimal)
{
	std::cout << "WrongAnimal -> Have just been copied" << std::endl;
	this->type = WrongAnimal.type;
}

// Destructor(s)
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal -> Have just been destroyed" << std::endl;
}

// Overload Operator(S)
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &Assign)
{
	std::cout << "WrongAnimal -> Have just been assigned" << std::endl;
	this->type = Assign.type;
	return (*this);
}

// Getter(s)
std::string WrongAnimal::getType() const
{
	return (this->type);
}

// Function(s)
void WrongAnimal::makeSound() const
{
	std::cout << this->type << " -> No sound in here" << std::endl;
}
