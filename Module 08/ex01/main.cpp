#include "Span.hpp"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <time.h>

#define MAX_VALUE 10

int main(void)
{

	srand(time(0));

	// 42 TESTS
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

	// My tests;
	{
		std::cout << "\nMy Tests:\n";
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

	//Test on insertion
	{
		std::cout << "\nTest on insertion:\n";
		Span				numbers(MAX_VALUE);
		std::vector<int>	v;

		for(int i = 0; i < MAX_VALUE; i++)
			v.push_back(rand());
		try
		{
			numbers.addSetOfNumbers(v.begin(), v.end());
			std::cout << numbers.shortestSpan() << std::endl;
			std::cout << numbers.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	// Tests on constructors
	{
		std::cout << "\nTest on contructors\n";
		Span	s(MAX_VALUE);
		std::vector<int>	v;
		for(int i = 0; i < MAX_VALUE; i++)
		{
			v.push_back(rand());
		}
		try
		{
			s.addSetOfNumbers(v.begin(), v.end());
			Span	s2(s);
			Span	s3 = s2;

			std::cout << "s" << s << std::endl;
			std::cout << "s2" << s2 << std::endl;
			std::cout << "s3" << s3 << std::endl << std::endl;
			std::cout << "s1 Shortest Span: " << s.shortestSpan() << std::endl;
			std::cout << "s2 Shortest Span: " << s2.shortestSpan() << std::endl; 
			std::cout << "s3 Shortest Span: " << s3.shortestSpan() << std::endl << std::endl;
			std::cout << "s1 Longuest Span: " << s.longestSpan() << std::endl;
			std::cout << "s2 Longuest Span: " << s2.longestSpan() << std::endl; 
			std::cout << "s3 Longuest Span: " << s3.longestSpan() << std::endl; 
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}