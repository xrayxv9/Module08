#pragma once

#include <iterator>
#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	public :
		typedef std::stack<T> stack;
		typedef typename stack::container_type container;
		typedef typename container::iterator iterator;
		typedef typename container::const_iterator const_iterator;
		typedef typename container::reverse_iterator reverse_iterator;

		MutantStack() {};

		~MutantStack() {};

		MutantStack operator=( MutantStack &self)
		{
			if (*this != self)
				*this = self;
			return *this;
		}
	
		MutantStack(MutantStack &self)
		{
			*this = self;
		}

		iterator begin()
		{
			return this->c.begin();
		}

		iterator end()
		{
			return this->c.end();
		}

		const_iterator const_begin()
		{
			return this->c.cbegin();
		}

		const_iterator const_end()
		{
			return this->c.cend();
		}

		reverse_iterator reverse_begin()
		{
			return this->c.rbegin();
		}

		reverse_iterator reverse_end()
		{
			return this->c.rend();
		}

};
