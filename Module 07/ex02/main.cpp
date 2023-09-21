#include <iostream>
#include "Array.hpp"
#include <stdlib.h>

#define MAX_VAL 750
int main(int, char**)
{

	std::cout << "Test on empty array:\n";
	Array<float>	empty;
	std::cout << "empty.size(): " << empty.size() << std::endl;
	std::cout << "Tyring to access on first element of empty......\n";
	try
	{
		std::cout << "empty[0]: " << empty[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n\n";
	}
	std::cout << "Test on a initialized by default array\n";
	Array<int>	zero(MAX_VAL);
	for(size_t i = 0; i < zero.size(); i++)
		std::cout << zero[i];
	std::cout << std::endl;
	


    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
	//SCOPE
    {
		std::cout << "\nAssigning tmp to numbers: (tmp = numbers)\n";
        Array<int> tmp = numbers;
		std::cout << "Calling copy constuctor on tmp: (Array<int> test(tmp))\n";
        Array<int> test(tmp);
		for (int i = 0; i < MAX_VAL; i++)
    	{
        	if (tmp[i] != numbers[i] || test[i] != tmp[i])
        	{
            	std::cerr << "didn't save the same value!!" << std::endl;
            	return 1;
        	}
			else if(&tmp + i == &numbers + i || &test + i == &tmp + i)
			{
				std::cerr << "tmp and numbers have the same addresses\n";
				return 1;
			}
		}
		std::cout << "Success: tmp, test and numbers have the same value but different addresses\n";
		
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

	std::cout << "\nTest with Strings:\n";
	Array<std::string>	array(3);
	array[0] = "toto";
	array[1] = "tata";
	array[2] = "tonton";
	Array<std::string> test = array;
	Array<std::string> tmp(test);
	std::cout << "&array: " << &array << std::endl;
	std::cout << "&test: " << &test << std::endl;
	std::cout << "&tmp: " << &tmp << std::endl << std::endl;
	for(size_t i = 0; i < array.size(); i++)
	{
		try
		{
			std::cout << "array[" << i << "]: \t" << array[i] << std::endl;
			std::cout << "test[" << i << "]: \t" << test[i] << std::endl;
			std::cout << "tmp[" << i << "]: \t" << tmp[i]  << std::endl;
			if(i != array.size() - 1)
				std::cout << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			return(1);
		}
	}
    return 0;
}