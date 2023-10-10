#include "PmergeMe.hpp"

int main (int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "usage: ./PmergeMe <n1 n2, ... nn>\n";
		return 1;
	}
	PmergeMe(argv);
	return 0;
}
