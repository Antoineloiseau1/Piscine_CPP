#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

struct Data {
	int			i;
	float 		pi;
	std::string	s;
};

std::ostream&	operator<<(std::ostream& out, Data& data);

#endif