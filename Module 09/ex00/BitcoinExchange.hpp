#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <iostream>
# include <map>
# include <sstream>

template<typename T, typename U>
std::map<T, U>	fill_map_from_file(std::ifstream & file, char separator)
{
	std::map<T, U>	data;
	std::string		line;
	T				key;
	U				value;

	std::getline(file,line); // ignore first line
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		iss >> key >> separator >> value;
		data.insert(std::pair<T, U>(key, value));
	}
	return data;
}

#endif
