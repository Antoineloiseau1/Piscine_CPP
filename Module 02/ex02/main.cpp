#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a(8);
	Fixed const b(9);
	std::cout << std::endl << "a = "<< a << std::endl;
	std::cout << "b = "<< b << std::endl << std::endl;

	/* Arithmetics Operators Tests */
	std::cout << "*** Arithmetics Operators Test ***" << std::endl;
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "a / b = " << a / b << std::endl << std::endl;

	/* Increment and decrement Operators Tests */
	std::cout << "*** Increment and decrement Operators Tests ***" << std::endl;
	std::cout << "++a: " << a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;

	// Compairison Operators tester
	std::cout << "*** Compairison Operators tester ***" << std::endl;
	std::cout << "(a < b): " << (a < b) << std::endl;
	std::cout << "(a > b): " << (a > b) << std::endl;
	std::cout << "(a <= b): " << (a <= b) << std::endl;
	std::cout << "(a >= b): " << (a >= b) << std::endl;
	std::cout << "(a == b): " << (a == b) << std::endl;
	std::cout << "(a != b): " << (a != b) << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}