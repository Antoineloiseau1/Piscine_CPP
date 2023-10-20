#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <string>
# include <sstream>
# include <cstdlib>
# include <algorithm>
# include <iostream>
# include <ctime>

void						PmergeMe(char **argv);
std::vector<std::string>	extractArgs(char **argv);
bool						check_errors(std::vector<std::string> & args);

template<typename T>
void	print_container(T & container)
{
	typename T::iterator	it;
	
	for(it = container.begin(); it != container.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template<typename T>
bool	is_sorted(T & container)
{
	typename T::iterator	it;

	for (it = container.begin(); it != (container.end() - 1); it++)
	{
		if (*it > *(it + 1))
		{
			return false;
		}
	}
	return true;
}

template<typename T>
void	merge_sort(T & container, T & lhs, T & rhs)
{
	typename T::iterator it;
	typename T::iterator lit = lhs.begin();
	typename T::iterator rit = rhs.begin();
	for(it = container.begin(); it != container.end(); it++)
	{
		if(lit == lhs.end())
		{
			*it = *rit;
			rit++;
		}
		else if(rit == rhs.end())
		{
			*it = *lit;
			lit++;
		}
		else if(*lit <= *rit)
		{
			*it = *lit;
			lit++;
		}
		else
		{
			*it = *rit;
			rit++;
		}
	}
}


template<typename T>
float	ford_johnson_algorithm(T & container)
{
	typename T::iterator	mid = container.begin();
	clock_t					time;
	float					time_stamp;

	if(is_sorted(container))
	{
		return 0;
	}
	for(size_t i = 0; i < (container.size() / 2); i++)
	{
		mid++;
	}

	T	first_half(container.begin(), mid);
	T	second_half(mid, container.end());
	
	time = clock();
	std::stable_sort(first_half.begin(),  first_half.end());
	std::stable_sort(second_half.begin(), second_half.end());
	merge_sort(container, first_half, second_half);
	time = clock() - time;
	time_stamp = static_cast<float>(time) / CLOCKS_PER_SEC;
	time_stamp *= static_cast<float>(1e6);
	return (time_stamp);
}

template<typename T>
T	extractNumbers(std::vector<std::string> & args)
{
	T									container;
	std::string							token;
	std::istringstream					iss;
	std::vector<std::string>::iterator	it;
	int									number;

	for(it = args.begin(); it != args.end(); it++)
	{
		iss.str(*it);
		while(iss >> token)
		{
			number = atoi(token.c_str());
			if(number < 0)
			{
				std::cerr << "Error\n";
				exit(1);
			}
			container.push_back(atoi(token.c_str()));
		}
		iss.clear();
	}
	return container;
}


#endif
