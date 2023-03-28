#include "Fixed.hpp"
#include <cmath>

// Default constructor
Fixed::Fixed(void) : _fixedPointValue(0) {
	return ;
}

// Default int constructor
Fixed::Fixed(int const i) {
	this->_fixedPointValue = i << _nbFractionnalBits;
}

// Default float constructor
Fixed::Fixed(float const f) {
	this->_fixedPointValue = (roundf(f * (1 << _nbFractionnalBits)));
}

// Copy constructor
Fixed::Fixed(Fixed const& src) {
	*this = src;
}

// Destructor
Fixed::~Fixed(void) {
	return ;
}

// Assignment constructor
Fixed&	Fixed::operator=(Fixed const& rhs) {
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

Fixed	Fixed::operator+(Fixed const& rhs) const {
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(Fixed const& rhs) const {
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(Fixed const& rhs) const {
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(Fixed const& rhs) const {
	return Fixed(this->toFloat() / rhs.toFloat());
}

// More than operator overload
bool	Fixed::operator>(Fixed const& rhs) const {
	return this->toFloat() > rhs.toFloat();
}

// less than operator overload
bool	Fixed::operator<(Fixed const& rhs) const {
	return this->toFloat() < rhs.toFloat();
}

// less or equal than operator overload
bool	Fixed::operator<=(Fixed const& rhs) const {
	return this->toFloat() <= rhs.toFloat();
}

// more or equal than operator overload
bool	Fixed::operator>=(Fixed const& rhs) const {
	return this->toFloat() >= rhs.toFloat();
}

// Strictly equal operator overload
bool	Fixed::operator==(Fixed const& rhs) const {
	return this->toFloat() == rhs.toFloat();
}

// Different than operator overload
bool	Fixed::operator!=(Fixed const& rhs) const {
	return this->toFloat() != rhs.toFloat();
}

Fixed&	Fixed::operator++() {
	this->_fixedPointValue++;
	return *this;
}

Fixed&	Fixed::operator--() {
	this->_fixedPointValue--;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed temp = *this;
	this->_fixedPointValue++;
	return temp;
}

Fixed	Fixed::operator--(int) {
	Fixed temp = *this;
	this->_fixedPointValue--;
	return temp;
}

Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	return ((a > b) ? a : b);
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b) {
	return (a < b) ? a : b;
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b) {
	return (a > b) ? a : b;
}

// insertion operator overload 
std::ostream&	operator<<(std::ostream& out, Fixed const& instance) {
	out << instance.toFloat();
	return out;
}