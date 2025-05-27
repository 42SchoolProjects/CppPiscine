/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 07:03:02 by albillie          #+#    #+#             */
/*   Updated: 2025/02/14 07:03:03 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		// Constructor(s)
		WrongAnimal();
		WrongAnimal(const WrongAnimal &WrongAnimal);
		// Destructor(s)
		~WrongAnimal();
		// Overload Operator(s)
		WrongAnimal &operator=(const WrongAnimal &Assign);
		// Getter(s)
		std::string getType() const;
		// Function(s)
		void makeSound() const;
};
