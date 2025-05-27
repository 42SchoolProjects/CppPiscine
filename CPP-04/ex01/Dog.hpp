/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 06:03:06 by albillie          #+#    #+#             */
/*   Updated: 2025/02/16 01:04:33 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		// Constructor(s)
		Dog();
		Dog(const Dog &Dog);
		// Destructor(s)
		virtual ~Dog();
		// Overload Operator(s)
		Dog &operator=(const Dog &Assign);
		// Function(s)
		virtual void makeSound() const;
};
