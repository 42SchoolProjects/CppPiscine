#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>

class Span
{
	private:
		std::vector<int>	intArray;
		unsigned int		maxSize;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &copy);
		Span &operator=(const Span &assign);
		~Span();
		void addNumber(int nb);
		void addMultipleNumbers();
		int shortestSpan();
		int longestSpan();
	class SpanIsFullException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class SpanIsEmptyException : public std::exception
	{
		virtual const char *what() const throw();
	};
};
