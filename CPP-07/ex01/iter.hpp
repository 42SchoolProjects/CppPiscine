#pragma once

#include <iostream>

template <typename T> void iter(T *array, size_t length, void f(const T &iter))
{
	for (size_t i = 0; i < length; i++)
	{
		f(array[i]);
	}
}

template <typename T> void iter(T *array, size_t length, void f(T &iter))
{
	for (size_t i = 0; i < length; i++)
	{
		f(array[i]);
	}
}
