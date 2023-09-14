#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <climits>
#include <cerrno>


/* Canonical functions */
ScalarConverter::ScalarConverter(void) {}
ScalarConverter::ScalarConverter(ScalarConverter const & src) { static_cast<void>(src); }
ScalarConverter::~ScalarConverter(void) {}
ScalarConverter&	ScalarConverter::operator=(ScalarConverter const & rhs) { static_cast<void>(rhs); return *this; }


bool	ScalarConverter::_isTypeInt(const std::string& literal) 
{
	char		*endptr = NULL;
	long int	li = strtol(literal.c_str(), &endptr, 10);

	if(*endptr)
		return false;
	else if (li > INT_MAX || li < INT_MIN)
		return false;
	else
		return true;
}

bool	ScalarConverter::_isTypeFloat(const std::string& literal) 
{
	errno = 0;
	char	*endptr = NULL;
	double	f = strtof(literal.c_str(), &endptr);

	if(literal == "+inff" || literal == "-inff" || literal == "nanf")
		return true;
	if(f == 0 && endptr == literal) // Means its a string
		return false;
	else if (errno != 0) // Means out of bounds
		return false;
	else if(f == 0 && *endptr == 'f' && endptr == &literal[literal.length() -1]) // Means f == 0.0f and not f == 0.0ff
		return true;
	else if(f != 0 && *endptr == 'f' && endptr == &literal[literal.length() -1]) 	// Means f == some float value (42.3f)
		return true;
	else
		return false;
}

bool	ScalarConverter::_isTypeDouble(const std::string& literal) 
{
	errno = 0;
	char	*endptr = NULL;
	double	d = strtod(literal.c_str(), &endptr);

	if(d == 0 && endptr == literal) // Means its a string
		return false;
	else if (errno != 0) // Means out of bounds
		return false;
	else if(d == 0 && *endptr == 0) // Means f == 0.0
		return true;
	else if(d != 0 && *endptr == 0) 	// Means f == some float value (42.3)
		return true;
	else
		return false;
}

char	ScalarConverter::_detectType(const std::string& literal) 
{
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

void	ScalarConverter::_convertInteger(const std::string& literal) 
{
	char	*endptr = NULL;
	long int integer;

	integer = strtol(literal.c_str(), &endptr, 10);
	if (integer > UCHAR_MAX || integer < 0)
		std::cout << "char: impossible\n";
	else if(!isprint(integer))
		std::cout << "char: Not displayable\n";
	else
		std::cout << "char: \'" << static_cast<char>(integer) << "\'" << std::endl;
	std::cout << "int: " << integer << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(integer) << "f\n";
	std::cout << "double: " << static_cast<double>(integer) << std::endl;

}

void	ScalarConverter::_convertChar(const std::string& literal) 
{
	char character = literal[0];
	std::cout << "char: \'" << character << "\'" << std::endl;
	std::cout << "int: " << static_cast<int>(character) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(character) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(character) << std::endl;
}

void	ScalarConverter::_convertFloat(const std::string& literal) 
{
	errno = 0;
	char	*endptr = NULL;
	double	floating = strtof(literal.c_str(), &endptr);

	if (literal == "nanf" || literal == "-inff" || literal == "+inff")
		std::cout << "char: impossible" << std::endl;
	else if (floating > UCHAR_MAX || floating < 0)
		std::cout << "char: impossible" << std::endl;
	else if(!isprint(floating))
		std::cout << "char: Not displayable\n";
	else
		std::cout << "char: \'" << static_cast<char>(floating) << "\'\n";
	if (literal == "nanf" || literal == "-inff" || literal == "+inff")
		std::cout << "int: impossible" << std::endl;
	else if(floating > INT_MAX || floating < INT_MIN)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(floating) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << floating << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(floating) << std::endl;
}

void	ScalarConverter::_convertDouble(const std::string& literal) 
{
	errno = 0;
	char	*endptr = NULL;
	double	d = strtod(literal.c_str(), &endptr);

	if (literal == "nan" || literal == "-inf" || literal == "+inf")
		std::cout << "char: impossible" << std::endl;
	else if (d > UCHAR_MAX || d < 0)
		std::cout << "char: impossible" << std::endl;
	else if(!isprint(d))
		std::cout << "char: Not displayable\n";
	else
		std::cout << "char: \'" << static_cast<char>(d) << "\'\n";
	if (literal == "nan" || literal == "-inf" || literal == "+inf")
		std::cout << "int: impossible" << std::endl;
	else if(d > INT_MAX || d < INT_MIN)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	// if (d > __FLT_MAX__ || d < __FLT_MAX__)
	// 	std::cout << "float: impossible\n";
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
	if(errno)
		std::cout << "double: impossible\n";
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}

void	ScalarConverter::_displayError(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void	ScalarConverter::convert(const std::string& literal) 
{
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
			break;
		default:
			_displayError();
			break;
	}
}