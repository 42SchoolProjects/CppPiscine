/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:20:02 by albillie          #+#    #+#             */
/*   Updated: 2025/01/31 19:40:38 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

int main()
{
	Zombie *Horde;

	Horde = zombieHorde(10, "albillie");
	for (size_t i = 0; i < 10; i++)
	{
		Horde->announce();
	}
	delete [] Horde;
}
