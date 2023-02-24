#include <iostream>
#include <fstream>
#include <string>
#include "utils.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << argv[0] << ": usage: <file> <needle> <newValue>" << std::endl;
		return (1);
	}

	std::ifstream	file;
	file.open (argv[1], std::ifstream::in);
	if (!file.is_open())
	{
		std::cerr << "Error: " << argv[0] << ": ";
		perror(argv[1]);
		return (1);
	}

	std::string		outfile(getOutfile(argv[1]));
	std::string		buffer;
	std::string		s1(argv[2]);
	std::string		s2(argv[3]);
	std::ofstream	replacedFile(outfile);
	int 			start;

	while (getline(file, buffer))
	{
		if (!s1.empty())
		{
			start = 0;
			while(buffer.find(s1, start) != buffer.npos)
			{
				start = buffer.find(s1);
				buffer.erase(start, s1.length());
				buffer.insert(start, s2);
			}
		}
		if (!file.eof())
			buffer += "\n";
		replacedFile << buffer;
	}
	file.close();
	replacedFile.close();
	return (0);
}
