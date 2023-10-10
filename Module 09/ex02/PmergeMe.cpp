#include "PmergeMe.hpp"
#include <iostream>
#include <deque>



void PmergeMe(char **argv)
{
	std::vector<std::string>	args = extractArgs(argv);
	std::vector<int>			v;
	std::deque<int>				d;

	if (check_errors(args))
	{
		return ;
	}
	v = extractNumbers<std::vector<int> >(args);
	d = extractNumbers<std::deque<int> >(args);
	(void)v;
	(void)d;
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

bool	check_errors(std::vector<std::string> & args)
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
				return true;
			}
		}
		iss.clear();
	}
	return false;
}


