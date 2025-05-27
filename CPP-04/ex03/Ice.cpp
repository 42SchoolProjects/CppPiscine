/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kave0 <kave0@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 04:24:32 by albillie          #+#    #+#             */
/*   Updated: 2025/02/18 05:28:31 by kave0            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// Constructor(s)
Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice -> Default constructor has been constructed" << std::endl;
}

Ice::Ice(const Ice &src) : AMateria("ice")
{
	(void) src;
	std::cout << "Ice -> Copy constructor has been called" << std::endl;
}

// Destructor(s)
Ice::~Ice()
{
	std::cout << "Ice -> Destructor has been called" << std::endl;
}

// Overloard Operator(s)
Ice &Ice::operator=(const Ice &assign)
{
	std::cout << "Ice -> Overload operator of assignment has been called" << std::endl;
	AMateria::operator=(assign);
	return (*this);
}

// Other(s) Function(s)

AMateria *Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
