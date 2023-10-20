#include "BitcoinExchange.hpp"

time_t	str_to_time(std::string str)
{
	struct tm	tm;

	strptime(str.c_str(), "%Y-%m-%d", &tm);
	tm.tm_sec = 0;
	tm.tm_min = 0;
	tm.tm_hour = 0;
	
	return mktime(&tm);
}

bool check_value(float value)
{
	if (value <= 0)
	{
		std::cout << "Error: not a positive number\n";
		return false;
	}
	else if (value > 1000)
	{
		std::cout << "Error: too large a number" << std::endl;
		return false;
	}
	else
	{
		return true;
	}
}


bool check_date(std::string date)
{
	int					value[3];
	std::string			token;
	bool				error = false;
	int					i = 0;
	std::istringstream	iss(date);

	if(date.size() < 10 || date.size() > 11)
		error = true;
	if(date[4] != '-' || date[7] != '-')
		error = true;
	while(std::getline(iss, token, '-') && i < 3)
	{
		size_t found = token.find_first_not_of(" 0123456789");
		if(found != std::string::npos)
			error = true;
		std::istringstream(token) >> value[i];
		i++;
	}
	if (value[0] < 0)
		error = true;
	if (!(value[1] >= 1 && value[1] <= 12))
		error = true;
	if (!(value[2] >= 1 && value[2] <= 31))
		error = true;
	if(std::getline(iss, token, '-'))
		error = true;
	if(error)
		std::cout << "Error: bad input => " << date << std::endl;
	return(!error);
}
