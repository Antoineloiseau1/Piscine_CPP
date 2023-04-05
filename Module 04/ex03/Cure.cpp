#include "Cure.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("cure") {
	std::cout << "Cure Default Constructor Called" << std::endl;
}

Cure::Cure(const Cure & src) : AMateria(src) {
	std::cout << "Cure Copy Constructor Called" << std::endl;
}

Cure &	Cure::operator=(const Cure & rhs) {
	std::cout << "Cure Assignment Operator Called" << std::endl;
	return *this;
}

Cure::~Cure(void) {
	std::cout << "Cure Default Destructor Called" << std::endl;
}

Cure*	Cure::clone(void) const {
	return new Cure;
}

void	Cure::use(ICharacter & target) {
	std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}