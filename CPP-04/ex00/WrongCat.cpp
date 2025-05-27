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

#include "WrongCat.hpp"

// Constructor(s)
WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat -> Have just been constructed" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &WrongCat) : WrongAnimal()
{
	std::cout << "WrongCat -> Have just been copied" << std::endl;
	this->type = WrongCat.type;
}

// Destructor(s)
WrongCat::~WrongCat()
{
	std::cout << "WrongCat -> Have just been destroyed" << std::endl;
}

// Overload Operator(S)
WrongCat &WrongCat::operator=(const WrongCat &Assign)
{
	std::cout << "WrongCat -> Have just been assigned" << std::endl;
	this->type = Assign.type;
	return (*this);
}

// Function(s)
void WrongCat::makeSound() const
{
	std::cout << this->type << " -> Meowwwwwwwww" << std::endl;
}
