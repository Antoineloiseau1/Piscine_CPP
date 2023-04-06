#include "AMateria.hpp"

AMateria::AMateria(void) : _type("Empty") {}

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(const AMateria &src) : _type(src.getType()) {}

AMateria&	AMateria::operator=(const AMateria & rhs) {
	return *this;
}

AMateria::~AMateria(void) {}

std::string const AMateria::getType(void) const {
	return this->_type;
}

void	AMateria::use(ICharacter & target) {}
