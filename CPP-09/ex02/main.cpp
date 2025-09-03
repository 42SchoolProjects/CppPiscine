#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error -> " << av[0] << " <numbers...>" << std::endl;
		return EXIT_FAILURE;
	}

	std::vector<int> InVec;
	std::deque<int> InDeq;

	for (int i = 1; i < ac; i++)
	{
		std::stringstream ss(av[i]);
		int Value;
		if (ss >> Value && Value > 0)
		{
			InVec.push_back(Value);
			InDeq.push_back(Value);
		}
		else
		{
			std::cerr << "Error -> Invalid number: " << av[i] << " is not a valid positive integer." << std::endl;
			InVec.clear();
			InDeq.clear();
			return EXIT_FAILURE;
		}
	}

	std::cout << std::endl << "----------------------------" << std::endl;
	std::cout << "| USING A VECTOR CONTAINER |" << std::endl;
	std::cout << "----------------------------" << std::endl << std::endl;
	PmergeMe<std::vector<int> > vecSorter(InVec);

	std::cout << "Before -> ";
	vecSorter.PrintContainer();

	std::clock_t start = std::clock();
	vecSorter.Sort();
	std::clock_t end = std::clock();
	double ElapsedVector = end - start;

	std::cout << std::endl << "After  -> ";
	vecSorter.PrintContainer();

	std::cout << std::endl << "----------------------------" << std::endl;
	std::cout << "| USING A DEQUE CONTAINER  |" << std::endl;
	std::cout << "----------------------------" << std::endl << std::endl;
	PmergeMe<std::deque<int> > deqSorter(InDeq);

	std::cout << "Before -> ";
	deqSorter.PrintContainer();

	start = std::clock();
	deqSorter.Sort();
	end = std::clock();
	double ElapsedDeque = end - start;

	std::cout << std::endl << "After  -> ";
	deqSorter.PrintContainer();

	std::cout << std::endl << "--------------------------------------" << std::endl;
	std::cout << "| TIME DIFFERENCE FOR BOTH CONTAINERS |" << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	std::cout << std::endl << "Elapsed time (vector): " << ElapsedVector << " ms" << std::endl;
	std::cout << "Elapsed time (deque): " << ElapsedDeque << " ms" << std::endl;

	return 0;
}
