#include "Span.hpp"
#include <stdexcept>

Span::Span() : maxSz(0) {};

Span::Span(unsigned int N) : maxSz(N) {};

Span::Span(const Span &other) : maxSz(other.maxSz), numbers(other.numbers) {};

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		maxSz = other.maxSz;
		numbers = other.numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (numbers.size() >= maxSz)
		throw std::runtime_error("Span: span is full cannot add new number");
	numbers.push_back(n);
}

int Span::shortestSpan() const
{
	if (numbers.size() < 2)
		throw std::runtime_error("Span: not eneough elements to compare");
	std::vector<int> sorted(numbers);
	std::sort(sorted.begin(), sorted.end());

	int minDiff = sorted[1] - sorted[0];
	for (size_t i = 2; i < sorted.size(); i++)
	{
		int diff = sorted[i] - sorted[i -1];
		if (diff < minDiff)
			minDiff = diff;
	}
	return minDiff;
}

int Span::longestSpan() const
{
	if (numbers.size() < 2)
		throw std::runtime_error("Span: not eneough elements to compare");
	int maxValue = *std::max_element(numbers.begin(), numbers.end());
	int minValue = *std::min_element(numbers.begin(), numbers.end());
	return (maxValue - minValue);
}