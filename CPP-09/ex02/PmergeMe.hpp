#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>
#include <sstream>
#include <ctime>

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

	bool HasPending = (Size % 2 != 0);
	typename PmergeMe<Container>::ValueType Pending;
	size_t PendingPos = End - 1;

	if (HasPending)
	{
		Pending = this->container[PendingPos];
		End--;
	}
	for (size_t i = Start; i < End; i += 2)
	{
		if (this->container[i] > this->container[i + 1])
		{
			std::swap(this->container[i], this->container[i + 1]);
		}
	}

	std::vector<typename PmergeMe<Container>::ValueType> high, low;

	for (size_t i = Start + 1; i < End; i += 2)
	{
		high.push_back(this->container[i]);
		low.push_back(this->container[i - 1]);
	}

	PmergeMe<std::vector<typename PmergeMe<Container>::ValueType> >(high).Sort();
	std::vector<size_t> InsertOrder = this->InsertionOrderGenerator(low.size());

	for (size_t k = 0; k < InsertOrder.size(); ++k)
	{
		size_t idx = InsertOrder[k];
		typename std::vector<typename PmergeMe<Container>::ValueType>::iterator it = std::lower_bound(high.begin(), high.end(), low[idx]);
		high.insert(it, low[idx]);
	}
	if (HasPending)
	{
		typename std::vector<typename PmergeMe<Container>::ValueType>::iterator it = std::lower_bound(high.begin(), high.end(), Pending);
		high.insert(it, Pending);
	}
	for (size_t i = 0; i < high.size(); ++i)
	{
		this->container[Start + i] = high[i];
	}
}

