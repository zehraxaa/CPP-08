#ifndef SPAN_HPP
#define SPAN_HPP

#include <iterator>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cstdlib>
#include <iostream>

class Span
{
	private:
		unsigned int maxSz;
		std::vector<int> numbers;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int n);
		int shortestSpan() const;
		int longestSpan() const;

		template<typename Iterator>
		void addRange(Iterator begin, Iterator end)
		{
			typename std::iterator_traits<Iterator>::difference_type dist;
			dist = std::distance(begin, end);
			if (dist < 0)
				throw std::runtime_error("Span: invalid iterator range");
			if (numbers.size() + static_cast<size_t>(dist) > maxSz)
				throw std::runtime_error("Span: range exceeds");
			numbers.insert(numbers.end(), begin, end);
		}
};

#endif