/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kave0 <kave0@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 04:43:24 by kave0             #+#    #+#             */
/*   Updated: 2025/02/18 05:25:42 by kave0            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

#include <iostream>
#include <string>

class Character : public ICharacter
{
	private:
		// Private Attribute(s)
		AMateria *gear[4];
	public:
		// Constructor(s)
		Character();
		Character(std::string name);
		Character(const Character &copy);
		// Destructor(s)
		~Character();
		// Overload Operator(s)
		Character &operator=(const Character &assign);
		// Getter(s)
		std::string const &getName() const;
		// Gear Functions
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};
