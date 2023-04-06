#include "Ice.hpp"
#include <iostream>
#include "AMateria.hpp"

Ice::Ice(void) : AMateria("ice") {}

Ice::Ice(const Ice & src) : AMateria(src) {}


Ice &	Ice::operator=(const Ice & rhs) {
	return *this;
}

Ice::~Ice(void) {}

Ice*	Ice::clone(void) const {
	return new Ice;
}

void	Ice::use(ICharacter & target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << "*" << std::endl;
}