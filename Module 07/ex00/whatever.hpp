#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void	swap(T & x, T & y)
{
	T tmp;

	tmp = x;
	x = y;
	y = tmp;
}

template<typename T>
T const &	min(T const & x, T const & y) {
	if (x < y)
		return x;
	else if (x > y)
		return y;
	else
		return y;
}

template<typename T>
T const &	max(T const & x, T const & y) {
	if (x > y)
		return x;
	else if (x < y)
		return y;
	else
		return y;
}

#endif