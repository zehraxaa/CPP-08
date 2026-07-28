#include "Span.hpp"
#include <algorithm>

int main()
{
	try {
	std::cout<<"Subject Test:"<<std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout<<sp.shortestSpan()<<std::endl;
	std::cout<<sp.longestSpan()<<std::endl<<std::endl;;

	std::cout<<"Adding 10001 random numbers by addNumber(int n) function:"<<std::endl;
	std::srand(std::time(NULL));
	Span sp2(10001);
	for (int i=0; i<10001; i++)
	{
		sp2.addNumber(std::rand());
	}
	std::cout<<sp2.shortestSpan()<<std::endl;
	std::cout<<sp2.longestSpan()<<std::endl<<std::endl;

	std::cout<<"Adding 10001 random numbers by addRange(begin, end) function:"<<std::endl;
	Span sp3(10001);
	std::vector<int> randomNums(10001);
	std::generate(randomNums.begin(), randomNums.end(), std::rand);
	sp3.addRange(randomNums.begin(), randomNums.end());
	std::cout<<sp3.shortestSpan()<<std::endl;
	std::cout<<sp3.longestSpan()<<std::endl<<std::endl;

	std::cout<<"Adding numbers by addRange(begin, end) function:"<<std::endl;
	Span sp4(5);
	std::vector<int> numbers;
	numbers.push_back(10);
	numbers.push_back(11);
	numbers.push_back(12);
	numbers.push_back(13);
	numbers.push_back(14);
	sp4.addRange(numbers.begin(), numbers.end());
	std::cout<<"shortest: "<<sp4.shortestSpan()<<std::endl;
	std::cout<<"longest: "<<sp4.longestSpan()<<std::endl<<std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}
	return 0;
}