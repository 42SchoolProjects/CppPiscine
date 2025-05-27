/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kave0 <kave0@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 02:20:26 by albillie          #+#    #+#             */
/*   Updated: 2025/02/18 05:21:07 by kave0            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// Constructor(s)
AMateria::AMateria()
{
}

AMateria::AMateria(std::string const &type) : type(type)
{
}

// Destructor(S)
AMateria::~AMateria()
{
}

// Getter(S)
std::string const &AMateria::getType() const
{
	return (this->type);
}

// Other Function(s)
void AMateria::use(ICharacter &target)
{
	(void) target;
}
