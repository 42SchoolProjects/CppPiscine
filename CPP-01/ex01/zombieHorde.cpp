/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:19:56 by albillie          #+#    #+#             */
/*   Updated: 2025/01/31 19:38:13 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *ZombieHorde = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		ZombieHorde[i].SetName(name);
	}
	return (ZombieHorde);
}
