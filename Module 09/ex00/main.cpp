#include "BitcoinExchange.hpp"

template<typename T>
void	displayMap(T & data)
{
	typename	T::iterator it;
	for (it = data.begin(); it != data.end(); it++)
	{
		std::cout << "[" << it->first << "] = " << it->second << std::endl;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "usage: btc <file>\n";
		return 1;
	}

	std::ifstream	inputFile(argv[1]);
	std::ifstream	dataBase("data.csv");

	if (!inputFile.is_open() || ! dataBase.is_open())
	{
		std::cerr << "Error: failed to open file\n";
		return 1;
	}

	std::multimap<std::string,  float>	data = fill_map_from_file<std::string, float>(dataBase, ',');
	dataBase.close();
	std::multimap<std::string,  float>	input = fill_map_from_file<std::string, float>(dataBase, '|');
	inputFile.close();
	displayMap(input);
	(void)data;
	std::multimap<std::string, float>::iterator	it;
	for (it = input.begin(); it != input.end(); it++)
	{
		std::cout << it->second << std::endl;
		if (!(it->second >= 0 && it->second <= 1000))
		{
			std::cout << "Error: not a positive number\n";
			it++;
		}
	}
	return 0;
}
