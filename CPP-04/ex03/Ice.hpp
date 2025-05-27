/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kave0 <kave0@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 03:50:24 by albillie          #+#    #+#             */
/*   Updated: 2025/02/18 05:28:58 by kave0            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
	public:
		// Constructor(s)
		Ice();
		Ice(const Ice &src);
		// Destructor(s)
		~Ice();
		// Overloard Operator(s)
		Ice &operator=(const Ice &assign);
		// Other(s) Function(s)
		AMateria *clone() const;
		void use(ICharacter &target);
};
