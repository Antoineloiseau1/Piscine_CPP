#include "WrongCat.hpp"
#include <iostream>


WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
	std::cout << this->_type << " Default Constructor Called" << std::endl; 
}

WrongCat::WrongCat(const WrongCat &src) {
	*this = src;
	std::cout << this->_type << "Copy Constructor Called" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat &rhs) {
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return *this;
}

WrongCat::~WrongCat(void)
{
	std::cout << this->_type << " Desctructor Called" << std::endl;
}

void	WrongCat::makeSound(void) const{
	std::cout << "* Meow *" << std::endl;
}