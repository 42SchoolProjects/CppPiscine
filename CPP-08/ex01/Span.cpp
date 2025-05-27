#include "Span.hpp"

Span::Span()
{
	maxSize = 0;
}

Span::Span(unsigned int N)
{
	maxSize = N;
}

Span::Span(const Span &copy)
{
	this->maxSize = copy.maxSize;
	this->intArray = copy.intArray;
}

Span &Span::operator=(const Span &assign)
{
	this->maxSize = assign.maxSize;
	this->intArray = assign.intArray;
	return (*this);
}

Span::~Span()
{
	// Maybe add a free right here later
}

void Span::addNumber(int nb)
{
	if (this->intArray.size() >= this->maxSize)
	{
		throw (SpanIsFullException());
	}
	this->intArray.push_back(nb);
}

void Span::addMultipleNumbers()
{
	this->intArray.resize(this->maxSize);
	std::fill(this->intArray.begin(), this->intArray.end(), 42);
}

int Span::shortestSpan()
{
	if (this->intArray.size() < 2)
	{
		throw (SpanIsEmptyException());
	}

	std::vector<int> sortedArray(this->intArray.begin(), this->intArray.end());
	std::sort(sortedArray.begin(), sortedArray.end());

	int shortestSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sortedArray.size(); ++i)
	{
		int diff = sortedArray[i] - sortedArray[i - 1];
		if (diff < shortestSpan)
		{
			shortestSpan = diff;
		}
	}
	return (shortestSpan);
}

int Span::longestSpan()
{
	if (this->intArray.size() < 2)
	{
		throw (SpanIsEmptyException());
	}

	std::vector<int> sortedArray(this->intArray.begin(), this->intArray.end());
	std::sort(sortedArray.begin(), sortedArray.end());
	int longestSpan = sortedArray.back() - sortedArray.front();

	return (longestSpan);
}

const char *Span::SpanIsFullException::what() const throw()
{
	return ("SpanIsFullException -> Span is full !");
}

const char *Span::SpanIsEmptyException::what() const throw()
{
	return ("SpanIsFullException -> Span is empty !");
}
