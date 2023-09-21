#ifndef CLASSA_HPP
# define CLASSA_HPP

#include <iostream>

class A {
	private:

		int	_n;

	public:

		A(int n) : _n(n) {}

		int	get(void) const {return _n;}

		A	operator++(int) {
			A temp(*this);
			++_n;
			return temp;
		}
};

std::ostream &	operator<<(std::ostream &out, A const & instance)
{
	out << instance.get();
	return out;
}

#endif