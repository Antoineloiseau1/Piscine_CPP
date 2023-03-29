#include "Point.hpp"

int main( void ) {

	{
		/* Point Inside */
		std::cout << "/* Point Inside */" << std::endl;
		Point a(1, 2);
		Point b(3, 4);
		Point c(5, 2);
		Point point(3, 3);
		std::cout << "a" << a << "\nb" << b << "\nc" << c << "\npoint" << point << std::endl;
		std::cout << ((bsp(a, b, c, point) == true) ? "true" : "false") << std::endl << std::endl;
	}
	{
		/* Point Outside */
		std::cout << "/* Point Outside */" << std::endl;
		Point a(1, 2);
		Point b(-1, -1);
		Point c(5, 2);
		Point point(3, 3);
		std::cout << "a" << a << "\nb" << b << "\nc" << c << "\npoint" << point << std::endl;
		std::cout << ((bsp(a, b, c, point) == true) ? "true" : "false") << std::endl << std::endl; 
	}
	{
		/* Point On side */
		std::cout << "/* Point On side */" << std::endl;
		Point a(1, 2);
		Point b(3, 4);
		Point c(5, 2);
		Point point(3, 2);
		std::cout << "a" << a << "\nb" << b << "\nc" << c << "\npoint" << point << std::endl;
		std::cout << ((bsp(a, b, c, point) == true) ? "true" : "false") << std::endl << std::endl; 
	}
	{
		/* Point Equals b */
		std::cout << "/* Point Equals b */" << std::endl;
		Point a(1, 2);
		Point b(3, 4);
		Point c(5, 2);
		Point point(3, 4);
		std::cout << "a" << a << "\nb" << b << "\nc" << c << "\npoint" << point << std::endl;
		std::cout << ((bsp(a, b, c, point) == true) ? "true" : "false") << std::endl << std::endl; 
	}
	{
		/* float values*/
		std::cout << "/* float values */" << std::endl;
		Point a(1.4568, 2.78912);
		Point b(3.7568, 4.12678);
		Point c(5.78531, 2.1264);
		Point point(3.1248, 2.78621);
		std::cout << "a" << a << "\nb" << b << "\nc" << c << "\npoint" << point << std::endl;
		std::cout << ((bsp(a, b, c, point) == true) ? "true" : "false") << std::endl; 
	}
	

	return 0;
}