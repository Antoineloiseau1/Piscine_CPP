#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <iostream>
# include <algorithm>
# include <map>
# include <sstream>
# include <time.h>


time_t	str_to_time(std::string str);
bool	check_value(float value);
bool	check_date(std::string date);

template<typename T, typename U, typename V>
std::multimap<T, U>	convert_map_typekey(std::multimap<V, U> & src, T(*f)(V))
{
	std::multimap<T, U>						result;
	typename std::multimap<V, U>::iterator	it;

	for(it = src.begin(); it != src.end(); it++)
	{
		result.insert(std::pair<T, U>(f(it->first), it->second));
	}
	return result;
}


template<typename T, typename U>
std::multimap<T, U>	fill_map_from_file(std::ifstream & file, char separator)
{
	std::multimap<T, U>	data;
	std::string			line;
	T					key;
	U					value;

	// >>>>> Error Parsing Handling HERE <<<<
	std::getline(file,line); // ignore first line
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::getline(iss, key, separator);
		iss >> value;
		data.insert(std::pair<T, U>(key, value));
	}
	return data;
}

template<typename T>
void	displayMap(T & data)
{
	typename	T::iterator it;
	for (it = data.begin(); it != data.end(); it++)
	{
		std::cout << "[" << it->first << "] = " << it->second << std::endl;
	}
}

#endif
