/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albillie <albillie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:31:31 by albillie          #+#    #+#             */
/*   Updated: 2025/02/01 14:56:57 by albillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	GetLevelIndex(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (size_t i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			return (i);
		}
	}
	return (-1);
}

void	HarlSwitchCase(std::string level, Harl &harl)
{
	std::cout << "[ " << level << " ]" << std::endl;
	switch (GetLevelIndex(level))
	{
		case 0:
			harl.complain("DEBUG");
		case 1:
			harl.complain("INFO");
		case 2:
			harl.complain("WARNING");
		case 3:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

int main(int ac, char **av)
{
	Harl harl;

	if (ac != 2)
	{
		std::cout << "Format -> ./harlFilter <LEVEL>" << std::endl;
		return (1);
	}
	HarlSwitchCase(av[1], harl);
	return (0);
}
