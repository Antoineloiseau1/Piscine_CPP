#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(void) : _type("Empty") {
	std::cout << "AMateria Default Constructor Called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type) {
	std::cout << "AMetaria Parametric Constructor Called with type \"";
	std::cout << this->getType() << "\"" << std::endl;
}

AMateria::AMateria(const AMateria &src) : _type(src.getType()) {
	std::cout << "AMateria Copy Constructor Called" << std::endl;
}

AMateria&	AMateria::operator=(const AMateria & rhs) {
	return *this;
}

AMateria::~AMateria(void) {
	std::cout << "AMateria Default Destructor Called" << std::endl;
}

std::string const AMateria::getType(void) const {
	return this->_type;
}

void	AMateria::use(ICharacter & target) {
	std::cout << "Empty Materias are useless..." << std::endl;
}
