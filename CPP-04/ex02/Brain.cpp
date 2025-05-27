/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:54:46 by albillie          #+#    #+#             */
/*   Updated: 2025/02/14 18:18:16 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Constructor(s)
Brain::Brain()
{
	std::cout << "Brain -> Have just been constructed" << std::endl;
	for (size_t i = 0; i < 100; i++)
	{
		ideas[i] = "I have no idea";
	}
}

Brain::Brain(const Brain &Brain)
{
	std::cout << "Brain -> Have just been copied" << std::endl;
	for (size_t i = 0; i < 100; i++)
	{
		this->ideas[i] = Brain.ideas[i];
	}
}

// Destructor(s)
Brain::~Brain()
{
	std::cout << "Brain -> Have just been destroyed" << std::endl;
}

// Overload Operator(S)
Brain &Brain::operator=(const Brain &Assign)
{
	std::cout << "Brain -> Have just been assigned" << std::endl;
	for (size_t i = 0; i < 100; i++)
	{
		this->ideas[i] = Assign.ideas[i];
	}
	return (*this);
}

// Getter(s)
std::string Brain::getIdea(int index) const
{
	return (this->ideas[index]);
}

