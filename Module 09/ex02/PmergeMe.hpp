#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <string>
# include <sstream>
# include <cstdlib>
# include <iostream>

void						PmergeMe(char **argv);
std::vector<std::string>	extractArgs(char **argv);
bool						check_errors(std::vector<std::string> & args);

template<typename T>
T	extractNumbers(std::vector<std::string> & args)
{
	T									container;
	std::string							token;
	std::istringstream					iss;
	std::vector<std::string>::iterator	it;

	for(it = args.begin(); it != args.end(); it++)
	{
		iss.str(*it);
		while(iss >> token)
		{
			container.push_back(atoi(token.c_str()));
		}
		iss.clear();
	}
	return container;
}


#endif
