#include "easyfind.hpp"
#include <vector>

int main()
{
	std::vector<int> intContainer;

	intContainer.push_back(1);
	intContainer.push_back(2);
	intContainer.push_back(3);
	intContainer.push_back(4);
	intContainer.push_back(42);

	easyfind(intContainer, 0);
	easyfind(intContainer, 1);
	easyfind(intContainer, 2);
	easyfind(intContainer, 3);
	easyfind(intContainer, 4);
	easyfind(intContainer, 5);
	easyfind(intContainer, 42);

	return (0);
}
