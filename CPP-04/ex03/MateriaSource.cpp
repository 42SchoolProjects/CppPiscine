/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kave0 <kave0@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 04:48:37 by kave0             #+#    #+#             */
/*   Updated: 2025/02/18 05:43:00 by kave0            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Constructor(S)
MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
	{
		this->blueprint[i] = NULL;
	}
	std::cout << "MateriaSource -> Default constructor has been called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (copy.blueprint[i])
		{
			this->blueprint[i] = copy.blueprint[i]->clone();
		}
	}
	std::cout << "MateriaSource -> Copy constructor has been called" << std::endl;
}

// Destructor(s)
MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->blueprint[i])
		{
			delete blueprint[i];
		}
	}
	std::cout << "MateriaSource -> Destructor has been called" << std::endl;
}

// Overload Operator(s)
MateriaSource &MateriaSource::operator=(const MateriaSource &assign)
{
	(void) assign;
	std::cout << "MateriaSource -> Overload operator of assignment has been called" << std::endl;
	return (*this);
}

// MateriaSource Functions
void MateriaSource::learnMateria(AMateria *m)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->blueprint[i] == NULL)
		{
			this->blueprint[i] = m->clone();
			return ;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 4 - 1; i >= 0; i--)
	{
		if (this->blueprint[i] != NULL && this->blueprint[i]->getType() == type)
		{
			return (this->blueprint[i]->clone());
		}
	}
	return (NULL);
}
