/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kave0 <kave0@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 04:57:15 by albillie          #+#    #+#             */
/*   Updated: 2025/02/18 05:27:08 by kave0            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	public:
		// Constructor(s)
		Cure();
		Cure(const Cure &src);
		// Destructor(s)
		~Cure();
		// Overloard Operator(s)
		Cure &operator=(const Cure &assign);
		// Other(s) Function(s)
		AMateria *clone() const;
		void use(ICharacter &target);
};
