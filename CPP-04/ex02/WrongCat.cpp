/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 07:03:50 by albillie          #+#    #+#             */
/*   Updated: 2025/02/14 07:04:01 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animals.h"

// Constructor(s)
WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat -> Have just been constructed" << std::endl;
	type = "WrongCat";
	noise = "Meowwwwwwwwwwwww";
	brain = new Brain;
}

WrongCat::WrongCat(const WrongCat &WrongCat) : WrongAnimal(WrongCat)
{
	std::cout << "WrongCat -> Have just been copied" << std::endl;
	type = WrongCat.type;
	noise = WrongCat.noise;
}

// Destructor(s)
WrongCat::~WrongCat()
{
	delete brain;
	std::cout << "WrongCat -> Have just been destroyed" << std::endl;
}

// Overload Operator(S)
WrongCat &WrongCat::operator=(const WrongCat &Assign)
{
	std::cout << "WrongCat -> Have just been assigned" << std::endl;
	brain = new Brain(*Assign.brain);
	return (*this);
}

// Function(s)
void WrongCat::makeSound() const
{
	std::cout << noise << std::endl;
}
