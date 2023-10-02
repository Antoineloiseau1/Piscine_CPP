#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		std::cerr << "usage: btc <file>\n";
		return 1;
	}

	std::ifstream	inputFile(argv[1]);

	if(!inputFile.is_open())
	{
		std::cerr << "Error: failed to open file\n";
		return 1;
	}

	std::map<std::string, float>	input;
	input = fill_map_from_file<std::string, float>(inputFile, '|');
	std::map<std::string, float>::iterator it;
	for(it = input.begin(); it != input.end(); it++)
	{
		std::cout << "[" << it->first << "] = " << it->second << std::endl;
	}
	inputFile.close();
	return 0;
}
