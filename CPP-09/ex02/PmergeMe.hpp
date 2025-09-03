#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>
#include <sstream>
#include <ctime>

// #define DEBUG

template <typename Container>
class PmergeMe
{
	private:
		typedef typename Container::value_type ValueType;
		typedef typename Container::iterator Iterator;

		Container &container;

		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);

		std::vector<size_t> InsertionOrderGenerator(size_t LowNumber);
		void				FordJohnsonProcess(size_t Start, size_t End);
	public:
		PmergeMe(Container &container);
		~PmergeMe();

		void Sort();
		void PrintContainer();
};

template <typename Container>
PmergeMe<Container>::PmergeMe(Container &container) : container(container)
{
}

template <typename Container>
PmergeMe<Container> &PmergeMe<Container>::operator=(const PmergeMe &other)
{
	(void) other;
}

template <typename Container>
PmergeMe<Container>::~PmergeMe()
{
}

template <typename Container>
void PmergeMe<Container>::Sort()
{
	FordJohnsonProcess(0, this->container.size());
}

template <typename Container>
void PmergeMe<Container>::PrintContainer()
{
	for (typename Container::iterator it = this->container.begin(); it != this->container.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <typename Container>
std::vector<size_t> PmergeMe<Container>::InsertionOrderGenerator(size_t LowNumber)
{
	std::vector<size_t> Order;

	if (LowNumber == 0)
	{
		return Order;
	}
	Order.push_back(0);
	if (LowNumber == 1)
	{
		return Order;
	}

	for (size_t i = 1; i < LowNumber; ++i)
	{
		Order.push_back(i);
	}
	return Order;
}

template <typename Container>
void PmergeMe<Container>::FordJohnsonProcess(size_t Start, size_t End)
{
	size_t Size = End - Start;
	if (Size <= 1)
	{
		return;
	}

	// Handle ODD
	bool HasPending = (Size % 2 != 0);
	typename PmergeMe<Container>::ValueType Pending;
	size_t PendingPos = End - 1;

	if (HasPending)
	{
		Pending = this->container[PendingPos];
		#ifdef DEBUG
			std::cout << std::endl << "[ DEBUG ] " << "Pending value is -> " << Pending << std::endl;
		#endif
		End--;
	}

	// Pairwise compare and swap
	for (size_t i = Start; i < End; i += 2)
	{
		if (this->container[i] > this->container[i + 1])
		{
			std::swap(this->container[i], this->container[i + 1]);
		}
	}

	std::vector<typename PmergeMe<Container>::ValueType> High, Low;

	// Split into high and low
	for (size_t i = Start + 1; i < End; i += 2)
	{
		High.push_back(this->container[i]);
		Low.push_back(this->container[i - 1]);
	}

	PmergeMe<std::vector<typename PmergeMe<Container>::ValueType> >(High).Sort(); // Sort high container
	std::vector<size_t> InsertOrder = this->InsertionOrderGenerator(Low.size());

	for (size_t k = 0; k < InsertOrder.size(); ++k)
	{
		size_t Index = InsertOrder[k];
		typename std::vector<typename PmergeMe<Container>::ValueType>::iterator it = std::lower_bound(High.begin(), High.end(), Low[Index]);
		#ifdef DEBUG
			std::cout << "[ DEBUG ] " << *it << " Will be replaced by -> " << Low[Index] << std::endl;
		#endif
		High.insert(it, Low[Index]);
	}

	if (HasPending)
	{
		typename std::vector<typename PmergeMe<Container>::ValueType>::iterator it = std::lower_bound(High.begin(), High.end(), Pending);
		#ifdef DEBUG
			std::cout << "[ DEBUG ] " << *it << " Will be replaced by -> " << Pending << std::endl;
		#endif
		High.insert(it, Pending);
	}

	for (size_t i = 0; i < High.size(); ++i)
	{
		this->container[Start + i] = High[i];
	}
}

