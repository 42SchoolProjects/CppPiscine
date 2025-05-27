#pragma once

#include <iostream>
#include <vector>

template <typename T>
class Array
{
	private:
		T	*array;
		int size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &copy);
		~Array();
		Array &operator=(const Array &assign);
		T &operator[](int idx);
};

template <class T> Array<T>::Array()
{
	size = 0;
	array = new T[0];
}

template <class T> Array<T>::Array(unsigned int n)
{
	array = new T[n];
	size = n;
}

template <class T> Array<T>::Array(const Array<T> &copy)
{
	array = new T[copy.size];
	size = copy.size;

	for (int i = 0; i < copy.size; i++)
	{
		this->array[i] = copy.array[i];
	}
}

template <class T> Array<T> &Array<T>::operator=(const Array<T> &assign)
{
	delete this->array;
	this->array = new T[assign.size];
	this->size = assign.size;

	for (int i = 0; i < assign.size; i++)
	{
		this->array[i] = assign.array[i];
	}
}

template <class T> T &Array<T>::operator[](int idx)
{
	if (idx < 0 || idx >= this->size)
	{
		throw std::out_of_range("Index parameter is too low or too big for Array range !");
	}
	return this->array[idx];
}

template <class T> Array<T>::~Array()
{
	delete [] this->array;
}
