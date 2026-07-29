#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout <<"Top: "<< mstack.top() << std::endl;
	mstack.pop();
	std::cout <<"Stack size: "<< mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout<<"Element of the stack:"<<std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout<<"Test for copying mutantstack to a normal int stack:"<<std::endl;
	std::stack<int> s(mstack);
	while(!s.empty())
	{
		std::cout<<s.top()<<std::endl;
		s.pop();
	}
	std::cout << "Same test with std::list" << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << "Top: " << lst.back() << std::endl;
	lst.pop_back();
	std::cout << "Stack size: " << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();
	++lit;
	--lit;
	std::cout << "Element of the stack:" << std::endl;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}

	std::cout << "Test with const_iterator:" << std::endl;
 
	MutantStack<int> clst;
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
 
	const MutantStack<int> constStack(clst);
	MutantStack<int>::const_iterator clit = constStack.begin();
	MutantStack<int>::const_iterator clite = constStack.end();
 
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	return 0;
}