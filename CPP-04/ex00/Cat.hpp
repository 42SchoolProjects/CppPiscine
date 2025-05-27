/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 06:26:40 by albillie          #+#    #+#             */
/*   Updated: 2025/02/14 06:55:12 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		// Constructor(s)
		Cat();
		Cat(const Cat &Cat);
		// Destructor(s)
		~Cat();
		// Overload Operator(s)
		Cat &operator=(const Cat &Assign);
		// Function(s)
		void makeSound() const;
};
