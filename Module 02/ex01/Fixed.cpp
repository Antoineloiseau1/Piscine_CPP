#include "Fixed.hpp"
#include <cmath>

// Default constructor
Fixed::Fixed(void) : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

// Default int constructor
Fixed::Fixed(int const i) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = i << _nbFractionnalBits;
}

// Default float constructor
Fixed::Fixed(float const f) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = (roundf(f * (1 << _nbFractionnalBits)));
}

// Copy constructor
Fixed::Fixed(Fixed const& src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

// Destructor
Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

// Assignment constructor
Fixed&	Fixed::operator=(Fixed const& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
	return *this;
}

// Returns the raw bits of the fixed point value
int	Fixed::getRawBits(void) const {
	return this->_fixedPointValue;
}

// Set the raw bist of the fixed point value
void	Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}

// Converts the fixed point value to float
float	Fixed::toFloat(void) const {
	return ((float)this->_fixedPointValue / (float)(1 << _nbFractionnalBits));
}

// Converts the fixed point value to int
int	Fixed::toInt(void) const {
	return (this->_fixedPointValue >> _nbFractionnalBits);
}

// insertion operator overload 
std::ostream&	operator<<(std::ostream& out, Fixed const& instance) {
	out << instance.toFloat();
	return out;
}
