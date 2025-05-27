/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:40:57 by albillie          #+#    #+#             */
/*   Updated: 2025/02/01 07:39:07 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(const std::string &name);
		void attack();
		void setWeapon(Weapon &weapon);
		~HumanB();
	private:
		Weapon *weapon;
		std::string name;
};
