#include "easyfind.hpp"
#include<vector>
#include<deque>
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
			v.push_back(rand());
		try
		{
			easyfind(v, 42);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		v.push_back(42);
		try
		{
			easyfind(v, 42);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	// TEST ON DEQUE
	{
		std::cout << "test on deque:\n";
		std::deque<int>	d;

		for(int i = 0; i < MAX_VALUE; i++)
			d.push_back(rand());
		try
		{
			easyfind(d, 24);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		d.push_back(24);
		try
		{
			easyfind(d, 24);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	//TEST ON ?
	{
		std::cout << "test on deque:\n";
		std::deque<int>	d;

		for(int i = 0; i < MAX_VALUE; i++)
			d.push_back(rand());
		try
		{
			easyfind(d, 24);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		d.push_back(24);
		try
		{
			easyfind(d, 24);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
	return 0;
}