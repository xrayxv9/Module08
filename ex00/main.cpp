#include "easyfind.hpp"
#include <list>
#include <vector>

int main()
{
	std::list<int> arr;
	std::vector<int> arr2;

	arr.push_back(1);
	arr.push_back(3);
	arr.push_back(0);
	arr.push_back(3);
	arr.push_back(2);

	arr2.push_back(1);
	arr2.push_back(3);
	arr2.push_back(0);
	arr2.push_back(3);
	arr2.push_back(2);

	std::cout << "list : " << std::endl << std::endl;
	::easyfind(arr, 92);
	::easyfind(arr, 1);
	::easyfind(arr, 2);

	std::cout << "vector : " << std::endl << std::endl;
	::easyfind(arr2, 92);
	::easyfind(arr2, 1);
	::easyfind(arr2, 2);
}
