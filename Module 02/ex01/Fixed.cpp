#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const i) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = i<< _nbFractionnalBits;
}

Fixed::Fixed(float const f) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = (roundf(f * (1 << _nbFractionnalBits)));
}

Fixed::Fixed(Fixed const& src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(Fixed const& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedPointValue = rhs.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const {
	return this->_fixedPointValue;
}

void	Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}

float	Fixed::toFloat(void) const {
	return ((float)this->_fixedPointValue / (float)(1 << _nbFractionnalBits));
}

int	Fixed::toInt(void) const {
	return (this->_fixedPointValue >> _nbFractionnalBits);
}
std::ostream&	operator<<(std::ostream& out, Fixed const& instance) {
	out << instance.toFloat();
	return out;
}

