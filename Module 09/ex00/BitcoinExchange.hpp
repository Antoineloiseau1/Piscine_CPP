#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <iostream>
# include <map>
# include <sstream>
# include <time.h>


time_t	str_to_time(std::string str)
{
	struct tm	tm;
	strptime(str.c_str(), "%Y-%m-%d", &tm);
	return mktime(&tm);
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

#endif
