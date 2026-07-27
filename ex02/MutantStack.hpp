#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
 
#include <stack>
#include <deque>

template<typename T, typename Container = std::deque<T> >
class MutantStack
{
	public:
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		typedef typename Container::reverse_iterator reverse_iterator;
		typedef typename Container::const_reverse_iterator c_r_iterator;

		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack& other);
		virtual ~MutantStack();

		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;

		reverse_iterator rbegin();
		reverse_iterator rend();
		c_r_iterator rbegin() const;
		c_r_iterator rend() const;
};

#include "MutantStack.tpp"

#endif