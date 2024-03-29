#include "ScalarConverter.hpp"
#include <iostream>



int main(int argc, char*argv[]) 
{
	if (argc != 2) 
	{
		std::cerr << "usage: ./convert <literal>\n";
		return (1);
	}

	ScalarConverter::convert(static_cast<std::string>(argv[1]));

	return (0);
}