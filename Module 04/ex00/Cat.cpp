#include "Cat.hpp"
#include <iostream>


Cat::Cat(void) : Animal("Cat") {
	std::cout << this->_type << " Default Constructor Called" << std::endl; 
}

Cat::Cat(const Cat &src) {
	*this = src;
	std::cout << this->_type << " Copy Constructor Called" << std::endl;
}

Cat&	Cat::operator=(const Cat &rhs) {
	if (this != &rhs)
		this->_type = rhs.getType();
	return *this;
}

Cat::~Cat(void) {
	std::cout << this->_type << " Desctructor Called" << std::endl;
}

void	Cat::makeSound(void) const {
	std::cout << "* Meow *" << std::endl;
}