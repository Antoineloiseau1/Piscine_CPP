#include "BitcoinExchange.hpp"
#include <iomanip>


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

	std::multimap<std::string, float>	tmp = fill_map_from_file<std::string, float>(dataBase, ',');
	std::multimap<time_t, float>		data = convert_map_typekey(tmp, &str_to_time);
	dataBase.close();


	std::multimap<std::string,  float>	input = fill_map_from_file<std::string, float>(inputFile, '|');
	inputFile.close();

	std::multimap<std::string, float>::iterator	it;	
	for (it = input.begin(); it != input.end(); it++)
	{
		if(check_date(it->first))
		{	
			std::multimap<time_t, float>::iterator needle = data.find(str_to_time(it->first));
			if(needle == data.end())
			{
				needle = data.lower_bound(str_to_time(it->first));
				if(needle != data.begin())
					needle--;
			}
			if (check_value(it->second))
			{
				std::cout << it->first << " => " << it->second << " = ";
				std::cout << it->second * needle->second << std::endl;
			}
		}
	}
	return 0;
}
