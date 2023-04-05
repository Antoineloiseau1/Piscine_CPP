#include "Ice.hpp"
#include <iostream>

Ice::Ice(void) : AMateria("ice") {
	std::cout << "Ice Default Constructor Called" << std::endl;
}

Ice::Ice(const Ice & src) : AMateria(src) {
	std::cout << "Ice Copy Constructor Called" << std::endl;
}

Ice &	Ice::operator=(const Ice & rhs) {
	std::cout << "Ice Assignment Operator Called" << std::endl;
	return *this;
}

Ice::~Ice(void) {
	std::cout << "Ice Default Destructor Called" << std::endl;
}

Ice*	Ice::clone(void) const {
	return new Ice;
}

void	Ice::use(ICharacter & target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << "*" << std::endl;
}