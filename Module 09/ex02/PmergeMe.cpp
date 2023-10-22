#include "PmergeMe.hpp"
#include <iostream>
#include <deque>
#include <iomanip>


void PmergeMe(char **argv)
{
	std::vector<std::string>	args = extractArgs(argv);
	std::vector<int>			v;
	std::deque<int>				d;
	float						time_stamp;

	check_errors(args);
	v = extractNumbers<std::vector<int> >(args);
	d = extractNumbers<std::deque<int> >(args);

	std::cout << "Before:\t";
	print_container(d);
	std::cout << "After:\t";
	time_stamp = ford_johnson_algorithm(d);
	print_container(d);
	std::cout << "Time to process a range of " << d.size();
	std::cout << " elements with std::deque: " << time_stamp << " µs" << std::endl;
	std::cout << "Time to process a range of " << v.size();
	std::cout << " elements with std::vector: " << ford_johnson_algorithm(v) << " µs" << std::endl;
}

std::vector<std::string>	extractArgs(char **argv)
{
	std::vector<std::string>	args;

	for(int i = 1; argv[i]; i++)
	{
		args.push_back(argv[i]);
	}
	return args;
}

void	check_errors(std::vector<std::string> & args)
{
	
	std::istringstream 					iss;
	std::string							token;
	std::vector<std::string>::iterator	it;

	for(it = args.begin(); it != args.end(); it++)
	{
		iss.str(*it);
		while(iss >> token)
		{
			size_t	found = token.find_first_not_of("0123456789");
			if(found != std::string::npos)
			{
				std::cout << "Error\n";
				exit(1);
			}
		}
		iss.clear();
	}
}

