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
		std::vector<int>::iterator it;

		it = easyfind(v, 128);
		std::cout<<*it<<std::endl;
	} catch (const std::exception &e) {
		std::cout<<e.what()<<std::endl;
	}
	try {
		std::vector<int>::iterator it2;

		it2 = easyfind(v, 108);
		std::cout<<*it2<<std::endl;
	}
	catch (const std::exception &e) {
		std::cout<<e.what()<<std::endl;
	}

	std::list<int> lst;
	lst.push_back(30);
	lst.push_back(20);
	lst.push_back(10);
	lst.push_back(0);

	try {
		std::list<int>::iterator it3 = easyfind(lst, 20);
		std::cout<<*it3<<std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}
	return 0;
}