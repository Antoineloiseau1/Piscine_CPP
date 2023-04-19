#include "Data.hpp"

std::ostream&	operator<<(std::ostream& out, Data& data) {
	out << "{" << data.i << ", " << data.pi << ", \"" << data.s <<"\"}";
	return out;
}