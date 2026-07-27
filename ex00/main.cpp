#include "easyfind.hpp"

int main()
{
	std::vector<int> v;
	v.push_back(12);
	v.push_back(12);
	v.push_back(36);
	v.push_back(128);
	v.push_back(9);

	try {
	{
		std::vector<int>::iterator it;

		it = easyfind(v, 108);
		std::cout<<*it<<std::endl;
	}
	} catch (const std::exception &e) {
		std::cout<<e.what()<<std::endl;
	}
	return 0;
}