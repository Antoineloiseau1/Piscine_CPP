#include "MutantStack.hpp"
#include <iostream>
#include <cstdlib>
#include <list>

#define MAX_VALUE 10

int main(void)
{
	MutantStack<int>	mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(42);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	it++;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}

// int main(void)
// {
// 	MutantStack<int> ms;

// 	std::cout << "Is MutantStack empy ?: " << std::boolalpha << ms.empty() << std::endl;

// 	std::cout << ">>>>>>> Pushing 42 <<<<<<<\n";
// 	ms.push(42);

// 	std::cout << "Is MutantStack empty ?: " << std::boolalpha << ms.empty() << std::endl;
// 	std::cout << "MutantSize: " << ms.size() << std::endl;

// 	std::cout << ">>>>>>>> Poping out 42 <<<<<<<<\n";
// 	ms.pop();
// 	std::cout << "MutantSize: " << ms.size() << std::endl;

// 	std::cout << "\n>>>>>>>>> Pushing numbers <<<<<<<<\n";
// 	for(size_t i = 10; i > 0; i--)
// 	{
// 		ms.push(i);
// 	}

// 	std::cout << "MutantStack's top(): " << ms.top() << std::endl;
// 	std::cout << "Using iterator on begin(): " << *ms.begin() << std::endl; 

// 	MutantStack<int>::iterator it;
// 	it = ms.begin();

// 	std::cout << "\n>>>>>>>>> Display stack using iterators <<<<<<<<\n";
// 	MutantStack<int>::iterator ite = ms.end();
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		it++;
// 	}
	
// 	return 0;
// }