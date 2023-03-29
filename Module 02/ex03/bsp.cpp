#include "Point.hpp"

Fixed	calculateArea(Point const a, Point const b, Point const p) {
	/* Calculates the area of a parallelogram given by points a, b and p*/
	const Fixed aX = a.getX(), aY = a.getY();
	const Fixed bX = b.getX(), bY = b.getY();
	const Fixed pX = p.getX(), pY = p.getY();
	/* this calculates the determinent of the matrice of vectors (p, a) and (p, b) */
	return ((aX - pX) * (bY - pY)) - ((aY - pY) * (bX - pX));
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	/* Chech if point is on the right or left side ofthe line of each sommets*/
	Fixed area1 = (calculateArea(a, b, point));
	Fixed area2 = (calculateArea(b, c, point));
	Fixed area3 = (calculateArea(c, a, point));
	/* if a b and c are clockwise*/
	if (area1 > 0 && area2 > 0 && area3 > 0)
		return true;
	/* if a b and c are counter clockwise*/
	else if (area1 < 0 && area2 < 0 && area3 < 0)
		return true;
	else
		return false;

}