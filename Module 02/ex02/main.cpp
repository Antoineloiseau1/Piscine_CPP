#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a(8);
	Fixed b(9);
	std::cout << std::endl << "a = "<< a << std::endl;
	std::cout << "b = "<< b << std::endl << std::endl;

	/* Arithmetics Operators Tests */
	std::cout << "/* Arithmetics Operators Tests */" << std::endl;
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "a / b = " << a / b << std::endl << std::endl;

	/* Increment and decrement Operators Tests */
	std::cout << "/* Increment and decrement Operators Tests */" << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "--a: " << --a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a =  " << a << std::endl;
	std::cout << "a--: " << a-- << std::endl;
	std::cout << "a = " << a << std::endl << std::endl;

	/* Compairison Operators tester */
	std::cout << "/* Compairison Operators tester */" << std::endl;
	std::cout << "(a < b): " << (a < b) << std::endl;
	std::cout << "(a > b): " << (a > b) << std::endl;
	std::cout << "(a <= b): " << (a <= b) << std::endl;
	std::cout << "(a >= b): " << (a >= b) << std::endl;
	std::cout << "(a == b): " << (a == b) << std::endl;
	std::cout << "(a != b): " << (a != b) << std::endl << std::endl;

	/* Min and Max tester */
	Fixed const c(19);
	Fixed const d(42);
	std::cout << "const c = " << c << std::endl;
	std::cout << "const d = " << d << std::endl << std::endl;

	std::cout << "/* Min and Max tester */" << std::endl;
	std::cout << "min(a, b) = " << Fixed::min( a, b ) << std::endl;
	std::cout << "max(a, b) = " << Fixed::max( a, b ) << std::endl;
	std::cout << "min(c, d) = " << Fixed::min( c, d ) << std::endl;
	std::cout << "max(c, d) = " << Fixed::max( c, d ) << std::endl;
	std::cout << "min(a, c) = " << Fixed::min( a, c ) << std::endl;
	std::cout << "max(b, d) = " << Fixed::max( b, d ) << std::endl << std::endl;

	return 0;
}