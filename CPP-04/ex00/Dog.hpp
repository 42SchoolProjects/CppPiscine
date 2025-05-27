/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 06:03:06 by albillie          #+#    #+#             */
/*   Updated: 2025/02/14 06:54:46 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		// Constructor(s)
		Dog();
		Dog(const Dog &Dog);
		// Destructor(s)
		~Dog();
		// Overload Operator(s)
		Dog &operator=(const Dog &Assign);
		// Function(s)
		void makeSound() const;
};
