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

#include "Animals.h"

class WrongCat : public WrongAnimal
{
	private:
		Brain *brain;
	public:
		// Constructor(s)
		WrongCat();
		WrongCat(const WrongCat &WrongCat);
		// Destructor(s)
		virtual ~WrongCat();
		// Overload Operator(s)
		WrongCat &operator=(const WrongCat &Assign);
		// Function(s)
		void makeSound() const;
};
