#ifndef CLASSA_HPP
# define CLASSA_HPP

#include <iostream>

template<typename T = int>
class A {
	private:

		T	_data;

	public:

		A(T data) : _data(data) {}
		A(void) {}
		~A() {}

		T	getData(void) const {return _data;}

		A	operator++(T) {
			A temp(*this);
			++_data;
			return temp;
		}
};

template<typename T>
std::ostream &	operator<<(std::ostream &out, A<T> const & instance)
{
	out << instance.getData();
	return out;
}

#endif