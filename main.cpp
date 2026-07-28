#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>

static void testSubjectExample()
{
	std::cout << "=== Subject example ===" << std::endl;
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "shortestSpan: " << sp.shortestSpan() << " (expected 2)" << std::endl;
	std::cout << "longestSpan: " << sp.longestSpan() << " (expected 14)" << std::endl;
}

static void testFullSpanException()
{
	std::cout << "\n=== Full span exception ===" << std::endl;
	Span sp(2);
	sp.addNumber(1);
	sp.addNumber(2);
	try
	{
		sp.addNumber(3);
		std::cout << "ERROR: no exception thrown" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught as expected: " << e.what() << std::endl;
	}
}

static void testEmptyAndSingleException()
{
	std::cout << "\n=== Empty / single element exceptions ===" << std::endl;

	Span empty(5);
	try
	{
		empty.shortestSpan();
		std::cout << "ERROR: no exception thrown (empty)" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught as expected (empty): " << e.what() << std::endl;
	}

	Span single(5);
	single.addNumber(42);
	try
	{
		single.longestSpan();
		std::cout << "ERROR: no exception thrown (single)" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught as expected (single): " << e.what() << std::endl;
	}
}

static void testAddRange()
{
	std::cout << "\n=== addRange with iterators ===" << std::endl;
	std::vector<int> values;
	values.push_back(4);
	values.push_back(8);
	values.push_back(15);
	values.push_back(16);
	values.push_back(23);
	values.push_back(42);

	Span sp(10);
	sp.addRange(values.begin(), values.end());

	std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
	std::cout << "longestSpan: " << sp.longestSpan() << std::endl;

	try
	{
		std::vector<int> tooMany(20, 1);
		sp.addRange(tooMany.begin(), tooMany.end());
		std::cout << "ERROR: no exception thrown (capacity overflow)" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught as expected (overflow): " << e.what() << std::endl;
	}
}

static void testBigSpan()
{
	std::cout << "\n=== Big span (10000+ numbers) ===" << std::endl;
	const unsigned int N = 10000;
	std::srand(42);

	std::vector<int> values;
	values.reserve(N);
	for (unsigned int i = 0; i < N; ++i)
		values.push_back(std::rand());

	Span sp(N);
	sp.addRange(values.begin(), values.end());

	std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
	std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
}

static void testCopyAndAssign()
{
	std::cout << "\n=== Copy constructor / operator= ===" << std::endl;
	Span sp(5);
	sp.addNumber(1);
	sp.addNumber(10);

	Span copy(sp);
	std::cout << "copy longestSpan: " << copy.longestSpan() << " (expected 9)" << std::endl;

	Span assigned(3);
	assigned = sp;
	std::cout << "assigned longestSpan: " << assigned.longestSpan() << " (expected 9)" << std::endl;
}

int main()
{
	testSubjectExample();
	testFullSpanException();
	testEmptyAndSingleException();
	testAddRange();
	testBigSpan();
	testCopyAndAssign();
	return (0);
}