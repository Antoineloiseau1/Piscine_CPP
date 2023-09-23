#include "Span.hpp"
#include<vector>
#include<iostream>
#include<stdlib.h>

#define MAX_VALUE 10000

int main(void)
{
	//42 TESTS
	{
		std::cout << "42 TEST:\n";
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	//My tests;
	{
		std::cout << "\nMy Tests\n";
		Span	span(MAX_VALUE);
		try
		{
			for(int i = 0; i < MAX_VALUE; i++)
			{
				span.addNumber(rand());
			}
			std::cout << span.shortestSpan() << std::endl;
			std::cout << span.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << "\ntest on insertion\n";
		Span				numbers(41);
		std::vector<int>	v;

		for(int i = 0; i < 10; i++)
			v.push_back(rand() % 1000);
		for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
			std::cout << *it << ", ";
		std::cout << std::endl;
		try
		{
			std::cout << numbers << std::endl;
			// numbers.addSetOfNumbers(v.begin(), v.end());
			numbers.addSetOfNumbers(v.begin() + 8, v.end());
			std::cout << *(numbers.getSet().begin() + 1) << std::endl;
			std::cout << numbers << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}