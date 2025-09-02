#include "MutantStack.hpp"

int main()
{
	// creation of a string stack
	MutantStack<std::string> mstack_string;
	mstack_string.push("Five");
	mstack_string.push("Seventeen");
	mstack_string.pop();
	mstack_string.push("Three");
	mstack_string.push("Seven hundred thirty-seven");

	// creation of a int stack
	MutantStack<int> mstack;
	mstack.push(5);		// addding 5
	mstack.push(17);	// adding 17
	mstack.pop();		// deleting 17
	mstack.push(3);		// adding 3
	mstack.push(737);	// adding 737

	std::cout << std::endl;

	MutantStack<std::string>::iterator s_it = mstack_string.begin();
	MutantStack<std::string>::iterator e_it = mstack_string.end();

	++s_it;
	--s_it;
	std::cout << "String Iterator: " << std::endl ;
	while (s_it != e_it)
	{
		std::cout << *s_it << std::endl ;
		++s_it;
	}

	mstack_string.pop();
	mstack_string.pop();
	mstack_string.pop();

	std::cout << std::endl << "-------------------------------------------------------------------" << std::endl << std::endl;

	MutantStack<int>::iterator it_s = mstack.begin();
	MutantStack<int>::iterator it_e = mstack.end();

	++it_s;
	--it_s;

	std::cout << "Int Iterator: " << std::endl;
	while (it_s != it_e)
	{
		std::cout << *it_s << std::endl;
		++it_s;
	}

	return 0;
}
