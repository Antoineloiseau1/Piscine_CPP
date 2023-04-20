#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <climits>
#include <string>
#include <sstream>

ScalarConverter::ScalarConverter(void) { return; }
ScalarConverter::ScalarConverter(ScalarConverter const & src) { static_cast<void>(src); return; }
ScalarConverter::~ScalarConverter(void) { return; }
ScalarConverter&	ScalarConverter::operator=(ScalarConverter const & rhs) { static_cast<void>(rhs); return *this; }

bool	ScalarConverter::_isTypeInt(const std::string& literal) {
	int	i = 0;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	while(isdigit(literal[i]))
		i++;
	return (!literal[i]);
}

bool	ScalarConverter::_isTypeFloat(const std::string& literal) {
	if (literal == "nanf" || literal == "-inff" || literal == "+inff")
		return true;
	int	i = 0;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if(!isdigit(literal[i]))
		return false;
	while(isdigit(literal[i]))
		i++;
	if (literal[i] == '.')
		i++;
	if (!isdigit(literal[i]))
		return false;
	while(isdigit(literal[i]))
		i++;
	return (literal[i] == 'f');
}

char	ScalarConverter::_detectType(const std::string& literal) {
	if(_isTypeInt(literal))
		return INT;
	else if (_isTypeFloat(literal))
		return FLOAT;
	else if (_isTypeDouble(literal))
		return DOUBLE;
	if (literal.length() == 1 && isprint(literal[0]))
		return CHAR;
	return -1;
}

void	ScalarConverter::_convertInteger(const std::string& literal) {
	double integer;
	try
	{
		integer = stoi(literal);
		if (integer > CHAR_MAX || integer < 0 || !isprint(integer))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: \'" << static_cast<char>(integer) << "\'" << std::endl;
		std::cout << "int: " << static_cast<int>(integer) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(integer) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(integer) << std::endl;

}

void	ScalarConverter::_convertChar(const std::string& literal) {
	char character = literal[0];
	std::cout << "char: \'" << character << "\'" << std::endl;
	std::cout << "int: " << static_cast<int>(character) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(character) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(character) << std::endl;
}

void	ScalarConverter::_convertFloat(const std::string& literal) {
	double floating = stof(literal);
	if (floating > CHAR_MAX || !isprint(static_cast<int>(floating)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(floating) << std::endl;
	if (literal == "nanf" || literal == "-inff" || literal == "+inff")
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(floating) << std::endl;
	std::cout << "float: " << floating << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(floating) << std::endl;
}

void	ScalarConverter::_displayError(void) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void	ScalarConverter::convert(const std::string& literal) {
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
		case DOUBLE:
			_convertDouble(literal);
		default:
			_displayError();
			break;
	}
}