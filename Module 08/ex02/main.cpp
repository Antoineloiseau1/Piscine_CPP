#include "MutantStack.hpp"
#include <iostream>
#include <cstdlib>
#include <list>

#define MAX_VALUE 10

int main(void)
{
	MutantStack<int> ms;

	std::cout << "Is MutantStack empty ?: " << std::boolalpha << ms.empty() << std::endl;

	std::cout << "\n>>>>>>> Pushing 42 <<<<<<<\n";
	ms.push(42);

	std::cout << "Is MutantStack empty ?: " << std::boolalpha << ms.empty() << std::endl;
	std::cout << "MutantSize: " << ms.size() << std::endl;

	std::cout << "\n>>>>>>>> Poping out 42 <<<<<<<<\n";
	ms.pop();
	std::cout << "MutantSize: " << ms.size() << std::endl;

	std::cout << "\n>>>>>>>>> Pushing numbers <<<<<<<<\n";
	std::list<int>	l;
	for(size_t i = 0; i < MAX_VALUE; i++)
	{
		int value = rand() % MAX_VALUE;
		ms.push(value);
		l.push_back(value);
	}

	std::cout << "\n>>>>>>>>> Display stack using iterators <<<<<<<<\n";
	MutantStack<int>::iterator it = ms.begin();
	MutantStack<int>::iterator ite = ms.end();
	std::cout << "{";
	while (it != ite)
	{
		std::cout << *it;
		if (it != ite -1)
			std::cout << ", ";
		it++;
	}
	std::cout << "}\n";

	std::cout << "\n>>>>>>>>> comparing with a list <<<<<<<<\n";
	std::list<int>::iterator i = l.begin();
	std::list<int>::iterator ie = l.end();
	size_t x = 0;
	std::cout << "{";
	while (i != ie)
	{
		std::cout << *i;
		if(x != l.size() - 1)
			std::cout << ", ";
		x++;
		i++;
	}
	std::cout << "}\n";

	std::stack<int> s(ms);
	return 0;
}
