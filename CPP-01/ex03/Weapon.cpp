/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:05:18 by albillie          #+#    #+#             */
/*   Updated: 2025/02/01 07:36:49 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : type(type)
{
}

Weapon::~Weapon()
{
}

std::string const &Weapon::getType()
{
	return (this->type);
}

void Weapon::setType(std::string Type)
{
	Weapon::type = Type;
}




