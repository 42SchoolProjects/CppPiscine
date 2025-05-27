/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 05:48:07 by albillie          #+#    #+#             */
/*   Updated: 2025/02/16 00:17:49 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal
{
	protected:
		std::string type;
		std::string noise;
		Animal(const Animal &Src);
		Animal();
	public:
		// Destructor(s)
		virtual ~Animal();
		// Overload Operator(s)
		Animal &operator=(const Animal &Assign);
		// Getter(s)
		std::string getType() const;
		// Function(s)
		virtual void makeSound() const;
};
