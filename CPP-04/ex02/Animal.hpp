/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 05:48:07 by albillie          #+#    #+#             */
/*   Updated: 2025/02/19 19:50:26 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Brain.hpp"

class Animal
{
	protected:
		std::string type;
		std::string noise;
	public:
		// Constructor(s)
		Animal();
		Animal(const Animal &Src);
		// Destructor(s)
		virtual ~Animal();
		// Overload Operator(s)
		Animal &operator=(const Animal &Assign);
		// Getter(s)
		std::string getType() const;
		// Function(s)
		virtual void makeSound() const = 0;
};
