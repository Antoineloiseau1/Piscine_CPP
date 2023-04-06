#include "Cure.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("cure") {}

Cure::Cure(const Cure & src) : AMateria(src) {}

Cure &	Cure::operator=(const Cure & rhs) {
	return *this;
}

Cure::~Cure(void) {}

Cure*	Cure::clone(void) const {
	return new Cure;
}

void	Cure::use(ICharacter & target) {
	std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}