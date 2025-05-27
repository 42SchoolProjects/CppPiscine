/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 07:04:05 by albillie          #+#    #+#             */
/*   Updated: 2025/02/14 07:04:13 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		// Constructor(s)
		WrongCat();
		WrongCat(const WrongCat &WrongCat);
		// Destructor(s)
		~WrongCat();
		// Overload Operator(s)
		WrongCat &operator=(const WrongCat &Assign);
		// Function(s)
		void makeSound() const;
};
