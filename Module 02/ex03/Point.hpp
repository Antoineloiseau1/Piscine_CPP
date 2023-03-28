#ifndef POINT_H
# define POINT_H

# include "Fixed.hpp"
# include <iostream>

class Point {

	private:

		const Fixed	_x;
		const Fixed	_y;

	public:

		Point(void);
		Point(const float x, const float y);
		Point(const Fixed x, const Fixed y);
		Point(Point const &src);
		Point&	operator=(Point const &rhs);
		~Point(void);

		const Fixed getX(void) const;
		const Fixed getY(void) const;

};

std::ostream&	operator<<(std::ostream& out, Point const &instance);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif