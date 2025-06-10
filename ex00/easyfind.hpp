#pragma  once

#include <iostream>
#include <algorithm>

template <typename T>
void easyfind(T &container, int toFind)
{
	typename T::iterator it = std::find(container.begin(), container.end(), toFind);

	if (container.end() == it)
	{
		std::cerr << "Couldn't find the number you asked for : " << toFind << std::endl;
		return ;
	}
	std::cout << "your number is this one : " << *it << std::endl;
}
