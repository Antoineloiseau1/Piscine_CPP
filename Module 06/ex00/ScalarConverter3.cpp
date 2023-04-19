#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>

void	ScalarConverter::convert(const std::string& literal) {
	if (literal.empty())
		return ;
	if(literal.length() == 1 && isprint(literal[0]))
		std::cout << "char: '" << literal[0] << "\'" << std::endl;
	else
		std::cout << "char: Not Displayable" << std::endl;
	int	i = strtol(literal.c_str(), NULL, 10);
	std::cout << i << std::endl;
	
}