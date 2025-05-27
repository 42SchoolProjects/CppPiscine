/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 06:26:42 by albillie          #+#    #+#             */
/*   Updated: 2025/02/14 06:55:17 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructor(s)
Cat::Cat() : Animal()
{
	std::cout << "Cat -> Have just been constructed" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &Cat) : Animal()
{
	std::cout << "Cat -> Have just been copied" << std::endl;
	this->type = Cat.type;
}

// Destructor(s)
Cat::~Cat()
{
	std::cout << "Cat -> Have just been destroyed" << std::endl;
}

// Overload Operator(S)
Cat &Cat::operator=(const Cat &Assign)
{
	std::cout << "Cat -> Have just been assigned" << std::endl;
	this->type = Assign.type;
	return (*this);
}

// Function(s)
void Cat::makeSound() const
{
	std::cout << this->type << " -> Meowwwwwwwww" << std::endl;
}
