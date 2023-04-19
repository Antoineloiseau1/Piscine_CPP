#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <climits>
#include <sstream>

ScalarConverter::ScalarConverter(void) { return; }
ScalarConverter::ScalarConverter(ScalarConverter const & src) { static_cast<void>(src); return; }
ScalarConverter::~ScalarConverter(void) { return; }
ScalarConverter&	ScalarConverter::operator=(ScalarConverter const & rhs) { static_cast<void>(rhs); return *this; }

bool	isTypeInt(std::string literal) {
	int	i = 0;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	while(isdigit(literal[i]))
		i++;
	return (!literal[i]);
}

bool	isTypeFloat(std::string literal) {
	int	i = 0;
	if(literal[i] == '+' || literal[i] == '-')
		i++;
	if(!isdigit(literal[i]))
		return false;
	while(isdigit(literal[i]))
		i++;
	if (literal[i] != '.')
		return false;
	else
		i++;
	if (!isdigit(literal[i]))
		return false;
	while(isdigit(literal[i]))
		i++;
	return (literal[i] == 'f');
	
}

char	ScalarConverter::_detectType(std::string literal) {
	if(isTypeInt(literal))
		return INT;
	// if (atoi(literal.c_str()) != 0 || literal == "0")
	// 	return INT;
	//char	*endPtr = NULL;
	// strtof(literal.c_str(), &endPtr);
	if (isTypeFloat(literal))
		return FLOAT;
	// strtod(literal.c_str(), &endPtr);
	// if (*endPtr == 0 || literal == "nan")
	// 	return DOUBLE;
	// strtol(literal.c_str(), &endPtr, 10);
	// if (*endPtr == 0)
	// 	return INT;
	if (literal.length() == 1 && isprint(literal[0]))
		return CHAR;
	return -1;
}

void	ScalarConverter::_convertInteger(std::string literal) {
	std::stringstream ss(literal);
	int	integer;
	ss >> integer;
	if (integer > CHAR_MAX || integer < 0 || !isprint(integer))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: \'" << static_cast<char>(integer) << "\'" << std::endl;
	std::cout << "int: " << integer << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(integer) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(integer) << std::endl;
}

void	ScalarConverter::_convertChar(std::string literal) {
	char character = literal[0];
	std::cout << "char: \'" << character << "\'" << std::endl;
	std::cout << "int: " << static_cast<int>(character) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(character) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(character) << std::endl;
}

void	ScalarConverter::_convertFloat(std::string literal) {
	float floating = strtof(literal.c_str(), NULL);
	if (floating > CHAR_MAX || !isprint(static_cast<int>(floating)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(floating) << std::endl;
	std::cout << "int: " << static_cast<int>(floating) << std::endl;
	std::cout << "float: " << floating << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(floating) << std::endl;
}

void	ScalarConverter::convert(std::string literal) {
	std::cout << "literal: " << literal << std::endl;
	char	type = _detectType(literal);
	switch (type) {
		case CHAR:
			_convertChar(literal);
			break;
		case INT:
			_convertInteger(literal);
			break;
		case FLOAT:
			_convertFloat(literal);
			break;
		default:
			break;
	}
}