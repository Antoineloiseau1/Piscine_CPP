#include "Point.hpp"

/* Default Constructor */
Point::Point(void) : _x(0), _y(0) {
	return ;
}

/* Parametric Constructor */
Point::Point(const float x, const float y) : _x(x), _y(y) {
	return ;
}

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y){
	return ;
}

/* Copy Constructor */
Point::Point(Point const &src) : _x(src._x), _y(src._y){
	return ;
}

/* Assignment Operator Overload Constructor*/
Point&	Point::operator=(Point const &rhs) {
	std::cerr << "Cannot assign object because Point class contains const members" << std::endl;
	return *this;
}

/* Get the value of X */
Fixed const	Point::getX(void) const {
	return this->_x;
}

/* Get the value of Y */
Fixed const Point::getY(void) const {
	return this->_y;
}

/* Destructor */
Point::~Point(void) {
	return ;
}

std::ostream&	operator<<(std::ostream& out, Point const &instance) {
	out << "(" << instance.getX() << ", " << instance.getY() << ")";
	return out; 
}