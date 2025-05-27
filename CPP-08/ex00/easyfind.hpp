#pragma once

#include <iostream>
#include <map>
#include <algorithm>

template <typename T> bool easyfind(T &intContainer, int occurr)
{
	if (std::find(intContainer.begin(), intContainer.end(), occurr) != intContainer.end())
	{
		std::cout << "Found occurrence !" << std::endl;
		return (true);
	}
	std::cout << "Occurrence " << occurr << " not found !" << std::endl;
	return (false);
}
