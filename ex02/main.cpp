#include "MutantStack.hpp"

static void testSubjectExample()
{
	std::cout << "=== Subject example ===" << std::endl;
 
	MutantStack<int> mstack;
 
	mstack.push(5);
	mstack.push(17);
 
	std::cout << mstack.top() << std::endl;
 
	mstack.pop();
 
	std::cout << mstack.size() << std::endl;
 
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
 
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
 
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	(void)s;
}
 
// Ayni islemleri std::list uzerinde yapip cikti dizisini karsilastiriyoruz.
// PDF: "MutantStack yerine std::list koyup calistirsak cikti ayni olmali."
static void testCompareWithList()
{
	std::cout << "\n=== Compare MutantStack output vs std::list output ===" << std::endl;
 
	std::vector<int> mutantOutput;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.pop();
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
 
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		while (it != ite)
		{
			mutantOutput.push_back(*it);
			++it;
		}
	}
 
	std::vector<int> listOutput;
	{
		std::list<int> l;
		l.push_back(5);
		l.push_back(17);
		l.pop_back();
		l.push_back(3);
		l.push_back(5);
		l.push_back(737);
		l.push_back(0);
 
		std::list<int>::iterator it = l.begin();
		std::list<int>::iterator ite = l.end();
		while (it != ite)
		{
			listOutput.push_back(*it);
			++it;
		}
	}
 
	bool same = (mutantOutput == listOutput);
	std::cout << "MutantStack: ";
	for (size_t i = 0; i < mutantOutput.size(); ++i)
		std::cout << mutantOutput[i] << " ";
	std::cout << std::endl;
 
	std::cout << "std::list:   ";
	for (size_t i = 0; i < listOutput.size(); ++i)
		std::cout << listOutput[i] << " ";
	std::cout << std::endl;
 
	std::cout << "Outputs identical: " << (same ? "YES" : "NO") << std::endl;
}
 
// const_iterator uzerinden erisim testi
static void testConstIterator()
{
	std::cout << "\n=== const_iterator ===" << std::endl;
 
	MutantStack<int> mstack;
	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
 
	const MutantStack<int> constStack(mstack);
	MutantStack<int>::const_iterator it = constStack.begin();
	MutantStack<int>::const_iterator ite = constStack.end();
 
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}
 
// Orthodox Canonical Form testi: copy constructor / operator=
static void testCopyAndAssign()
{
	std::cout << "\n=== Copy constructor / operator= ===" << std::endl;
 
	MutantStack<int> original;
	original.push(10);
	original.push(20);
	original.push(30);
 
	MutantStack<int> copy(original);
	std::cout << "copy.top(): " << copy.top() << " (expected 30)" << std::endl;
	std::cout << "copy.size(): " << copy.size() << " (expected 3)" << std::endl;
 
	MutantStack<int> assigned;
	assigned.push(999);
	assigned = original;
	std::cout << "assigned.top(): " << assigned.top() << " (expected 30)" << std::endl;
	std::cout << "assigned.size(): " << assigned.size() << " (expected 3)" << std::endl;
 
	// Bagimsizlik kontrolu: original'i degistirmek copy'yi etkilememeli
	original.push(40);
	std::cout << "original.size() after push: " << original.size() << " (expected 4)" << std::endl;
	std::cout << "copy.size() unaffected: " << copy.size() << " (expected 3)" << std::endl;
}
 
int main()
{
	testSubjectExample();
	testCompareWithList();
	testConstIterator();
	testCopyAndAssign();
	return (0);
}