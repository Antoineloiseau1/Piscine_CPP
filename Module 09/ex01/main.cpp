#include "RPN.hpp"
#include <iostream>
#include <stack>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "usage: RPN <expression>\n";
		return 1;
	}
	RPN(argv[1]);
	return 0;
}
