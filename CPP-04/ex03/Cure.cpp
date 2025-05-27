/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kave0 <kave0@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 04:57:34 by albillie          #+#    #+#             */
/*   Updated: 2025/02/18 05:26:32 by kave0            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// Constructor(s)
Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure -> Default constructor has been called" << std::endl;
}

Cure::Cure(const Cure &src) : AMateria("cure")
{
	(void) src;
	std::cout << "Cure -> Copy constructor has been called" << std::endl;
}

// Destructor(s)
Cure::~Cure()
{
	std::cout << "Cure -> Destructor has been called" << std::endl;
}

// Overloard Operator(s)
Cure &Cure::operator=(const Cure &assign)
{
	std::cout << "Cure -> Overload operator of assignment has been called" << std::endl;
	AMateria::operator=(assign);
	return (*this);
}

// Other(s) Function(s)
AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "s wounds *" << std::endl;
}
