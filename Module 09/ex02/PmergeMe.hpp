#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <string>
# include <sstream>
# include <cstdlib>
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
void	insertion_sort(T & container)
{
	typename T::iterator		it;
	unsigned int				tmp;

	for(it = container.begin(); it != (container.end() - 1); it++)
	{
		if(*it > *(it + 1))
		{
			tmp = *it;
			*it = *(it + 1);
			*(it + 1) = tmp;
		}
	}
	if(!is_sorted(container))
	{
		insertion_sort(container);
	}
}

template<typename T>
double	ford_johnson_algorithm(T & container)
{
	typename T::iterator	mid = container.begin();
	clock_t	time;

	for(size_t i = 0; i < (container.size() / 2); i++)
	{
		mid++;
	}

	T	first_half(container.begin(), mid);
	T	second_half(mid, container.end());
	
	time = clock();
	insertion_sort(first_half);
	insertion_sort(second_half);
	merge_sort(container, first_half, second_half);
	time = clock() - time;
	return ((static_cast<float>(time) / CLOCKS_PER_SEC) * 1e6);
}

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
