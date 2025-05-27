/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 04:52:27 by kave0             #+#    #+#             */
/*   Updated: 2025/02/19 20:08:22 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Constructor(S)
Character::Character()
{
	this->name = "Default";
	for (size_t i = 0; i < 4; i++)
	{
		this->gear[i] = NULL;
	}
	std::cout << "Character created with default constructor" << std::endl;
}

Character::Character(std::string name)
{
	this->name = name;
	for (size_t i = 0; i < 4; i++)
	{
		this->gear[i] = NULL;
	}
	std::cout << "Character created with string constructor" << std::endl;
}

Character::Character(const Character &copy)
{
	this->name = copy.name;
	for (size_t i = 0; i < 4; i++)
	{
		this->gear[i] = copy.gear[i]->clone();
	}
	std::cout << "Character has been copied" << std::endl;
}

// Destructor(s)
Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->gear[i])
		{
			delete this->gear[i];
		}
	}
	std::cout << "Character has been destroyed" << std::endl;
}

// Overload Operator(s)
Character &Character::operator=(const Character &assign)
{
	this->name = assign.name;
	for (size_t i = 0; i < 4; i++)
	{
		if (this->gear[i])
		{
			delete this->gear[i];
		}
		this->gear[i] = assign.gear[i]->clone();
	}
	return (*this);
}

// Getter(s)
std::string const &Character::getName() const
{
	return (this->name);
}

// Gear Functions
void Character::equip(AMateria *m)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->gear[i] == NULL)
		{
			std::cout << this->getName() << " equiped " << m->getType() << " in his gear" << std::endl;
			this->gear[i] = m->clone();
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4  && this->gear[idx] != NULL)
	{
		delete this->gear[idx];
		this->gear[idx] = NULL;
		std::cout << this->getName() << " unequiped item at index " << idx << " of his inventory" << std::endl;
	}
	else
	{
		std::cout << "Invalid index in gear or failed to unequip element at index " << idx << " of the gear" << std::endl;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4  && this->gear[idx] != NULL)
	{
		this->gear[idx]->use(target);
		std::cout << "Used item at index " << idx << " of the gear on " << target.getName() << std::endl;
	}
}
