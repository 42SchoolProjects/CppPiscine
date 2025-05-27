/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 06:26:40 by albillie          #+#    #+#             */
/*   Updated: 2025/02/16 01:04:37 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *brain;
	public:
		// Constructor(s)
		Cat();
		Cat(const Cat &Cat);
		// Destructor(s)
		virtual ~Cat();
		// Overload Operator(s)
		Cat &operator=(const Cat &Assign);
		// Function(s)
		virtual void makeSound() const;
};
