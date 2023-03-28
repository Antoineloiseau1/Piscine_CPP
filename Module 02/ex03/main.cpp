#include <iostream>
#include "Point.hpp"

int main( void ) {

	Point a(3.58, 12.15);
	Point b(1.25, 42.42);
	Point c(-6.98, -4.52);
	Point point(2.36, 8.75);
	std::cout << bsp(a, b, c, point) << std::endl;
	return 0;
}