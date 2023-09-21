#include "easyfind.hpp"
#include<vector>
#include<deque>
#include <list>
#include<cstdlib>
#include<iostream>

#define MAX_VALUE 150

int main(void)
{
	//TEST ON VECTORS
	{
		std::cout << "test on vectors:\n";
		std::vector<int>	v;

		for(int i = 0; i < MAX_VALUE; i++)
			v.push_back(rand() % MAX_VALUE);
		try
		{
			std::cout << "found value: " << *easyfind(v, rand() % MAX_VALUE) << " in vector" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	// TEST ON DEQUE
	{
		std::cout << "\ntest on deque:\n";
		std::deque<int>	d;

		for(int i = 0; i < MAX_VALUE; i++)
			d.push_back(rand() % MAX_VALUE);
		try
		{
			std::cout << "found value: " << *easyfind(d, rand() % MAX_VALUE)<< " in deque" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	//TEST ON LIST
	{
		std::cout << "\ntest on list:\n";
		std::list<int>	l;

		for(int i = 0; i < MAX_VALUE; i++)
			l.push_back(rand() % MAX_VALUE);
		try
		{
			std::cout << "found value: " << *easyfind(l, rand() % MAX_VALUE) << " in list" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
	//Test on invalid key
	{
		std::cout << "\nTest on invalid key\n";
		std::vector<int>	v;
		for(int i = 0; i < MAX_VALUE; i++)
			v.push_back(i);
		try
		{
			std::cout << *easyfind(v, 4242) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	return 0;
}